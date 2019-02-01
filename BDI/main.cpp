/* BetterDiscord Installer
 *
 * Copyright (c) 2019-present Jiiks - https://github.com/Jiiks
 * All rights reserved.
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


#include "mainwindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	MainWindow w;
	w.show();
	return a.exec();
}
