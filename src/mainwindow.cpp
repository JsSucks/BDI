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

Asset MainWindow::asset(const QString &id) const {
	return _assets.find(id).value();
}

void MainWindow::initOptionsPage() const {
	_ui.commonData->setChecked(_userConfig.useCommonDataPath());
	_ui.commonInstall->setChecked(_userConfig.useCommonInstallPath());
	_ui.autoInject->setChecked(_userConfig.autoInject());

	_ui.installPathChooser->initialize("Install Path:",
		"* Location for BetterDiscord core files.",
		_userConfig.installPath(),
		_userConfig.useCommonInstallPath() ? "/BetterDiscord" : "/BetterDiscord/:channel");

	_ui.dataPathChooser->initialize("Data Path:",
		"* Location for BetterDiscord data such as plugins, themes and caches.",
		_userConfig.dataPath(),
		_userConfig.useCommonDataPath() ? "/BetterDiscord" : "/BetterDiscord/:channel");
}

void MainWindow::splashFinished(QVector<Discord*> &discords, const QJsonObject &remotes) {
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
		} else {
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

	QVector<Discord*> install;
	QVector<Discord*> remove;

	for(auto discord : _discords) {
		discord->widget()->hideButtons();
		discord->widget()->setStatus("");
		if(discord->action() == Discord::A_REPAIR_INSTALL) {
			_ui.productsToInstall->layout()->addWidget(discord->widget());
			install.append(discord);
		} else if(discord->action() == Discord::A_UNINSTALL) {
			_ui.productsToRemove->layout()->addWidget(discord->widget());
			remove.append(discord);
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

	for(auto discord : remove) {
		discord->widget()->setStatus("Removing...");
		if(discord->remove()) {
			discord->widget()->setStatus("Done");
		} else {
			discord->widget()->setStatus("Error!");
		}
	}

	if(install.length() <= 0) return;
	install.first()->widget()->setStatus("Pulling packages...");
	this->install(install);
}

void MainWindow::install(QVector<Discord *> &discords) const {
	connect(asset("stub").remote, &RemoteFile::finished, [=]() {
		processRemotes(discords);
	});

	connect(asset("core").remote, &RemoteFile::finished, [=]() {
		processRemotes(discords);
	});

	connect(asset("client").remote, &RemoteFile::finished, [=]() {
		processRemotes(discords);
	});

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

	asset("stub").remote->download();
}

void MainWindow::processRemotes(QVector<Discord *> discords) const {
	if(!asset("stub").remote->downloaded() || !asset("core").remote->downloaded() || !asset("client").remote->downloaded()) return;
	Logger::Debug("Finished pulling packages");

	discords.first()->widget()->setStatus("Installing...");
}

void MainWindow::inject(QVector<Discord *> discords) const {

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
	checked ? _ui.installPathChooser->setSuffix("/BetterDiscord") : _ui.installPathChooser->setSuffix("/BetterDiscord/:channel");
}

void MainWindow::dataCheckboxCheckedChanged(const bool checked) const {
	checked ? _ui.dataPathChooser->setSuffix("/BetterDiscord") : _ui.dataPathChooser->setSuffix("/BetterDiscord/:channel");
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
