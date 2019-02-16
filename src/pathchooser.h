/* BetterDiscord Installer
 *
 * Copyright (c) 2019-present Jiiks - https://github.com/Jiiks
 * All rights reserved.
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <QObject>
#include <QFileDialog>
#include "ui_pathchooser.h"

#include "utils.h"

class PathChooser final : public QWidget {
	Q_OBJECT

public:
	explicit PathChooser(QWidget *parent = Q_NULLPTR);
	QString selectedPath() const;
	void initialize(const QString &text, const QString &hint, const QString &initialPath, const QString &suffix);
	void setSuffix(const QString &suffix);
	void setInitialPath(const QString &initialPath);
	void setHint(const QString &hint) const;
	void setPath(const QString &path);

private:
	Ui::PathChooser _ui;

	QString _suffix;
	QString _selectedPath;

	void setText() const;

public slots:
	void browse();
};
