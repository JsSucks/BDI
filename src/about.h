/**
 * BetterDiscord Installer
 * Copyright (c) 2018-present Jiiks/JsSucks - https://github.com/Jiiks / https://github.com/JsSucks
 * All rights reserved.
 * https://betterdiscord.net
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
*/

#pragma once

#include <QObject>

#include "ui_about.h"

#include "qtfs.hpp"

class About final : public QWidget {
	Q_OBJECT
public:
	explicit About(QWidget *parent = Q_NULLPTR);
	void loadLicenseText(const QString &fPath = "about.htm");

private:
	Ui::AboutWindow _ui;

public slots:
	static void aboutQt();
};

