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
