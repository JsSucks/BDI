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

#include <QProgressBar>
#include <QTimer>
#include <QPainter>
#include <QColor>
#include <QDateTime>

class Pbar final : public QProgressBar {
	Q_OBJECT

public:
	explicit Pbar(QWidget *parent);

private:
	QTimer *_animTimer;

	QColor _borderColour;
	QColor _chunkColour;
	QBrush _chunkBrush;
	QColor _bgColour;
	QBrush _bgBrush;
	QImage _gradient;

	double _trailingValue;
	double _tracker;

protected:
	void paintEvent(QPaintEvent *event) override;

public slots:
	void animate();
};

