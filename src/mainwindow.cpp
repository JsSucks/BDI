/**
 * BetterDiscord Installer
 * Copyright (c) 2018-present Jiiks/JsSucks - https://github.com/Jiiks / https://github.com/JsSucks
 * All rights reserved.
 * https://betterdiscord.net
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
*/

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
	setWindowFlags(Qt::FramelessWindowHint);
	_remotesLoaded = false;
	_ui.setupUi(this);
	_ui.mainStack->setCurrentWidget(_ui.pageInitial);
	_ui.btnExit->hide();
	_ui.lblDone->hide();

	_toInstall = new QVector<Discord*>();
	_toRemove = new QVector<Discord*>();

#ifdef TEST_MODE
	_ui.centralWidget->setStyleSheet("#centralWidget { background: red; }");
#else
	_ui.centralWidget->setStyleSheet("#centralWidget { background: rgb(62, 204, 156); }");
#endif

	_about = new About();
	_about->loadLicenseText();

	auto splash = new Splash();
	connect(splash, &Splash::finished, this, &MainWindow::splashFinished);
	splash->show();
}

void MainWindow::initOptionsPage() const {
	_ui.commonData->setChecked(_userConfig.useCommonDataPath());
	_ui.commonInstall->setChecked(_userConfig.useCommonInstallPath());
	_ui.autoInject->setChecked(_userConfig.autoInject());
	_ui.installPathChooser->initialize("Install Path:",
		"* Location for BetterDiscord core files.",
		_userConfig.installPath(),
		_userConfig.useCommonInstallPath() ? "" : "/:channel");

	_ui.dataPathChooser->initialize("Data Path:",
		"* Location for BetterDiscord data such as plugins, themes and caches.",
		_userConfig.dataPath(),
		_userConfig.useCommonDataPath() ? "" : "/:channel");
}

void MainWindow::splashFinished(QVector<Discord*> &discords, const QJsonObject &remotes) {
	Logger::Debug(QJsonDocument(remotes).toJson());
	initOptionsPage();
	show();
	raise();
	setFocus();

	_discords = discords;
	_remotes = remotes;

	for(auto remote : remotes["files"].toArray()) {
		auto obj = remote.toObject();
		Asset asset(obj);
		if(asset.id() == "stub") {
			asset.remote = new RemoteFile(asset.raw());
		}
		else {
			asset.remote = new RemoteFile(asset.fileName(), "tmp", asset.remoteLocation(), false);
			asset.remote->loadLocal();
			asset.zip = new Zip(asset.remote->localFilePath(), "tmp");
		}

		_assets.insert(obj["id"].toString(), asset);
	}

	for(auto discord : discords) {
		switch(discord->state()) {
		case Discord::NOT_INSTALLED:
			_ui.availableProducts->layout()->addWidget(discord->widget());
			break;
		case Discord::INSTALLED:
		case Discord::BROKEN:
			_ui.installedProducts->layout()->addWidget(discord->widget());
			break;
		case Discord::INSTALLING:
		case Discord::UNAVAILABLE:
		default: break;
		}
	}
}

void MainWindow::btnContinueClicked() const {
	// TODO Better spinner
	auto mov = new QMovie(":/images/horSpinner");
	_ui.spinner->setMovie(mov);
	mov->start();

	for(auto discord : _discords) {
		discord->widget()->hideButtons();
		discord->widget()->setStatus("");
		if(discord->action() == Discord::A_REPAIR_INSTALL) {
			_ui.productsToInstall->layout()->addWidget(discord->widget());
			_toInstall->append(discord);
		} else if(discord->action() == Discord::A_UNINSTALL) {
			_ui.productsToRemove->layout()->addWidget(discord->widget());
			_toRemove->append(discord);
		}
	}

	if(_ui.productsToRemove->children().length() <= 1) {
		_ui.productsToRemoveHeader->hide();
		_ui.productsToRemove->hide();
	}

	if(_ui.productsToInstall->children().length() <= 1) {
		_ui.productsToInstallHeader->hide();
		_ui.productsToInstall->hide();
	}

	_ui.mainStack->setCurrentWidget(_ui.pageInstall);

	for(auto discord : *_toRemove) {
		discord->widget()->setStatus("Removing...");
		if(discord->remove()) {
			discord->widget()->setStatus("Done");
		} else {
			discord->widget()->setStatus("Error!");
		}
	}

	if(_toInstall->length() <= 0) {
		_ui.btnExit->show();
		_ui.spinner->hide();
		_ui.lblDone->show();
		return;
	}

	_toInstall->first()->widget()->setStatus("Pulling packages...");

	QTimer::singleShot(2000, this, &MainWindow::install);
}

void MainWindow::install() const {
	connect(asset("stub").remote, &RemoteFile::finished, this, &MainWindow::processRemotes);
	connect(asset("core").remote, &RemoteFile::finished, this, &MainWindow::processRemotes);
	connect(asset("client").remote, &RemoteFile::finished, this, &MainWindow::processRemotes);
	connect(asset("editor").remote, &RemoteFile::finished, this, &MainWindow::processRemotes);

	// Check if files exist
	if(asset("core").localFileExists() && asset("core").compareHash()) {
		Logger::Debug("Latest core archive exists");
		asset("core").remote->setDownloaded(true);
	} else {
		Logger::Debug("Latest core archive does not exist");
		asset("core").remote->download();
	}

	if(asset("client").localFileExists() && asset("client").compareHash()) {
		Logger::Debug("Latest client archive exists");
		asset("client").remote->setDownloaded(true);
	} else {
		Logger::Debug("Latest client archive does not exist");
		asset("client").remote->download();
	}

	if(asset("editor").localFileExists() && asset("editor").compareHash()) {
		Logger::Debug("Latest editor archive exists");
		asset("editor").remote->setDownloaded(true);
	} else {
		Logger::Debug("Latest editor archive does not exist");
		asset("editor").remote->download();
	}

	asset("stub").remote->download();
}

