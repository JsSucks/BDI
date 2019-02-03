/* BetterDiscord Installer
 *
 * Copyright (c) 2019-present Jiiks - https://github.com/Jiiks
 * All rights reserved.
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

	if(latestVersion.majorVersion() == 0 && latestVersion.minorVersion() == 0 && latestVersion.microVersion() == 0) {
		_installState = UNAVAILABLE;
		return;
	}

	_latestVersion = latestVersion;

	auto rDir = QDir(QDir::toNativeSeparators(latestDir.absolutePath() + "/resources"));

	if(!rDir.exists()) {
		_installState = UNAVAILABLE;
		return;
	}

	_appDir = QDir(QDir::toNativeSeparators(rDir.absolutePath() + "/app"));

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
void Discord::locate() {}
#else
void Discord::locate() { _installState = UNAVAILABLE; }
#endif

bool Discord::inject() {
	if(!_appDir.exists()) {
		if (!_appDir.mkdir(".")) return false;
	}

	QFile f(_appDir.filePath("index.js"));
	if (!f.open(QIODevice::WriteOnly | QIODevice::Text)) return false;

	QTextStream out(&f);
	out << _stub;

	_installState = INSTALLED;
	return true;
}

QString Discord::channelString() const {
	if (_channel == "ptb") return "Discord PTB";
	if (_channel == "canary") return "Discord Canary";
	return "Discord";
}

Product *Discord::widget() {
	if(_product != nullptr) return _product;

	_product = new Product();

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
	return QDir("");
}
