/**
 * BetterDiscord Installer
 * Copyright (c) 2018-present Jiiks/JsSucks - https://github.com/Jiiks / https://github.com/JsSucks
 * All rights reserved.
 * https://betterdiscord.net
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
*/

#include "pbar.h"

Pbar::Pbar(QWidget* parent) : QProgressBar(parent) {
	_borderColour = QColor("#191919");
	_chunkColour = QColor(62, 204, 156);
	_chunkBrush = QBrush(_chunkColour, Qt::SolidPattern);
	_bgColour = QColor(30, 30, 38);
	_bgBrush = QBrush(_bgColour, Qt::SolidPattern);
	_gradient = QImage(":/images/pbargradient");

	_trailingValue = static_cast<double>(value());
	_tracker = qrand() % -20;

	_animTimer = new QTimer(this);
	connect(_animTimer, &QTimer::timeout, this, &Pbar::animate);
	_animTimer->start(5);
}

void Pbar::animate() {
	if (_trailingValue >= maximum() - 0.1) _animTimer->stop();
	_tracker += 2;
	if (_tracker > width()) _tracker = qrand() % -20;
	if (_trailingValue >= value()) {
		update();
		return;
	}
	_trailingValue = _trailingValue + (value() - _trailingValue) / 10;
	update();
}

void Pbar::paintEvent(QPaintEvent* event) {
	QPainter painter(this);

	painter.setPen(_borderColour);
	painter.drawRect(0, 0, width() - 1, height() - 1);

	const auto percent = static_cast<double>(width()) / static_cast<double>(maximum());
	const auto chunk = percent * _trailingValue;

	painter.fillRect(0, 0, chunk, height() - 1, _chunkBrush);
	if (value() >= maximum()) return;
	painter.drawImage(QRectF(_tracker, 1, _gradient.width() / 2, _gradient.height()), _gradient);

	painter.fillRect(chunk, 1, width(), height() - 2, _bgBrush);
}