void MainWindow::processRemotes() const {
	if(!asset("stub").remote->downloaded() || 
		!asset("core").remote->downloaded() || 
		!asset("client").remote->downloaded() ||
		!asset("editor").remote->downloaded()) return;
	Logger::Debug("Finished pulling packages");

	_toInstall->first()->widget()->setStatus("Installing...");
	inject();
}

void MainWindow::inject() const {
	auto coreAsset = asset("core");
	if(_userConfig.useCommonInstallPath() && !coreAsset.zip->isExtracted()) {
		connect(coreAsset.zip, &Zip::extracted, this, &MainWindow::inject);
		coreAsset.zip->extract(_userConfig.installPath());
		return;
	}

	auto clientAsset = asset("client");
	if(_userConfig.useCommonInstallPath() && !clientAsset.zip->isExtracted()) {
		connect(clientAsset.zip, &Zip::extracted, this, &MainWindow::inject);
		clientAsset.zip->extract(_userConfig.installPath());
		return;
	}

	auto editorAsset = asset("editor");
	if(_userConfig.useCommonInstallPath() && !editorAsset.zip->isExtracted()) {
		connect(editorAsset.zip, &Zip::extracted, this, &MainWindow::inject);
		editorAsset.zip->extract(_userConfig.installPath());
		return;
	}

	for(auto discord : *_toInstall) {
		discord->widget()->setStatus("Installing...");
		if(discord->inject(asset("stub").remote->readAll(), _userConfig.toObj(), "", "")) {
			discord->widget()->setStatus("Done");
		} else {
			discord->widget()->setStatus("Error!");
		}
	}

	_ui.lblDone->show();
	_ui.btnExit->show();
	_ui.spinner->hide();
}

Asset MainWindow::asset(const QString &id) const {
	return _assets.find(id).value();
}

void MainWindow::btnOptionsClicked() const {
	_ui.mainStack->setCurrentWidget(_ui.pageOptions);
}

void MainWindow::btnApplyOptionsClicked() {
	_userConfig.useCommonInstallPath(_ui.commonInstall->isChecked());
	_userConfig.useCommonDataPath(_ui.commonData->isChecked());
	_userConfig.autoInject(_ui.autoInject->isChecked());
	_userConfig.setInstallPath(_ui.installPathChooser->selectedPath());
	_userConfig.setDataPath(_ui.dataPathChooser->selectedPath());
	_userConfig.write();
	_ui.mainStack->setCurrentWidget(_ui.pageInitial);
}

void MainWindow::btnCancelOptionsClicked() const {
	_ui.commonInstall->setChecked(_userConfig.useCommonInstallPath());
	_ui.commonData->setChecked(_userConfig.useCommonDataPath());
	_ui.autoInject->setChecked(_userConfig.autoInject());
	_ui.installPathChooser->setPath(_userConfig.installPath());
	_ui.dataPathChooser->setPath(_userConfig.dataPath());
	_ui.mainStack->setCurrentWidget(_ui.pageInitial);
}

void MainWindow::installCheckboxCheckedChanged(const bool checked) const {
	checked ? _ui.installPathChooser->setSuffix("") : _ui.installPathChooser->setSuffix("/:channel");
}

void MainWindow::dataCheckboxCheckedChanged(const bool checked) const {
	checked ? _ui.dataPathChooser->setSuffix("") : _ui.dataPathChooser->setSuffix("/:channel");
}

void MainWindow::captionCloseClicked() const {
	QCoreApplication::quit();
}

void MainWindow::captionHelpClicked() const {
	_about->show();
	const auto cx = x() + width() / 2;
	const auto cy = y() + height() / 2;
	_about->move(cx - _about->width() / 2, cy - _about->height() / 2);
}

void MainWindow::captionMinClicked() {
	setWindowState(Qt::WindowMinimized);
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
	if(!_drag) return;
	move(event->globalX() - _mousePressX, event->globalY() - _mousePressY);
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
	setFocus();
	_drag = true;
	_mousePressX = event->x();
	_mousePressY = event->y();
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event) {
	_drag = false;
}

void MainWindow::changeEvent(QEvent *event) {
	if(event->type() != QEvent::ActivationChange) return;
	_ui.mainStack->setEnabled(isActiveWindow());
	if(!isActiveWindow()) {
		_ui.centralWidget->setStyleSheet("#centralWidget { background: gray; }");
		_ui.icon->setEnabled(false);
		_ui.prodcutsSplit->setStyleSheet("border-bottom: 1px solid gray; color: #aeaeae; margin-left: 75px;");
		_ui.label_2->setText(R"(<html><head/><body><p><span style="color:gray;">Better</span><span style="color:#ffffff;">Discord</span></p></body></html>)");
	}
	else {
		_about->hide();
#ifdef TEST_MODE
		_ui.centralWidget->setStyleSheet("#centralWidget { background: red; }");
#else
		_ui.centralWidget->setStyleSheet("#centralWidget { background: rgb(62, 204, 156); }");
#endif
		_ui.icon->setEnabled(true);
		_ui.prodcutsSplit->setStyleSheet("border-bottom: 1px solid rgb(62, 204, 156); color: rgb(62, 204, 156); margin-left: 75px;");
		_ui.label_2->setText(R"(<html><head/><body><p><span style="color:#3ecc9c;">Better</span><span style="color:#ffffff;">Discord</span></p></body></html>)");
	}
}
