/**
 * BetterDiscord Installer
 * Copyright (c) 2018-present Jiiks/JsSucks - https://github.com/Jiiks / https://github.com/JsSucks
 * All rights reserved.
 * https://betterdiscord.net
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
*/

#include "utils.h"

void Utils::copyDir(const QString &src, const QString &dst) {
	QDir dir(src);
	if(!dir.exists()) return;

	foreach(QString d, dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot)) {
		auto dstPath = dst + QDir::separator() + d;
		dir.mkpath(dstPath);
		copyDir(src + QDir::separator() + d, dstPath);
	}

	foreach(QString f, dir.entryList(QDir::Files)) {
		QFile::copy(src + QDir::separator() + f, dst + QDir::separator() + f);
	}
}

bool Utils::pathEndsIn(const QString &path, const QString &suffix) {
	return QDir::cleanPath(path).toLower().endsWith(suffix);
}
