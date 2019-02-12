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
	auto extractProcess = new QProcess(this);

	QStringList args;
	args << "x";
	args << "-y";
	args << _in;
	args << "-o" + _out;

	Logger::Debug(_extractProgram + " " + args.join(" "));

	connect(extractProcess, &QProcess::readyReadStandardOutput, [&]() {
		emit extractProcessChanged(QString(extractProcess->readAllStandardOutput()));
	});

	extractProcess->start(_extractProgram, args);
	if(!extractProcess->waitForFinished()) {
		emit extracted(false);
	} else {
		emit extracted(true);
	}
}
#else
void Zip::extract() {

}
#endif