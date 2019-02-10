/********************************************************************************
** Form generated from reading UI file 'errordialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERRORDIALOG_H
#define UI_ERRORDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ErrorDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *content;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_4;
    QLabel *lblErrorText;
    QWidget *footer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;

    void setupUi(QWidget *ErrorDialog)
    {
        if (ErrorDialog->objectName().isEmpty())
            ErrorDialog->setObjectName(QStringLiteral("ErrorDialog"));
        ErrorDialog->resize(456, 204);
        ErrorDialog->setStyleSheet(QLatin1String("#ErrorDialog {\n"
"	background: rgb(62, 204, 156);\n"
"}\n"
"\n"
"#centralWidget {\n"
"	background: rgb(30, 30, 38);\n"
"}\n"
"\n"
"#footer {\n"
"	background: rgb(32, 32, 38);\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"	border: 0;\n"
"	background: transparent;\n"
"	width: 5px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"	background: rgb(62, 204, 156)\n"
"}\n"
"\n"
"QScrollArea {\n"
"	border: 0;\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(ErrorDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        centralWidget = new QWidget(ErrorDialog);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        content = new QWidget(centralWidget);
        content->setObjectName(QStringLiteral("content"));
        verticalLayout_3 = new QVBoxLayout(content);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label = new QLabel(content);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QLatin1String("color: #aeaeae;\n"
"	font-family: \"Roboto\";"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label);

        scrollArea = new QScrollArea(content);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setStyleSheet(QLatin1String("background: rgb(30, 30, 38);\n"
"font-family: \"Inconsolata\";"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 434, 98));
        verticalLayout_4 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        lblErrorText = new QLabel(scrollAreaWidgetContents);
        lblErrorText->setObjectName(QStringLiteral("lblErrorText"));
        lblErrorText->setStyleSheet(QStringLiteral("color: #aeaeae"));

        verticalLayout_4->addWidget(lblErrorText);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_3->addWidget(scrollArea);


        verticalLayout_2->addWidget(content);

        footer = new QWidget(centralWidget);
        footer->setObjectName(QStringLiteral("footer"));
        footer->setMinimumSize(QSize(0, 50));
        footer->setMaximumSize(QSize(16777215, 50));
        footer->setStyleSheet(QLatin1String("QPushButton {\n"
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
"}"));
        horizontalLayout = new QHBoxLayout(footer);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOk = new QPushButton(footer);
        btnOk->setObjectName(QStringLiteral("btnOk"));
        btnOk->setMinimumSize(QSize(70, 28));

        horizontalLayout->addWidget(btnOk);


        verticalLayout_2->addWidget(footer);


        verticalLayout->addWidget(centralWidget);


        retranslateUi(ErrorDialog);
        QObject::connect(btnOk, SIGNAL(clicked()), ErrorDialog, SLOT(btnOkClicked()));

        QMetaObject::connectSlotsByName(ErrorDialog);
    } // setupUi

    void retranslateUi(QWidget *ErrorDialog)
    {
        ErrorDialog->setWindowTitle(QApplication::translate("ErrorDialog", "BetterDiscord Setup", nullptr));
        label->setText(QApplication::translate("ErrorDialog", "an error has occured and setup cannot continue.\n"
"Check the debug.log file for more information.", nullptr));
        lblErrorText->setText(QApplication::translate("ErrorDialog", "TextLabel", nullptr));
        btnOk->setText(QApplication::translate("ErrorDialog", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ErrorDialog: public Ui_ErrorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERRORDIALOG_H
