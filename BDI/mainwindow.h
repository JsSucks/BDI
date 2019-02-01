/* BetterDiscord Installer
 *
 * Copyright (c) 2019-present Jiiks - https://github.com/Jiiks
 * All rights reserved.
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"

class MainWindow : public QMainWindow {
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);

private:
	Ui::MainWindowClass ui;
};
