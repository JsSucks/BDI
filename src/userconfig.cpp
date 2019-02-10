/**
 * BetterDiscord Installer
 * Copyright (c) 2018-present Jiiks/JsSucks - https://github.com/Jiiks / https://github.com/JsSucks
 * All rights reserved.
 * https://betterdiscord.net
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
*/

#include "userconfig.h"

UserConfig::UserConfig() {
	read();
}

void UserConfig::useCommonInstallPath(const bool use) {
	_commonInstallPath = use;
}

void UserConfig::useCommonDataPath(const bool use) {
	_commonDataPath = use;
}

void UserConfig::autoInject(const bool autoInject) {
	_autoInject = autoInject;
}

void UserConfig::setInstallPath(const QString &installPath) {
	_installPath = installPath;
}

void UserConfig::setDataPath(const QString &dataPath) {
	_dataPath = dataPath;
}

QJsonObject UserConfig::toObj() const {
	return QJsonObject{
		{ "options", QJsonObject{
			{ "commonCore", _commonInstallPath },
			{ "commonData", _commonDataPath },
			{ "autoInject", _autoInject }
		} },
		{ "paths", QJsonObject{
			{ "core", _installPath },
			{ "data", _dataPath }
		} }
	};
}


UserConfig *UserConfig::read(const QString &fPath) {
	QFile file(fPath);
	if(!file.open(QIODevice::ReadOnly)) {
		return defaults();
	}

	const auto data = file.readAll();
	auto doc(QJsonDocument::fromJson(data));
	if(!doc.isObject()) {
		return defaults();
	}

	auto obj = doc.object();

	_commonInstallPath = obj["_commonInstallPath"].toBool(true);
	_commonDataPath = obj["_commonDataPath"].toBool(false);
	_autoInject = obj["_autoInject"].toBool(true);
	_installPath = obj["_installPath"].toString("default");
	_dataPath = obj["_dataPath"].toString("default");

	return this;
}

UserConfig *UserConfig::write(const QString &fPath) {
	QJsonObject obj;
	obj["_commonInstallPath"] = _commonInstallPath;
	obj["_commonDataPath"] = _commonDataPath;
	obj["_autoInject"] = _autoInject;
	obj["_installPath"] = _installPath;
	obj["_dataPath"] = _dataPath;

	QFile file(fPath);
	if(!file.open(QIODevice::WriteOnly)) {
		return this;
	}

	file.write(QJsonDocument(obj).toJson());
	return this;
}

UserConfig *UserConfig::defaults() {
	_commonInstallPath = true;
	_commonDataPath = false;
	_autoInject = true;
	_installPath = "default";
	_dataPath = "default";
	return write();
}
