/**
 * BetterDiscord Installer
 * Copyright (c) 2018-present Jiiks/JsSucks - https://github.com/Jiiks / https://github.com/JsSucks
 * All rights reserved.
 * https://betterdiscord.net
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
*/

#include "discord.h"

Discord::Discord(const QString &channel) {
	_installState = UNKNOWN;
	_action = A_UNKNOWN;
	_channel = channel;
}

QString Discord::applicationName() const {
#if defined(Q_OS_WIN) || defined(Q_OS_LINUX)
	if (_channel == "ptb" || _channel == "canary") return "discord" + _channel;
	return "discord";
#elif defined(Q_OS_DARWIN)
	if (_channel == "ptb") return "Discord PTB.app";
	if (_channel == "canary") return "Discord Canary.app";
	return "Discord.app";
#endif
	return "Unknown";
}

#if defined(Q_OS_WIN)
void Discord::locate() {
	_baseDir = resolveBaseDir();

	if(!_baseDir.exists()) {
		_installState = UNAVAILABLE;
		return;
	}

	QDirIterator it(_baseDir, QDirIterator::NoIteratorFlags);

	QVersionNumber latestVersion(0, 0, 0);
	QDir latestDir;

	while(it.hasNext()) {
		auto dir = QDir(it.next());
		auto nextVersion = resolveVersion(dir.dirName());

		if(QVersionNumber::compare(nextVersion, latestVersion) <= 0) continue;

		latestVersion = nextVersion;
		latestDir = dir;
	}

	if(QVersionNumber::compare(_latestVersion, QVersionNumber(0,0,0)) == 0) {
		_installState = UNAVAILABLE;
		return;
	}

	_latestVersion = latestVersion;

	auto rDir = QDir(QDir::cleanPath(latestDir.absolutePath() + "/resources"));

	if(!rDir.exists()) {
		_installState = UNAVAILABLE;
		return;
	}

	_appDir = QDir(QDir::cleanPath(rDir.absolutePath() + "/app"));

	if(!_appDir.exists()) {
		_installState = NOT_INSTALLED;
		return;
	}

	QFile bdJsonFile(_appDir.filePath("bd.json"));
	if(!bdJsonFile.exists()) {
		_installState = NOT_INSTALLED;
		return;
	}
	_installState = INSTALLED;
}
#elif defined(Q_OS_LINUX)
void Discord::locate() {}
#elif defined(Q_OS_DARWIN)
void Discord::locate() {
	_baseDir = QDir(QDir::cleanPath("/Applications"));

	if(!_baseDir.exists()) {
		_installState = UNAVAILABLE;
		return;
	}

    auto bundleDir = QDir(QDir::cleanPath(_baseDir.absolutePath() + "/" + applicationName()));

	if(!bundleDir.exists()) {
        _baseDir = QDir(QDir::cleanPath(QDir::homePath() + "/Applications"));
        bundleDir = QDir(QDir::cleanPath(_baseDir.absolutePath() + "/" + applicationName()));
        if(!bundleDir.exists()) {
            _installState = UNAVAILABLE;
		    return;
        }
	}

	auto rDir = QDir(QDir::cleanPath(bundleDir.absolutePath() + "/Contents/Resources"));

	if(!rDir.exists()) {
		_installState = UNAVAILABLE;
		return;
	}

	_appDir = QDir(QDir::cleanPath(rDir.absolutePath() + "/app"));

	if(!_appDir.exists()) {
		_installState = NOT_INSTALLED;
		return;
	}

	QFile bdJsonFile(_appDir.filePath("bd.json"));
	if(!bdJsonFile.exists()) {
		_installState = NOT_INSTALLED;
		return;
	}
	_installState = INSTALLED;
}
#else
void Discord::locate() { _installState = UNAVAILABLE; }
#endif

bool Discord::inject(const QString &stub, QJsonObject config, const QString &corePath, const QString &clientPath) {
	Logger::Debug(_channel + " injecting to: " + _appDir.absolutePath());
	if(!_appDir.exists()) {
		Logger::Debug(_channel + " _appDir does not exist");
		if(!_appDir.mkpath(".")) {
			Logger::Debug(_channel + " cannot create _appDir");
			emit injected(false);
			return false;
		}
	}

	QFile indexFile(_appDir.filePath("index.js"));
	if (!indexFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
		Logger::Debug("Unable to write to: " + _appDir.filePath("index.js"));
		emit injected(false);
		return false;
	}

	QTextStream indexOut(&indexFile);
	indexOut << stub;

	QFile configFile(_appDir.filePath("bd.json"));
	if(!configFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
		Logger::Debug("Unable to write to: " + _appDir.filePath("bd.json"));
		emit injected(false);
		return false;
	}

	QFile packageFile(_appDir.filePath("package.json"));
	if(!packageFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
		Logger::Debug("Unable to write to: " + _appDir.filePath("package.json"));
		emit injected(false);
		return false;
	}

	auto options = config["options"].toObject();
	auto paths = config["paths"].toObject();

	if(options["commonCore"].toBool()) {
		paths["core"] = QDir::cleanPath(paths["core"].toString());
		paths["client"] = QDir::cleanPath(paths["client"].toString());
	} else {
		paths["core"] = QDir::cleanPath(paths["core"].toString() + _channel);
		paths["client"] = QDir::cleanPath(paths["client"].toString() + _channel);
	}

	QDir editorPath(paths["core"].toString());
	editorPath.cdUp();
	paths["editor"] = QDir::cleanPath(editorPath.absolutePath() + "/editor");

	if(options["commonData"].toBool()) {
		paths["data"] = QDir::cleanPath(paths["data"].toString());
	} else {
		paths["data"] = QDir::cleanPath(paths["data"].toString() + _channel);
	}

	config["paths"] = paths;

	QTextStream configOut(&configFile);
	configOut << QJsonDocument(config).toJson(QJsonDocument::Indented);

	QTextStream packageOut(&packageFile);
	packageOut << QJsonDocument(QJsonObject{
		{ "name", "betterdiscord" },
		{ "description", "BetterDiscord" },
		{ "main", "index.js" },
		{ "private", true }
	}).toJson(QJsonDocument::Indented);

	_installState = INSTALLED;
	emit injected(true);
	return true;
}

