/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AboutWindow
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QWidget *caption;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QToolButton *captionBtnX;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *lblVersion;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QLabel *licenses;

    void setupUi(QWidget *AboutWindow)
    {
        if (AboutWindow->objectName().isEmpty())
            AboutWindow->setObjectName(QStringLiteral("AboutWindow"));
        AboutWindow->resize(473, 442);
        AboutWindow->setStyleSheet(QLatin1String("QWidget {\n"
"	color: #aeaeae;\n"
"	font-family: \"Roboto\";\n"
"}\n"
"\n"
"#AboutWindow {\n"
"	background: rgb(62, 204, 156);\n"
"}\n"
"\n"
"#centralWidget {\n"
"	background: rgb(30, 30, 38);\n"
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
        verticalLayout = new QVBoxLayout(AboutWindow);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        centralWidget = new QWidget(AboutWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        caption = new QWidget(centralWidget);
        caption->setObjectName(QStringLiteral("caption"));
        caption->setMinimumSize(QSize(0, 24));
        horizontalLayout = new QHBoxLayout(caption);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(566, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        captionBtnX = new QToolButton(caption);
        captionBtnX->setObjectName(QStringLiteral("captionBtnX"));
        captionBtnX->setMinimumSize(QSize(30, 24));
        captionBtnX->setMaximumSize(QSize(30, 24));
        captionBtnX->setStyleSheet(QStringLiteral("background: transparent;"));
        captionBtnX->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(captionBtnX);


        verticalLayout_3->addWidget(caption);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(50, 50));
        label_2->setMaximumSize(QSize(50, 50));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/images/logoPtb")));
        label_2->setScaledContents(true);

        horizontalLayout_2->addWidget(label_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(16);
        label_3->setFont(font);

        verticalLayout_3->addWidget(label_3);

        lblVersion = new QLabel(centralWidget);
        lblVersion->setObjectName(QStringLiteral("lblVersion"));
        lblVersion->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(lblVersion);

        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setStyleSheet(QLatin1String("background: rgb(30, 30, 38);\n"
"font-family: \"Inconsolata\";"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 469, 322));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        licenses = new QLabel(scrollAreaWidgetContents);
        licenses->setObjectName(QStringLiteral("licenses"));
        licenses->setWordWrap(true);
        licenses->setOpenExternalLinks(true);

        verticalLayout_2->addWidget(licenses);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_3->addWidget(scrollArea);


        verticalLayout->addWidget(centralWidget);


        retranslateUi(AboutWindow);
        QObject::connect(captionBtnX, SIGNAL(clicked()), AboutWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(AboutWindow);
    } // setupUi

    void retranslateUi(QWidget *AboutWindow)
    {
        AboutWindow->setWindowTitle(QApplication::translate("AboutWindow", "Form", nullptr));
        captionBtnX->setText(QString());
        label_2->setText(QString());
        label_3->setText(QApplication::translate("AboutWindow", "<html><head/><body><p align=\"center\"><span style=\" color:#3ecc9c;\">Better</span><span style=\" color:#ffffff;\">Discord</span></p></body></html>", nullptr));
        lblVersion->setText(QApplication::translate("AboutWindow", "Version x.x.x", nullptr));
        licenses->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AboutWindow: public Ui_AboutWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
