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

#include <QtWidgets/QMainWindow>
#include <QMovie>

#include "ui_mainwindow.h"

#include "splash.h"
#include "about.h"
#include "remotefile.h"
#include "errordialog.h"
#include "config.h"
#include "userconfig.h"
#include "zip.h"
#include "asset.h"

class MainWindow final : public QMainWindow {
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = Q_NULLPTR);

private:
	Ui::MainWindowClass _ui;
	About *_about;
	UserConfig _userConfig;
	QMap<QString, Asset> _assets;
	Asset asset(const QString &id) const;
	QJsonObject _remotes;
	QVector<Discord*> _discords;
	QVector<Discord*> *_toRemove;
	QVector<Discord*> *_toInstall;
	bool _remotesLoaded;
	
	void initOptionsPage() const;

protected:
	int _mousePressX;
	int _mousePressY;
	bool _drag = false;
	void mouseMoveEvent(QMouseEvent *event) override;
	void mousePressEvent(QMouseEvent *event) override;
	void mouseReleaseEvent(QMouseEvent *event) override;

	void changeEvent(QEvent *event) override;

public slots:
	void splashFinished(QVector<Discord*> &discords, const QJsonObject &remotes);
	void captionCloseClicked() const;
	void captionHelpClicked() const;
	void captionMinClicked();
	void btnOptionsClicked() const;
	void btnApplyOptionsClicked();
	void btnCancelOptionsClicked() const;
	void btnContinueClicked() const;
	void installCheckboxCheckedChanged(bool checked) const;
	void dataCheckboxCheckedChanged(bool checked) const;
	void install() const;
	void processRemotes() const;
	void inject() const;

};
