/* BetterDiscord Installer
 *
 * Copyright (c) 2019-present Jiiks - https://github.com/Jiiks
 * All rights reserved.
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <QVersionNumber>
#include <QUrl>

#include "qtfs.hpp"
#include "qtjson.hpp"

#define TEST_MODE

struct Repository final {
	QString name;
	QString main;
	QString scnd;
	QString active;
};

struct Paths final {
	QString releaseInfo;
};

struct Urls final {
	QString github;
	QString bd;
	QString api;
	Paths paths;
};

namespace Config {
	void deserialize(const QString &configPath = "config.json");
	QUrl repository();
	QUrl ghuc(const QString &path);
	QVersionNumber installerVersion();
	Urls urls();
}
