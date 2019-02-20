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
	_extracted = false;
}

bool Zip::isExtracted() {
	return _extracted;
}


#if defined(Q_OS_WIN)
void Zip::extract(const QString &out) {
	if(!out.isEmpty()) _out = out;
	if(QFileInfo(_in).fileName().endsWith(".tar.gz")) return extractTarGz();
	auto extractProcess = new QProcess(this);
	
	QStringList args{"x", "-y", _in, "-o" + _out};

	Logger::Debug(_extractProgram + " " + args.join(" "));

	connect(extractProcess, &QProcess::readyReadStandardOutput, [&]() {
		emit extractProcessChanged(QString(extractProcess->readAllStandardOutput()));
	});

	connect(extractProcess, static_cast<void(QProcess:: *)(int, QProcess::ExitStatus)>(&QProcess::finished), [=](int exitCode, QProcess::ExitStatus exitStatus) {
		delete extractProcess;
		_extracted = true;
		emit extracted(true);
	});

	extractProcess->start(_extractProgram, args);
	if(!extractProcess->waitForStarted()) {
		Logger::Debug("extractProcess failed to start!");
		emit extracted(false);
	}
}

void Zip::extractTarGz() {
	auto gzProcess = new QProcess(this);
	QStringList gzArgs{ "x", _in, "-so" };
	Logger::Debug(_extractProgram + " " + gzArgs.join(" "));

	connect(gzProcess, &QProcess::readyReadStandardOutput, [&]() {
		emit extractProcessChanged(QString(gzProcess->readAllStandardOutput()));
	});

	auto tarProcess = new QProcess(this);
	QStringList tarArgs{ "x", "-aoa", "-si", "-ttar", "-o" + _out };
	Logger::Debug(_extractProgram + " " + tarArgs.join(" "));

	connect(tarProcess, static_cast<void(QProcess:: *)(int, QProcess::ExitStatus)>(&QProcess::finished), [=](int exitCode, QProcess::ExitStatus exitStatus) {
		delete tarProcess;
		delete gzProcess;
		_extracted = true;
		emit extracted(true);
	});

	gzProcess->setStandardOutputProcess(tarProcess);

	gzProcess->start(_extractProgram, gzArgs);
	tarProcess->start(_extractProgram, tarArgs);
	tarProcess->setProcessChannelMode(QProcess::ForwardedChannels);

	if(!gzProcess->waitForStarted()) {
		Logger::Debug("gzProcess failed to start!");
		emit extracted(false);
	}
}

#elif defined(Q_OS_DARWIN)
void Zip::extract(const QString &out) {
	if(!out.isEmpty()) _out = out;
	// Since we have no zip support on osx just return targz
	return extractTarGz();
}

void Zip::extractTarGz() {
	auto gzProcess = new QProcess(this);
	QStringList gzArgs{ "-zxf", _in };
	Logger::Debug(_extractProgram + " " + gzArgs.join(" "));

	connect(gzProcess, static_cast<void(QProcess:: *)(int, QProcess::ExitStatus)>(&QProcess::finished), [=](int exitCode, QProcess::ExitStatus exitStatus) {
		delete gzProcess;
		emit extracted(true);
	});

	gzProcess->start(_extractProgram, gzArgs);

	if(!gzProcess->waitForStarted()) {
		Logger::Debug("gzProcess failed to start!");
		emit extracted(false);
	}
}
#else
void Zip::extract() {

}

void Zip::extractTarGz() {

}
#endif