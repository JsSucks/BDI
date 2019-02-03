/* BetterDiscord Installer
 *
 * Copyright (c) 2019-present Jiiks - https://github.com/Jiiks
 * All rights reserved.
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "splash.h"
#include <QTimer>

Splash::Splash(QWidget *parent) : QWidget(parent) {
	setWindowFlags(Qt::FramelessWindowHint);
	_ui.setupUi(this);
	_ui.mainStack->setCurrentIndex(0);
}

void Splash::attemptClose() {
	QApplication::quit();
}

void Splash::systemChecks() {
	Logger::Debug("System checks started");

	auto stable = new Discord("stable");
	stable->locate();
	stable->debug();
	_ui.pbarSystemChecks->setValue(33);

	auto ptb = new Discord("ptb");
	ptb->locate();
	ptb->debug();
	_ui.pbarSystemChecks->setValue(66);

	auto canary = new Discord("canary");
	canary->locate();
	canary->debug();
	_ui.pbarSystemChecks->setValue(100);

	_discords = QVector<Discord*> {
		stable,
		ptb,
		canary
	};

	Logger::Debug("System checks finished");
}

void Splash::remotes(const QJsonObject &remotes) {
	_ui.pbarRemotes->setValue(100);
	emit finished(_discords, remotes);
}


void Splash::mouseMoveEvent(QMouseEvent *event) {
	if (!_drag) return;
	move(event->globalX() - _mousePressX, event->globalY() - _mousePressY);
}

void Splash::mousePressEvent(QMouseEvent *event) {
	_drag = true;
	_mousePressX = event->x();
	_mousePressY = event->y();
}

void Splash::mouseReleaseEvent(QMouseEvent *event) {
	_drag = false;
}

void Splash::btnContinueClicked() {
	_ui.mainStack->setCurrentIndex(1);
	systemChecks();
	_ui.pbarRemotes->setValue(50);
#ifdef TEST_MODE
	QFile rf("releaseinfo.json");
	rf.open(QIODevice::ReadOnly | QIODevice::Text);
	remotes(QJsonDocument::fromJson(rf.readAll()).object());
#else

#endif
}
