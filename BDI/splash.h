/* BetterDiscord Installer
 *
 * Copyright (c) 2019-present Jiiks - https://github.com/Jiiks
 * All rights reserved.
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <QObject>

#include "ui_splash.h"

class Splash final : public QWidget {
	Q_OBJECT

public:
	explicit Splash(QWidget *parent = Q_NULLPTR);

private:
	Ui::Splash _ui;

public slots:
	void attemptClose();

signals:
	void finished();
};
