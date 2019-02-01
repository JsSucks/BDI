/* BetterDiscord Installer
 *
 * Copyright (c) 2019-present Jiiks - https://github.com/Jiiks
 * All rights reserved.
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "config.h"

Config::Config() {
	
}

void Config::deserialize(const QString &configPath) {
	QFile configFile(configPath);
	if(!configFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
		// TODO Log error after logger refactor
		return;
	}	
}
