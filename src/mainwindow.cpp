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

	for(auto remote : remotes["files"].toArray()) {
		auto obj = remote.toObject();
		if(obj.value("id") == "core") _coreObj = obj;
		else if(obj.value("key") == "client") _clientObj = obj;
	}

	const auto coreVersion = QVersionNumber::fromString(_coreObj.value("version").toString());
	const auto clientVersion = QVersionNumber::fromString(_clientObj.value("version").toString());

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
	for(auto discord : _discords) {
		discord->widget()->hideButtons();
		if(discord->action() == Discord::A_REPAIR_INSTALL) {
			_ui.productsToInstall->layout()->addWidget(discord->widget());
		} else if(discord->action() == Discord::A_UNINSTALL) {
			_ui.productsToRemove->layout()->addWidget(discord->widget());
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
