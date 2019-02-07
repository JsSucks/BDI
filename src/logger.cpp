/**
 * BetterDiscord Installer
 * Copyright (c) 2018-present Jiiks/JsSucks - https://github.com/Jiiks / https://github.com/JsSucks
 * All rights reserved.
 * https://betterdiscord.net
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
*/

#include "logger.h"

QVector<QString> Logger::_logs;

void Logger::Log(const QString &msg) {
	_logs.append(msg);

	QFile f("debug.log");
	if(!f.open(QIODevice::WriteOnly | QIODevice::Append)) {
		Debug("Unable to write logs", false);
		return;
	}

	QTextStream stream(&f);
	stream << msg << endl;
}

void Logger::Debug(const QString &msg, const bool &log) {
	const auto fullMsg = msg.isEmpty() ? "" : TimeStamp() + msg;
#ifdef QT_DEBUG
	qDebug(qPrintable(fullMsg));
#endif
	if (log) Log(fullMsg);
}

void Logger::Debug(const QVector<QString> &messages) {
	for (auto &msg : messages) Debug(msg);
}

void Logger::Dump(const QString &fPath) {
	QFile f(fPath);
	if(!f.open(QIODevice::WriteOnly)) {
		Debug("Unable to dump logs", false);
		return;
	}
	QTextStream stream(&f);
	for(auto &log : _logs) stream << log << endl;
}

QString Logger::TimeStamp() {
	return "[" + QDateTime::currentDateTime().toString("dd/MM/yy hh:mm:ss") + "] ";
}
