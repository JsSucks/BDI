/* BetterDiscord Installer
 *
 * Copyright (c) 2019-present Jiiks - https://github.com/Jiiks
 * All rights reserved.
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <QVersionNumber>
#include <QMetaEnum>
#include <QTextStream>

#include "qtfs.hpp"
#include "product.h"
#include "logger.h"

class Discord final : public QObject {
	Q_OBJECT

public:
	explicit Discord(const QString &channel);

	enum InstallState {
		NOT_INSTALLED = 0x0,
		INSTALLED = 0x1,
		INSTALLING = 0x2,
		BROKEN = 0x4,
		UNAVAILABLE = 0x8,
		UNKNOWN = 0x10
	};
	Q_ENUM(InstallState)

	enum Action {
		A_REPAIR_INSTALL = 0x0,
		A_UNINSTALL = 0x1,
		A_SKIP = 0x2,
		A_UNKNOWN = 0x4
	};
	Q_ENUM(Action)


	QString applicationName() const;
	void locate();
	bool inject();
	QString channelString() const;

	Product *widget();
	void debug() const;

	InstallState state() const;
	QString channel() const;

private:
	QString _channel;
	QDir _baseDir;
	QDir _appDir;
	InstallState _installState;
	Action _action;
	QVersionNumber _latestVersion;
	QVersionNumber _bdCoreVersion;
	QVersionNumber _bdClientVersion;
	QString _stub;

	Product *_product = nullptr;

	void resolveAction(bool debug = true);
	void actionChange();

	QVersionNumber resolveVersion(const QString &versionString) const;
	QDir resolveBaseDir() const;
};