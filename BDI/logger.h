/* BetterDiscord Installer
 *
 * Copyright (c) 2019-present Jiiks - https://github.com/Jiiks
 * All rights reserved.
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <QString>
#include <QDateTime>
#include <QVector>
#include <QTextStream>

#include "qtfs.hpp"

class Logger final {
public:
	static void Log(const QString &msg);
	static void Debug(const QString &msg, const bool &log = true);
	static void Debug(const QVector<QString> &messages);

	static void Dump(const QString &fPath = "debug.log");
	static QString TimeStamp();

private:
	static QVector<QString> _logs;
};