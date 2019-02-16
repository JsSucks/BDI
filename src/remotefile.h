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

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QLocale>

#include "qtfs.hpp"
#include "logger.h"

class RemoteFile final : public QObject {
	Q_OBJECT
		QNetworkAccessManager _manager;

public:
	RemoteFile(const QString &fileName, const QString &basePath, const QUrl &remoteLocation, bool memoryOnly = true);
	RemoteFile(const QString &basePath, const QUrl &remoteLocation, const bool memoryOnly = true) : RemoteFile("", basePath, remoteLocation, memoryOnly) {};
	explicit RemoteFile(const QUrl &remoteLocation, const bool memoryOnly = true) : RemoteFile("", "", remoteLocation, memoryOnly) {};

	void download();
	void loadLocal();
	QString readAll() const;
	QByteArray hash(const QCryptographicHash::Algorithm &algorithm = QCryptographicHash::Sha256);
	QString hashString(const QCryptographicHash::Algorithm &algorithm = QCryptographicHash::Sha256);
	bool compareHash(const QString &hash, const bool &recalculate = false);
	bool exists() const;
	bool downloaded() const;
	void setDownloaded(bool downloaded);

	QUrl remoteLocation() const { return _remoteLocation; }
	QString fileName() const { return _fileName; }
	QDir basePath() const { return _basePath; }
	QString localFilePath() const { return _localFilePath; }
	bool localFileExists() const { return QFile(_localFilePath).exists(); }
	QFile &localFile() const { return QFile(_localFilePath); }
	bool isMemoryOnly() const { return _memoryOnly; }
	QString errorMsg() const { return _error; }
	QByteArray bytes() const { return _bytes; }

private:
	QUrl _remoteLocation;
	QString _fileName;
	QDir _basePath;
	QString _localFilePath;
	bool _memoryOnly;
	bool _downloaded;
	QLocale _systemLocale = QLocale::system();
	QByteArray _bytes;
	QString _error;
	QByteArray _hash;

public slots:
	void downloadFinished(QNetworkReply *reply);

signals:
	void downloadProgressChanged(qint64 bytesReceived, qint64 bytesTotal, double percentage, QString bytesReceivedFormatted, QString bytesTotalFormatted);
	void finished(RemoteFile *remoteFile);
	void error(RemoteFile *remoteFile);
};
