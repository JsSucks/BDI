/**
 * BetterDiscord Installer
 * Copyright (c) 2018-present Jiiks/JsSucks - https://github.com/Jiiks / https://github.com/JsSucks
 * All rights reserved.
 * https://betterdiscord.net
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
*/

#include "zip.h"

Zip::Zip(const QString &in, const QString &out) {
	_in = in;
	_out = out;
}

#if defined(Q_OS_WIN)
void Zip::extract() {
	if(QFileInfo(_in).fileName().endsWith(".tar.gz")) return extractTarGz();
	QProcess extractProcess;

	QStringList args;
	args << "x" << "-y" << _in << "-o" + _out;

	Logger::Debug(_extractProgram + " " + args.join(" "));

	connect(&extractProcess, &QProcess::readyReadStandardOutput, [&]() {
		emit extractProcessChanged(QString(extractProcess.readAllStandardOutput()));
	});

	extractProcess.start(_extractProgram, args);
	if(!extractProcess.waitForFinished()) {
		Logger::Debug("extractProcess failed to finish!");
		emit extracted(false);
		return;
	}

	emit extracted(true);
}

void Zip::extractTarGz() {
	QProcess gzProcess;
	QStringList gzArgs;
	gzArgs << "x" << _in << "-so";
	Logger::Debug(_extractProgram + " " + gzArgs.join(" "));

	connect(&gzProcess, &QProcess::readyReadStandardOutput, [&]() {
		emit extractProcessChanged(QString(gzProcess.readAllStandardOutput()));
	});

	QProcess tarProcess;
	QStringList tarArgs;
	tarArgs << "x" << "-aoa" << "-si" << "-ttar" << "-o" + _out;
	Logger::Debug(_extractProgram + " " + tarArgs.join(" "));

	gzProcess.setStandardOutputProcess(&tarProcess);

	gzProcess.start(_extractProgram, gzArgs);
	tarProcess.start(_extractProgram, tarArgs);
	tarProcess.setProcessChannelMode(QProcess::ForwardedChannels);

	if(!gzProcess.waitForStarted()) {
		Logger::Debug("gzProcess failed to start!");
		emit extracted(false);
		return;
	}

	if(!gzProcess.waitForFinished()) {
		Logger::Debug("gzProcess failed to finish!");
		emit extracted(false);
		return;
	}

	if(!tarProcess.waitForFinished()) {
		Logger::Debug("tarProcess failed to finish!");
		emit extracted(false);
		return;
	}

	emit extracted(true);
}

#else
void Zip::extract() {

}

void Zip::extractTarGz() {

}
#endif