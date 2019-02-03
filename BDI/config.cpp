#include "config.h"
/* BetterDiscord Installer
 *
 * Copyright (c) 2019-present Jiiks - https://github.com/Jiiks
 * All rights reserved.
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

namespace Config {

	namespace {
		QVersionNumber INSTALLER_VERSION;
		Repository REPOSITORY;
		Urls URLS;
		int API_VERSION;
	}

	void deserialize(const QString &configPath) {
		QFile configFile(configPath);
		if(!configFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
			// TODO Log error after logger refactor
			return;
		}

		auto doc(QJsonDocument::fromJson(configFile.readAll()));
		auto obj = doc.object();

		INSTALLER_VERSION = QVersionNumber::fromString(obj["version"].toString());
		API_VERSION = obj["api_version"].toInt();

		auto repository = obj["repository"].toObject();
		REPOSITORY = {
		repository["name"].toString(),
		repository["main"].toString(),
		repository["scnd"].toString(),
		repository[repository["active"].toString()].toString()
		};

		auto urls = obj["urls"].toObject();
		auto paths = urls["paths"].toObject();

		URLS = {
		urls["github"].toString(),
		urls["bd"].toString(),
		urls["api"].toString(),
		paths["release_info"].toString()
		};
	}

	QUrl repository() {
		return QUrl(URLS.github + "/" + REPOSITORY.active + "/" + REPOSITORY.name);
	}

	QUrl ghuc(const QString &path) {
		return QUrl("https://raw.githubusercontent.com/" + REPOSITORY.active + "/" + REPOSITORY.name + path);
	}

	QVersionNumber installerVersion() {
		return INSTALLER_VERSION;
	}

	Urls urls() {
		return URLS;
	}
}
