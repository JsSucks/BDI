#pragma once

#include <QVersionNumber>
#include <QUrl>

#include "config.h"
#include "qtjson.hpp"
#include "zip.h"
#include "remotefile.h"

class Asset final {
public:
	explicit Asset(const QJsonObject &obj);

	QString id() const;
	QString fileName() const;
	QVersionNumber version() const;
	int size() const;
	QUrl remoteLocation() const;
	QUrl raw() const;
	QString hash() const;
	bool localFileExists() const;
	bool compareHash(const bool recalculate = false) const;

	RemoteFile *remote;
	Zip *zip;

private:
	QString _id;
	QString _fileName;
	QVersionNumber _version;
	int _size;
	QString _remoteLocation;
	QString _hash;
};
