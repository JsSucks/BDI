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

struct Repository {
	QString name;
	QString main;
	QString scnd;
	QString active;
};

struct Paths {
	QString releaseInfo;
};

struct Urls {
	QString github;
	QString bd;
	QString api;
	Paths paths;
};

class Config final {
public:
	Config();

	void deserialize(const QString &configPath = "config.json");

	QUrl repository() const;
	QUrl ghuc(const QString &path) const;
	Urls urls() const;

private:
	Repository _repository;
	Urls _urls;
	int _apiVersion;
	QVersionNumber _installerVersion;
};

extern Config *CONFIG;
