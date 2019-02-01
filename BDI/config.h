/* BetterDiscord Installer
 *
 * Copyright (c) 2019-present Jiiks - https://github.com/Jiiks
 * All rights reserved.
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include "qtfs.hpp"
#include "qtjson.hpp"

class Config final {
public:
	Config();

	void deserialize(const QString &configPath = "config.json");
};
