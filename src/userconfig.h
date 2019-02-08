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

#include <QString>
#include "qtfs.hpp"
#include "qtjson.hpp"

class UserConfig final {
public:
	UserConfig();

	bool useCommonInstallPath() const { return _commonInstallPath; }
	void useCommonInstallPath(bool use);
	bool useCommonDataPath() const { return _commonDataPath; }
	void useCommonDataPath(bool use);
	bool autoInject() const { return _autoInject; }
	void autoInject(bool autoInject);

	QString installPath() const { return _installPath; }
	void setInstallPath(const QString &installPath);
	QString dataPath() const { return _dataPath; }
	void setDataPath(const QString &dataPath);

	UserConfig *read(const QString &fPath = "userconfig.json");
	UserConfig *write(const QString &fPath = "userconfig.json");
	UserConfig *defaults();

private:
	bool _commonInstallPath;
	bool _commonDataPath;
	bool _autoInject;

	QString _installPath;
	QString _dataPath;

};
