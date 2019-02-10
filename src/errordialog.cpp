/**
 * BetterDiscord Installer
 * Copyright (c) 2018-present Jiiks/JsSucks - https://github.com/Jiiks / https://github.com/JsSucks
 * All rights reserved.
 * https://betterdiscord.net
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
*/

#include "errordialog.h"

ErrorDialog::ErrorDialog(const QString &text, QWidget *parent) : QWidget(parent) {
	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
	_ui.setupUi(this);
	setErrorText(text);
}

void ErrorDialog::setErrorText(const QString &text) const {
	_ui.lblErrorText->setText(text);
}

void ErrorDialog::btnOkClicked() {
	qApp->quit();
}
