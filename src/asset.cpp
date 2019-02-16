/**
 * BetterDiscord Installer
 * Copyright (c) 2018-present Jiiks/JsSucks - https://github.com/Jiiks / https://github.com/JsSucks
 * All rights reserved.
 * https://betterdiscord.net
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
*/

#include "asset.h"

Asset::Asset(const QJsonObject &obj) {
	_id = obj["id"].toString();
	_fileName = obj["name"].toString();
	_version = QVersionNumber::fromString(obj["version"].toString());
	_size = obj["size"].toInt();
	_remoteLocation = obj["remote"].toString();
	_hash = obj["hash"].toString();
}

QString Asset::id() const {
	return _id;
}

QString Asset::fileName() const {
	return _fileName;
}

QVersionNumber Asset::version() const {
	return _version;
}

int Asset::size() const {
	return _size;
}

QUrl Asset::remoteLocation() const {
	return Config::repository(_remoteLocation);
}

QUrl Asset::raw() const {
	return Config::ghuc(_remoteLocation);
}

QString Asset::hash() const {
	return _hash;
}

bool Asset::localFileExists() const {
	return remote->exists();
}

bool Asset::compareHash(const bool recalculate) const {
	return remote->compareHash(_hash, recalculate);
}
