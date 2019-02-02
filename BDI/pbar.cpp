/* BetterDiscord Installer
 *
 * Copyright (c) 2019-present Jiiks - https://github.com/Jiiks
 * All rights reserved.
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
