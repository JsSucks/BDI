/* BetterDiscord Installer
 *
 * Copyright (c) 2019-present Jiiks - https://github.com/Jiiks
 * All rights reserved.
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "config.h"

Config *CONFIG = new Config();

Config::Config() {}

QUrl Config::repository() const {
	return QUrl(_urls.github + "/" + _repository.active + "/" + _repository.name);
}

QUrl Config::ghuc(const QString &path) const {
	return QUrl("https://raw.githubusercontent.com/" + _repository.active + "/" + _repository.name + path);
}

Urls Config::urls() const {
	return _urls;
}

void Config::deserialize(const QString &configPath) {
	QFile configFile(configPath);
	if(!configFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
		// TODO Log error after logger refactor
		return;
	}

	auto doc(QJsonDocument::fromJson(configFile.readAll()));
	auto obj = doc.object();

	_installerVersion = QVersionNumber::fromString(obj["version"].toString());
	_apiVersion = obj["api_version"].toInt();

	auto repository = obj["repository"].toObject();

	_repository = {
		repository["name"].toString(),
		repository["main"].toString(),
		repository["scnd"].toString(),
		repository[repository["active"].toString()].toString()
	};

	auto urls = obj["urls"].toObject();
	auto paths = urls["paths"].toObject();

	_urls = {
		urls["github"].toString(),
		urls["bd"].toString(),
		urls["api"].toString(),
		paths["release_info"].toString()
	};
}
