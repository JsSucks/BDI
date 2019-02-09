/**
 * BetterDiscord Installer
 * Copyright (c) 2018-present Jiiks/JsSucks - https://github.com/Jiiks / https://github.com/JsSucks
 * All rights reserved.
 * https://betterdiscord.net
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
*/

#include "product.h"

Product::Product(QWidget *parent) : QWidget(parent) {
	_ui.setupUi(this);
}

void Product::setText(const QString &text) const {
	_ui.lblInfo->setText(text);
}

void Product::setInstallBtnState(const bool enabled, const QString &text) const {
	_ui.btnInstall->setEnabled(enabled);
	_ui.btnInstall->setText(text);
}

void Product::setSkipBtnState(const bool enabled, const QString &text) const {
	_ui.btnSkip->setEnabled(enabled);
	_ui.btnSkip->setText(text);
}

void Product::setUninstallBtnState(const bool enabled, const QString &text) const {
	_ui.btnUninstall->setEnabled(enabled);
	_ui.btnUninstall->setText(text);
}

void Product::setCheckedBtn(const int index) const {
	_ui.btnInstall->setChecked(false);
	_ui.btnSkip->setChecked(false);
	_ui.btnUninstall->setChecked(false);
	switch(index) {
	case 0:
		_ui.btnInstall->setChecked(true);
		break;
	case 1:
		_ui.btnSkip->setChecked(true);
		break;
	case 2:
		_ui.btnUninstall->setChecked(true);
		break;
	default: 
		_ui.btnSkip->setChecked(true);
	}
}

void Product::setIcon(const QString &iconPath) const {
	_ui.icon->setPixmap(QPixmap(iconPath));
}

void Product::showButtons() const {
	_ui.rsStack->setCurrentWidget(_ui.pageButtons);
}


void Product::hideButtons() const {
	_ui.rsStack->setCurrentWidget(_ui.pageStatus);
}

void Product::setStatus(const QString &status) const {
	_ui.lblStatus->setText(status);
}


void Product::checkBtn(bool checked) {
	auto btn = qobject_cast<QPushButton*>(sender());
	_ui.btnInstall->setChecked(false);
	_ui.btnSkip->setChecked(false);
	_ui.btnUninstall->setChecked(false);
	btn->setChecked(true);
	emit actionChanged();
}
