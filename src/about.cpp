/**
 * BetterDiscord Installer
 * Copyright (c) 2018-present Jiiks/JsSucks - https://github.com/Jiiks / https://github.com/JsSucks
 * All rights reserved.
 * https://betterdiscord.net
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
*/

#include "about.h"
#include "splash.h"

About::About(QWidget *parent) : QWidget(parent) {
	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
	_ui.setupUi(this);
	_ui.lblVersion->setText("Version " + Config::installerVersion().toString());
}

void About::aboutQt() {
	qApp->aboutQt();
}

void About::loadLicenseText(const QString &fPath) {
	QFile f(fPath);
	if(!f.open(QIODevice::ReadOnly | QIODevice::Text)) return;

	_ui.licenses->setText(f.readAll());
}