bool Discord::remove() {
	Logger::Debug("Removing BetteDiscord installation at: " + _appDir.absolutePath());
	if(!_appDir.exists()) {
		Logger::Debug("App dir doesn't seem to exist anymore");
		return true;
	}
	return _appDir.removeRecursively();
}

QString Discord::channelString() const {
	if (_channel == "ptb") return "Discord PTB";
	if (_channel == "canary") return "Discord Canary";
	return "Discord";
}

Product *Discord::widget() {
	if(_product != nullptr) return _product;

	_product = new Product();
	_product->setText(
		"BetterDiscord v" + _bdCoreVersion.toString() +
		"/" + _bdClientVersion.toString() +
		" for " + channelString() + " " + _latestVersion.toString()
	);

	if(_channel == "canary") _product->setIcon(":/images/logoCanary");
	else if(_channel == "ptb") _product->setIcon(":/images/logoPtb");
	else _product->setIcon(":/images/logoStable");

	switch(_installState) {
		case NOT_INSTALLED:
		case UNKNOWN:
			_product->setCheckedBtn(1);
			_product->setInstallBtnState(true, "Install");
			_product->setUninstallBtnState(false);
			break;
		case INSTALLED:
		case BROKEN:
			_product->setCheckedBtn(0);
			_product->setInstallBtnState(true, "Repair");
			_product->setUninstallBtnState(true);
			break;
		case INSTALLING:
		case UNAVAILABLE:
		default: break;
	}

	resolveAction(false);

	connect(_product, &Product::actionChanged, this, &Discord::actionChange);

	return _product;
}

void Discord::resolveAction(const bool debug) {
	const auto oldAction = _action;

	_action = _product->install() ? A_REPAIR_INSTALL :
		_product->skip() ? A_SKIP :
		_product->uninstall() ? A_UNINSTALL : A_UNKNOWN;

	if(!debug) return;
	Logger::Debug("Action changed for " + _channel +
		" from " + QMetaEnum::fromType<Action>().valueToKey(oldAction) +
		" to " + QMetaEnum::fromType<Action>().valueToKey(_action));
}

void Discord::actionChange() {
	resolveAction();
}

QVersionNumber Discord::resolveVersion(const QString &versionString) const {
	if (!versionString.startsWith("app-")) return QVersionNumber::fromString(versionString);
	auto split = versionString.split("-");
	if (split.length() != 2) return QVersionNumber::fromString(versionString);
	return QVersionNumber::fromString(split[1]);
}

QDir Discord::resolveBaseDir() const {
	const auto appName = QCoreApplication::applicationName();
	QCoreApplication::setApplicationName(applicationName());

#ifdef Q_OS_WIN
	QDir rDir(QStandardPaths::locate(QStandardPaths::AppLocalDataLocation, "", QStandardPaths::LocateOption::LocateDirectory));
#elif defined(Q_OS_LINUX)
	QDir rDir(QStandardPaths::locate(QStandardPaths::AppConfigLocation, "", QStandardPaths::LocateOption::LocateDirectory));
#elif defined(Q_OS_DARWIN)
	auto aDir = QDir(QStandardPaths::locate(QStandardPaths::ApplicationsLocation, "", QStandardPaths::LocateOption::LocateDirectory));
	QDir rDir(QDir::cleanPath(aDir.absolutePath() + applicationName()));
#endif
	QCoreApplication::setApplicationName(appName);
	return rDir;
}

void Discord::debug() const {
	// TODO get actual installed bd version from bd.json
	Logger::Debug(QVector<QString>{
		applicationName(),
			"App Dir: " + _appDir.absolutePath(),
			_installState == INSTALLED ? ("BD Installed - v2.0.0") : "BD Not Installed",
			"InstallState: " + QString(QMetaEnum::fromType<InstallState>().valueToKey(_installState)) + "\n"
	});
}

Discord::InstallState Discord::state() const {
	return _installState;
}

Discord::Action Discord::action() const {
	return _action;
}

QString Discord::channel() const {
	return _channel;
}
