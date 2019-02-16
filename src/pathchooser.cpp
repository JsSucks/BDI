/* BetterDiscord Installer
 *
 * Copyright (c) 2019-present Jiiks - https://github.com/Jiiks
 * All rights reserved.
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "pathchooser.h"

PathChooser::PathChooser(QWidget *parent) : QWidget(parent) {
	_ui.setupUi(this);
	_suffix = "";
}

QString PathChooser::selectedPath() const {
	return _selectedPath; 
}

void PathChooser::initialize(const QString &text, const QString &hint, const QString &initialPath, const QString &suffix) {
	if(!_selectedPath.isEmpty()) return;
	setSuffix(suffix);
	setInitialPath(initialPath);
	_ui.lblText->setText(text);
	setHint(hint);
}

void PathChooser::setSuffix(const QString &suffix) {
	_suffix = suffix;
	if(_selectedPath.isEmpty()) return;
	setText();
}

void PathChooser::setInitialPath(const QString &initialPath) {
	if(!_selectedPath.isEmpty()) return;
	_selectedPath = Utils::pathEndsIn(initialPath, "/betterdiscord") ? initialPath : initialPath + "/BetterDiscord";
	setText();
}

void PathChooser::setHint(const QString &hint) const {
	_ui.lblHint->setText("");
	_ui.teHint->setPlainText(hint);
}

void PathChooser::setPath(const QString &path) {
	_selectedPath = Utils::pathEndsIn(path, "/betterdiscord") ? path : path + "/BetterDiscord";
	setText();
}

void PathChooser::browse() {
	auto dialogResult = QFileDialog::getExistingDirectory(this->parentWidget(), "Choose path", _selectedPath);
	if(dialogResult.isEmpty()) return;

	setPath(dialogResult);
}

void PathChooser::setText() const {
	_ui.lineEdit->setText(QDir(_selectedPath + _suffix).absolutePath());
}
