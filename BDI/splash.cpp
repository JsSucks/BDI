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
}

void Splash::attemptClose() {
	QApplication::quit();
}

void Splash::systemChecks() {
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
}
