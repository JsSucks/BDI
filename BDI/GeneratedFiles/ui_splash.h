/********************************************************************************
** Form generated from reading UI file 'splash.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPLASH_H
#define UI_SPLASH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "pbar.h"

QT_BEGIN_NAMESPACE

class Ui_Splash
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QWidget *caption;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QToolButton *captionBtnX;
    QStackedWidget *mainStack;
    QWidget *page;
    QVBoxLayout *verticalLayout_4;
    QWidget *content;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lblLogo;
    QLabel *lblLogoText_2;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QLabel *label_2;
    QWidget *footer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *footerSpacer;
    QPushButton *btnContinue;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_6;
    QWidget *content_2;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lblLogo_2;
    QLabel *lblLogoText_3;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *systemChecksLayout;
    QLabel *label_3;
    Pbar *progressBar;
    QVBoxLayout *remoteChecksLayout;
    QLabel *label_4;
    Pbar *progressBar_2;

    void setupUi(QWidget *Splash)
    {
        if (Splash->objectName().isEmpty())
            Splash->setObjectName(QStringLiteral("Splash"));
        Splash->resize(410, 235);
        Splash->setStyleSheet(QLatin1String("QWidget {\n"
"	font-family: \"Roboto\";\n"
"	color: #AEAEAE;\n"
"}\n"
"\n"
"#Splash {\n"
"	background: rgb(62, 204, 156);\n"
"}\n"
"\n"
"#centralWidget, #page, #page_2 {\n"
"	background: rgb(30, 30, 38);\n"
"}\n"
"\n"
"#captionBtnX {\n"
"	border-image: url(:/images/xNormal);\n"
"}\n"
"\n"
"#captionBtnX:hover {\n"
"	border-image: url(:/images/xHover);\n"
"}"));
        verticalLayout = new QVBoxLayout(Splash);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        centralWidget = new QWidget(Splash);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        caption = new QWidget(centralWidget);
        caption->setObjectName(QStringLiteral("caption"));
        caption->setMaximumSize(QSize(16777215, 24));
        horizontalLayout = new QHBoxLayout(caption);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        captionBtnX = new QToolButton(caption);
        captionBtnX->setObjectName(QStringLiteral("captionBtnX"));
        captionBtnX->setMinimumSize(QSize(30, 24));
        captionBtnX->setMaximumSize(QSize(30, 24));
        captionBtnX->setStyleSheet(QStringLiteral("background: transparent;"));
        captionBtnX->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(captionBtnX);


        verticalLayout_3->addWidget(caption);

        mainStack = new QStackedWidget(centralWidget);
        mainStack->setObjectName(QStringLiteral("mainStack"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        verticalLayout_4 = new QVBoxLayout(page);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        content = new QWidget(page);
        content->setObjectName(QStringLiteral("content"));
        verticalLayout_2 = new QVBoxLayout(content);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lblLogo = new QLabel(content);
        lblLogo->setObjectName(QStringLiteral("lblLogo"));
        lblLogo->setMinimumSize(QSize(50, 50));
        lblLogo->setMaximumSize(QSize(50, 50));
        lblLogo->setPixmap(QPixmap(QString::fromUtf8(":/images/logoPtb")));
        lblLogo->setScaledContents(true);
        lblLogo->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(lblLogo);


        verticalLayout_2->addLayout(horizontalLayout_3);

        lblLogoText_2 = new QLabel(content);
        lblLogoText_2->setObjectName(QStringLiteral("lblLogoText_2"));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(16);
        lblLogoText_2->setFont(font);

        verticalLayout_2->addWidget(lblLogoText_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        label = new QLabel(content);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 15));
        label->setMaximumSize(QSize(16777215, 15));
        QFont font1;
        font1.setFamily(QStringLiteral("Roboto"));
        font1.setPointSize(8);
        label->setFont(font1);
        label->setStyleSheet(QStringLiteral(""));
        label->setMargin(0);
        label->setOpenExternalLinks(true);

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(content);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(0, 15));
        label_2->setMaximumSize(QSize(16777215, 15));
        label_2->setLineWidth(1);
        label_2->setMargin(0);
        label_2->setOpenExternalLinks(true);

        verticalLayout_2->addWidget(label_2);


        verticalLayout_4->addWidget(content);

        footer = new QWidget(page);
        footer->setObjectName(QStringLiteral("footer"));
        footer->setMinimumSize(QSize(0, 0));
        horizontalLayout_2 = new QHBoxLayout(footer);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        footerSpacer = new QSpacerItem(405, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(footerSpacer);

        btnContinue = new QPushButton(footer);
        btnContinue->setObjectName(QStringLiteral("btnContinue"));
        btnContinue->setStyleSheet(QLatin1String("QPushButton {\n"
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

        horizontalLayout_2->addWidget(btnContinue);


        verticalLayout_4->addWidget(footer);

        mainStack->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        verticalLayout_6 = new QVBoxLayout(page_2);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        content_2 = new QWidget(page_2);
        content_2->setObjectName(QStringLiteral("content_2"));
        verticalLayout_5 = new QVBoxLayout(content_2);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        lblLogo_2 = new QLabel(content_2);
        lblLogo_2->setObjectName(QStringLiteral("lblLogo_2"));
        lblLogo_2->setMinimumSize(QSize(50, 50));
        lblLogo_2->setMaximumSize(QSize(50, 50));
        lblLogo_2->setPixmap(QPixmap(QString::fromUtf8(":/images/logoPtb")));
        lblLogo_2->setScaledContents(true);
        lblLogo_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(lblLogo_2);


        verticalLayout_5->addLayout(horizontalLayout_4);

        lblLogoText_3 = new QLabel(content_2);
        lblLogoText_3->setObjectName(QStringLiteral("lblLogoText_3"));
        lblLogoText_3->setFont(font);

        verticalLayout_5->addWidget(lblLogoText_3);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_3);

        systemChecksLayout = new QVBoxLayout();
        systemChecksLayout->setObjectName(QStringLiteral("systemChecksLayout"));
        label_3 = new QLabel(content_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        systemChecksLayout->addWidget(label_3);

        progressBar = new Pbar(content_2);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setMaximumSize(QSize(16777215, 8));
        progressBar->setValue(24);

        systemChecksLayout->addWidget(progressBar);


        verticalLayout_5->addLayout(systemChecksLayout);

        remoteChecksLayout = new QVBoxLayout();
        remoteChecksLayout->setObjectName(QStringLiteral("remoteChecksLayout"));
        label_4 = new QLabel(content_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        remoteChecksLayout->addWidget(label_4);

        progressBar_2 = new Pbar(content_2);
        progressBar_2->setObjectName(QStringLiteral("progressBar_2"));
        progressBar_2->setMaximumSize(QSize(16777215, 8));
        progressBar_2->setValue(24);

        remoteChecksLayout->addWidget(progressBar_2);


        verticalLayout_5->addLayout(remoteChecksLayout);


        verticalLayout_6->addWidget(content_2);

        mainStack->addWidget(page_2);

        verticalLayout_3->addWidget(mainStack);


        verticalLayout->addWidget(centralWidget);


        retranslateUi(Splash);
        QObject::connect(captionBtnX, SIGNAL(clicked()), Splash, SLOT(attemptClose()));
        QObject::connect(btnContinue, SIGNAL(clicked()), Splash, SLOT(btnContinueClicked()));

        mainStack->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Splash);
    } // setupUi

    void retranslateUi(QWidget *Splash)
    {
        Splash->setWindowTitle(QApplication::translate("Splash", "Form", nullptr));
        captionBtnX->setText(QString());
        lblLogo->setText(QString());
        lblLogoText_2->setText(QApplication::translate("Splash", "<html><head/><body><p align=\"center\"><span style=\" color:#3ecc9c;\">Better</span><span style=\" color:#ffffff;\">Discord</span></p></body></html>", nullptr));
        label->setText(QApplication::translate("Splash", "<html><head/><body><p align=\"center\">To learn more about privacy, see the BetterDiscord <a href=\"https://betterdiscord.net/fwd?id=pp\"><span style=\" text-decoration: none; color:#3ecc9c;\">Privacy Policy</span></a></p></body></html>", nullptr));
        label_2->setText(QApplication::translate("Splash", "<html><head/><body><p align=\"center\">By continuing you agree to the BetterDiscord <a href=\"https://betterdiscord.net/fwd?id=slt\"><span style=\"text-decoration: none; color:#3ecc9c;\">Software License Terms</span></a></p></body></html>", nullptr));
        btnContinue->setText(QApplication::translate("Splash", "Continue", nullptr));
        lblLogo_2->setText(QString());
        lblLogoText_3->setText(QApplication::translate("Splash", "<html><head/><body><p align=\"center\"><span style=\" color:#3ecc9c;\">Better</span><span style=\" color:#ffffff;\">Discord</span></p></body></html>", nullptr));
        label_3->setText(QApplication::translate("Splash", "System Checks", nullptr));
        label_4->setText(QApplication::translate("Splash", "Remote Resources", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Splash: public Ui_Splash {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPLASH_H
