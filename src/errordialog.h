/**
 * BetterDiscord Installer
 * Copyright (c) 2018-present Jiiks/JsSucks - https://github.com/Jiiks / https://github.com/JsSucks
 * All rights reserved.
 * https://betterdiscord.net
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
*/

#include <QObject>
#include "ui_errordialog.h"

class ErrorDialog final : public QWidget {
	Q_OBJECT

public:
	ErrorDialog(const QString &text, QWidget *parent = Q_NULLPTR);
	explicit ErrorDialog(QWidget *parent = Q_NULLPTR) : ErrorDialog("", parent){};

	void setErrorText(const QString &text) const;

private:
	Ui::ErrorDialog _ui;

public slots:
	void btnOkClicked();
};
