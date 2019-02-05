/* BetterDiscord Installer
 *
 * Copyright (c) 2019-present Jiiks - https://github.com/Jiiks
 * All rights reserved.
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

