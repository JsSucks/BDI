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
#include <QtWidgets/QApplication>
#include "config.h"

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	Config::deserialize();

	MainWindow w;

	return app.exec();
}
