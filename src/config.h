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

#include <QVersionNumber>
#include <QUrl>

#include "qtfs.hpp"
#include "qtjson.hpp"

// #define TEST_MODE

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
	QUrl repository(const QString &path);
	QUrl ghuc(const QString &path);
	QUrl release(const QString &path);
	QVersionNumber installerVersion();
	Urls urls();
	QString activeRepo();

}
