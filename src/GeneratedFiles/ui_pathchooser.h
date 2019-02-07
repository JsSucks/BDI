/********************************************************************************
** Form generated from reading UI file 'pathchooser.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATHCHOOSER_H
#define UI_PATHCHOOSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PathChooser
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lblText;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *lblHint;
    QPlainTextEdit *teHint;

    void setupUi(QWidget *PathChooser)
    {
        if (PathChooser->objectName().isEmpty())
            PathChooser->setObjectName(QStringLiteral("PathChooser"));
        PathChooser->resize(788, 90);
        PathChooser->setMinimumSize(QSize(0, 90));
        PathChooser->setMaximumSize(QSize(16777215, 16777215));
        PathChooser->setStyleSheet(QLatin1String("QWidget {\n"
"	background: transparent;\n"
"	color: #aeaeae;\n"
"	font-family: \"Roboto\";\n"
"}\n"
"\n"
"QLineEdit {\n"
"	background: #17171c;\n"
"	border: 1px solid #303030;\n"
"}\n"
"\n"
"QPushButton {\n"
"	background: transparent;\n"
"    color: #fff;\n"
"    padding: 7px 10px;\n"
"    min-width: 50px;\n"
"	background: #17171c;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"	background: rgb(35, 35, 38);\n"
"	background: rgb(62, 204, 156)\n"
"}\n"
"\n"
"QPlainTextEdit {\n"
"	border: 0;\n"
"}"));
        verticalLayout = new QVBoxLayout(PathChooser);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lblText = new QLabel(PathChooser);
        lblText->setObjectName(QStringLiteral("lblText"));

        verticalLayout->addWidget(lblText);

        widget = new QWidget(PathChooser);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(50, 0));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, -1, 0);
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 29));
        lineEdit->setStyleSheet(QLatin1String("padding-left: 5px;\n"
"padding-right: 5px;"));
        lineEdit->setFrame(false);
        lineEdit->setReadOnly(true);

        horizontalLayout_2->addWidget(lineEdit);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout->addWidget(widget);

        lblHint = new QLabel(PathChooser);
        lblHint->setObjectName(QStringLiteral("lblHint"));
        lblHint->setMaximumSize(QSize(16777215, 0));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(7);
        lblHint->setFont(font);

        verticalLayout->addWidget(lblHint);

        teHint = new QPlainTextEdit(PathChooser);
        teHint->setObjectName(QStringLiteral("teHint"));
        teHint->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        teHint->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout->addWidget(teHint);


        retranslateUi(PathChooser);
        QObject::connect(pushButton, SIGNAL(clicked()), PathChooser, SLOT(browse()));

        QMetaObject::connectSlotsByName(PathChooser);
    } // setupUi

    void retranslateUi(QWidget *PathChooser)
    {
        lblText->setText(QApplication::translate("PathChooser", "TextLabel", nullptr));
        lineEdit->setText(QString());
        pushButton->setText(QApplication::translate("PathChooser", "Browse", nullptr));
        lblHint->setText(QApplication::translate("PathChooser", "Text", nullptr));
        teHint->setPlainText(QString());
        Q_UNUSED(PathChooser);
    } // retranslateUi

};

namespace Ui {
    class PathChooser: public Ui_PathChooser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATHCHOOSER_H
