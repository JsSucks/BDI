/* BetterDiscord Installer
 *
 * Copyright (c) 2019-present Jiiks - https://github.com/Jiiks
 * All rights reserved.
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <QObject>
#include <QMouseEvent>
#include <QVector>

#include "ui_splash.h"
#include "config.h"
#include "logger.h"
#include "discord.h"

class Splash final : public QWidget {
	Q_OBJECT

public:
	explicit Splash(QWidget *parent = Q_NULLPTR);

private:
	Ui::Splash _ui;
	QVector<Discord*> _discords;

	void systemChecks();
	void remotes(const QJsonObject &remotes);

protected:
	void mouseMoveEvent(QMouseEvent *event) override;
	void mousePressEvent(QMouseEvent *event) override;
	void mouseReleaseEvent(QMouseEvent *event) override;
	int _mousePressX;
	int _mousePressY;
	bool _drag;

public slots:
	void attemptClose();
	void btnContinueClicked();

signals:
	void finished(QVector<Discord*> &discords, const QJsonObject &remotes);
};
