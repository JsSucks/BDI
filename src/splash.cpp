/**
 * BetterDiscord Installer
 * Copyright (c) 2018-present Jiiks/JsSucks - https://github.com/Jiiks / https://github.com/JsSucks
 * All rights reserved.
 * https://betterdiscord.net
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
*/

#include "splash.h"
#include <QTimer>
#include "remotefile.h"

Splash::Splash(QWidget *parent) : QWidget(parent) {
	setWindowFlags(Qt::FramelessWindowHint);
	if(!QDir("tmp").exists()) {
		if(!QDir("tmp").mkpath(".")) {
			Logger::Debug("Unable to create tmp dir");
			qApp->exit(0);
			return;
		}
	}

	_ui.setupUi(this);
	_ui.mainStack->setCurrentIndex(0);
}

void Splash::attemptClose() {
	QApplication::quit();
}

void Splash::systemChecks() {
	Logger::Debug("System checks started");

	auto stable = new Discord("stable");
	stable->locate();
	stable->debug();
	_ui.pbarSystemChecks->setValue(33);

	auto ptb = new Discord("ptb");
	ptb->locate();
	ptb->debug();
	_ui.pbarSystemChecks->setValue(66);

	auto canary = new Discord("canary");
	canary->locate();
	canary->debug();
	_ui.pbarSystemChecks->setValue(100);

	_discords = QVector<Discord*> {
		stable,
		ptb,
		canary
	};

	Logger::Debug("System checks finished");
}

void Splash::remotes(const QJsonObject &remotes) {
	_ui.pbarRemotes->setValue(100);
	emit finished(_discords, remotes);
	hide();
}


void Splash::mouseMoveEvent(QMouseEvent *event) {
	if (!_drag) return;
	move(event->globalX() - _mousePressX, event->globalY() - _mousePressY);
}

void Splash::mousePressEvent(QMouseEvent *event) {
	_drag = true;
	_mousePressX = event->x();
	_mousePressY = event->y();
}

void Splash::mouseReleaseEvent(QMouseEvent *event) {
	_drag = false;
}

void Splash::btnContinueClicked() {
	_ui.mainStack->setCurrentIndex(1);
	systemChecks();

#ifdef TEST_MODE
	QFile rf("releaseinfo.json");
	rf.open(QIODevice::ReadOnly | QIODevice::Text);
	remotes(QJsonDocument::fromJson(rf.readAll()).object());
#else
	auto qnam = new QNetworkAccessManager(this);
	QNetworkRequest req;
	req.setAttribute(QNetworkRequest::FollowRedirectsAttribute, true);
	req.setUrl(QUrl("https://github.com/" + Config::activeRepo() + "/BetterDiscordApp/releases/latest"));
	connect(qnam, &QNetworkAccessManager::finished, [&](QNetworkReply *reply) {
		auto latestReleaseUrl = reply->url();
		Logger::Debug("Latest Release: " + latestReleaseUrl.url());
		_ui.pbarRemotes->setValue(50);

		auto remotesFile = new RemoteFile(QUrl(latestReleaseUrl.url().replace("tag", "download") + "/releaseinfo.json"));
		connect(remotesFile, &RemoteFile::error, [](RemoteFile *remoteFile) {
			Logger::Debug(remoteFile->errorMsg());
		});
		connect(remotesFile, &RemoteFile::finished, [&](RemoteFile *remoteFile) {
			remotes(QJsonDocument::fromJson(remoteFile->bytes()).object());
		});
		remotesFile->download();
	});
	qnam->get(req);
#endif

}
