/* BetterDiscord Installer
 *
 * Copyright (c) 2019-present Jiiks - https://github.com/Jiiks
 * All rights reserved.
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
	setWindowFlags(Qt::FramelessWindowHint);
	_ui.setupUi(this);

#ifdef TEST_MODE
	_ui.centralWidget->setStyleSheet("#centralWidget { background: red; }");
#else
	_ui.centralWidget->setStyleSheet("#centralWidget { background: rgb(62, 204, 156); }");
#endif

	auto splash = new Splash();
	connect(splash, &Splash::finished, this, &MainWindow::splashFinished);
	splash->show();
}

void MainWindow::splashFinished(QVector<Discord*> &discords, const QJsonObject &remotes) {
	show();
	raise();
	setFocus();

	QJsonObject _coreObj, _clientObj;

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
		_ui.prodcutsSplit->setStyleSheet("border-bottom: 1px solid gray; color: #aeaeae; margin-left: 65px;");
		_ui.label_2->setText(R"(<html><head/><body><p><span style="color:gray;">Better</span><span style="color:#ffffff;">Discord</span></p></body></html>)");
	} else {
#ifdef TEST_MODE
		_ui.centralWidget->setStyleSheet("#centralWidget { background: red; }");
#else
		_ui.centralWidget->setStyleSheet("#centralWidget { background: rgb(62, 204, 156); }");
#endif
		_ui.icon->setEnabled(true);
		_ui.prodcutsSplit->setStyleSheet("border-bottom: 1px solid rgb(62, 204, 156); color: rgb(62, 204, 156); margin-left: 65px;");
		_ui.label_2->setText(R"(<html><head/><body><p><span style="color:#3ecc9c;">Better</span><span style="color:#ffffff;">Discord</span></p></body></html>)");
	}
}
