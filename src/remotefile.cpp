/**
 * BetterDiscord Installer
 * Copyright (c) 2018-present Jiiks/JsSucks - https://github.com/Jiiks / https://github.com/JsSucks
 * All rights reserved.
 * https://betterdiscord.net
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
*/

#include "remotefile.h"

RemoteFile::RemoteFile(const QString &fileName, const QString &basePath, const QUrl &remoteLocation, const bool memoryOnly) {
	_downloaded = false;
	_memoryOnly = memoryOnly;
	_fileName = fileName;
	_basePath = QDir(QDir::cleanPath(basePath));
	_remoteLocation = remoteLocation;

	connect(&_manager, &QNetworkAccessManager::finished, this, &RemoteFile::downloadFinished);
}

void RemoteFile::download() {
	Logger::Debug("Fetching remote file: " + _remoteLocation.toString());
	QNetworkRequest request(_remoteLocation);
	request.setAttribute(QNetworkRequest::FollowRedirectsAttribute, true);
	request.setHeader(QNetworkRequest::UserAgentHeader, "BetterDiscord");
	const auto reply = _manager.get(request);

	connect(reply, &QNetworkReply::downloadProgress, [=](const qint64 bytesReceived, const qint64 bytesTotal) {
		if(bytesTotal <= 0) return;
		emit downloadProgressChanged(
			bytesReceived,
			bytesTotal,
			bytesReceived * 100 / bytesTotal,
			_systemLocale.formattedDataSize(bytesReceived),
			_systemLocale.formattedDataSize(bytesTotal)
		);
	});
}

void RemoteFile::loadLocal() {
	_localFilePath = _basePath.filePath(_fileName);
}


void RemoteFile::downloadFinished(QNetworkReply *reply) {
	auto url = reply->url();

	auto statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);

	Logger::Debug("Finished fetch: " + url.toString() + " - " + statusCode.toString());

	_downloaded = true;

	if(reply->error()) {
		_error = reply->errorString();
		emit error(this);
		return;
	}

	if(_memoryOnly) {
		_bytes = reply->readAll();
		emit finished(this);
		return;
	}

	if(_fileName.isEmpty()) {
		_fileName = QFileInfo(url.path()).fileName();
	}

	_localFilePath = _basePath.filePath(_fileName);

	QFile f(_localFilePath);
	if(!f.open(QIODevice::WriteOnly)) {
		_error = "Cannot write to: " + _localFilePath;
		emit error(this);
		return;
	}

	f.write(reply->readAll());
	f.close();

	emit finished(this);
}

QString RemoteFile::readAll() const {
	if(_memoryOnly) return _bytes;

	if(!QFile::exists(_localFilePath)) return "";
	QFile f(_localFilePath);
	if(!f.open(QFile::ReadOnly | QFile::Text)) return "";
	auto ra = f.readAll();
	f.close();
	return ra;
}

QByteArray RemoteFile::hash(const QCryptographicHash::Algorithm &algorithm) {
	if(!_hash.isEmpty()) return _hash;

	QCryptographicHash hash(algorithm);
	if(!_memoryOnly) {
		QFile f(_localFilePath);
		f.open(QFile::ReadOnly);
		hash.addData(&f);
		f.close();
		return (_hash = hash.result().toHex());
	}
	hash.addData(_bytes);
	return (_hash = hash.result().toHex());
}

QString RemoteFile::hashString(const QCryptographicHash::Algorithm &algorithm) {
	return QString::fromUtf8(hash(algorithm));
}

bool RemoteFile::compareHash(const QString &hash, const bool &recalculate) {
	if(recalculate) _hash.clear();
	auto hs = hashString();
	Logger::Debug(QFileInfo(_localFilePath).fileName() + " - " + hs.toUpper() + "|" + hash.toUpper());
	return hs.compare(hash, Qt::CaseInsensitive) == 0;
}

bool RemoteFile::exists() const {
	return QFile::exists(_localFilePath);
}

bool RemoteFile::downloaded() const {
	return _downloaded;
}

void RemoteFile::setDownloaded(const bool downloaded) {
	_downloaded = downloaded;
}
