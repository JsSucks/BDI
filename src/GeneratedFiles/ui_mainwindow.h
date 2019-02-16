/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "pathchooser.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QWidget *caption;
    QHBoxLayout *horizontalLayout;
    QLabel *icon;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *captionHelp;
    QPushButton *captionMin;
    QPushButton *captionClose;
    QStackedWidget *mainStack;
    QWidget *pageInitial;
    QVBoxLayout *verticalLayout_5;
    QWidget *content;
    QVBoxLayout *verticalLayout_3;
    QWidget *installedProducts;
    QVBoxLayout *verticalLayout_8;
    QWidget *prodcutsSplit;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QWidget *availableProducts;
    QVBoxLayout *verticalLayout_4;
    QWidget *footer;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_4;
    QPushButton *btnOptions;
    QPushButton *btnContinue;
    QWidget *pageOptions;
    QVBoxLayout *verticalLayout_6;
    QWidget *optionsContent;
    QVBoxLayout *verticalLayout_7;
    QCheckBox *commonInstall;
    PathChooser *installPathChooser;
    QCheckBox *commonData;
    PathChooser *dataPathChooser;
    QCheckBox *autoInject;
    QSpacerItem *verticalSpacer;
    QWidget *optionsFooter;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnCancelOptions;
    QPushButton *btnApplyOptions;
    QWidget *pageInstall;
    QVBoxLayout *verticalLayout_9;
    QWidget *installContent;
    QVBoxLayout *verticalLayout_10;
    QWidget *productsToRemoveHeader;
    QVBoxLayout *verticalLayout_11;
    QLabel *label;
    QWidget *productsToRemove;
    QVBoxLayout *verticalLayout_13;
    QWidget *productsToInstallHeader;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_4;
    QWidget *productsToInstall;
    QVBoxLayout *verticalLayout_14;
    QSpacerItem *verticalSpacer_2;
    QWidget *installFooter;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lblDone;
    QSpacerItem *horizontalSpacer_3;
    QLabel *spinner;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btnExit;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(850, 500);
        MainWindowClass->setStyleSheet(QLatin1String("QWidget {\n"
"	color: #aeaeae;\n"
"	font-family: \"Roboto\";\n"
"}\n"
"\n"
"#content,\n"
"#optionsContent,\n"
"#installContent {\n"
"	background: #2d2d30;\n"
"	background: rgb(30, 30, 38);\n"
"}\n"
"\n"
"#caption {\n"
"	background: #2d2d34;\n"
"	background: rgb(32, 32, 38);\n"
"}\n"
"\n"
"#footer,\n"
"#optionsFooter,\n"
"#installFooter {\n"
"	background: #202023;\n"
"	background: rgb(32, 32, 38);\n"
"	max-height: 50px;\n"
"	min-height: 50px;\n"
"}\n"
"\n"
"QCheckBox {\n"
"    spacing: 5px;\n"
"}\n"
"\n"
"QCheckBox:hover {\n"
"	color: #fff;\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"	image: none;\n"
"	background: #2a2a2a;\n"
"	border: 2px solid#2a2a2a;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:hover {\n"
"	background: #3a3a3a;\n"
"	border: 2px solid#3a3a3a;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"	background: rgb(62, 204, 156);\n"
"	border: 2px solid#3a3a3a;\n"
"}\n"
""));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(0, 0));
        centralWidget->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        caption = new QWidget(centralWidget);
        caption->setObjectName(QStringLiteral("caption"));
        caption->setMinimumSize(QSize(0, 100));
        caption->setMaximumSize(QSize(16777215, 100));
        horizontalLayout = new QHBoxLayout(caption);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(60, 0, 0, 0);
        icon = new QLabel(caption);
        icon->setObjectName(QStringLiteral("icon"));
        icon->setEnabled(true);
        icon->setMaximumSize(QSize(40, 40));
        icon->setStyleSheet(QStringLiteral(""));
        icon->setPixmap(QPixmap(QString::fromUtf8(":/images/logoPtb")));
        icon->setScaledContents(true);
        icon->setTextInteractionFlags(Qt::NoTextInteraction);

        horizontalLayout->addWidget(icon);

        label_2 = new QLabel(caption);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setEnabled(false);
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(30);
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(265, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        widget = new QWidget(caption);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QLatin1String("QPushButton {\n"
"	background: transparent;\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        captionHelp = new QPushButton(widget);
        captionHelp->setObjectName(QStringLiteral("captionHelp"));
        captionHelp->setMinimumSize(QSize(30, 24));
        captionHelp->setMaximumSize(QSize(30, 24));
        QFont font1;
        font1.setFamily(QStringLiteral("Roboto"));
        font1.setPointSize(10);
        captionHelp->setFont(font1);
        captionHelp->setStyleSheet(QLatin1String("QPushButton {\n"
"	border-image: url(:/images/qNormal);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	border-image: url(:/images/qHover);\n"
"}"));

        horizontalLayout_2->addWidget(captionHelp, 0, Qt::AlignRight|Qt::AlignTop);

        captionMin = new QPushButton(widget);
        captionMin->setObjectName(QStringLiteral("captionMin"));
        captionMin->setMinimumSize(QSize(30, 24));
        captionMin->setMaximumSize(QSize(30, 24));
        QFont font2;
        font2.setFamily(QStringLiteral("Roboto"));
        font2.setPointSize(13);
        captionMin->setFont(font2);
        captionMin->setStyleSheet(QLatin1String("QPushButton {\n"
"	border-image: url(:/images/mNormal);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	border-image: url(:/images/mHover);\n"
"}"));

        horizontalLayout_2->addWidget(captionMin, 0, Qt::AlignRight|Qt::AlignTop);

        captionClose = new QPushButton(widget);
        captionClose->setObjectName(QStringLiteral("captionClose"));
        captionClose->setMinimumSize(QSize(30, 24));
        captionClose->setMaximumSize(QSize(30, 24));
        QFont font3;
        font3.setFamily(QStringLiteral("Roboto"));
        font3.setPointSize(13);
        font3.setBold(false);
        font3.setWeight(50);
        captionClose->setFont(font3);
        captionClose->setStyleSheet(QLatin1String("QPushButton {\n"
"	border-image: url(:/images/xNormal);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	border-image: url(:/images/xHover);\n"
"}"));

        horizontalLayout_2->addWidget(captionClose, 0, Qt::AlignRight|Qt::AlignTop);


        horizontalLayout->addWidget(widget);


        verticalLayout->addWidget(caption);

        mainStack = new QStackedWidget(centralWidget);
        mainStack->setObjectName(QStringLiteral("mainStack"));
        pageInitial = new QWidget();
        pageInitial->setObjectName(QStringLiteral("pageInitial"));
        verticalLayout_5 = new QVBoxLayout(pageInitial);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        content = new QWidget(pageInitial);
        content->setObjectName(QStringLiteral("content"));
        verticalLayout_3 = new QVBoxLayout(content);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        installedProducts = new QWidget(content);
        installedProducts->setObjectName(QStringLiteral("installedProducts"));
        verticalLayout_8 = new QVBoxLayout(installedProducts);
        verticalLayout_8->setSpacing(20);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);

        verticalLayout_3->addWidget(installedProducts, 0, Qt::AlignTop);

        prodcutsSplit = new QWidget(content);
        prodcutsSplit->setObjectName(QStringLiteral("prodcutsSplit"));
        prodcutsSplit->setMaximumSize(QSize(16777215, 20));
        prodcutsSplit->setStyleSheet(QLatin1String("border-bottom: 1px solid rgb(62, 204, 156);\n"
"color: rgb(62, 204, 156);\n"
"margin-left: 75px;"));
        verticalLayout_2 = new QVBoxLayout(prodcutsSplit);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(prodcutsSplit);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setEnabled(true);
        QFont font4;
        font4.setFamily(QStringLiteral("Roboto"));
        font4.setPointSize(10);
        font4.setKerning(true);
        label_3->setFont(font4);
        label_3->setIndent(0);

        verticalLayout_2->addWidget(label_3);


        verticalLayout_3->addWidget(prodcutsSplit);

        availableProducts = new QWidget(content);
        availableProducts->setObjectName(QStringLiteral("availableProducts"));
        availableProducts->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_4 = new QVBoxLayout(availableProducts);
        verticalLayout_4->setSpacing(20);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);

        verticalLayout_3->addWidget(availableProducts, 0, Qt::AlignTop);


        verticalLayout_5->addWidget(content);

        footer = new QWidget(pageInitial);
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
        horizontalLayout_9 = new QHBoxLayout(footer);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalSpacer_5 = new QSpacerItem(325, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_5);

        pushButton_4 = new QPushButton(footer);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(20, 5));
        pushButton_4->setMaximumSize(QSize(5, 5));
        pushButton_4->setStyleSheet(QLatin1String("background: transparent;\n"
"border: 0;\n"
"color: transparent;\n"
"min-width: 0;"));

        horizontalLayout_9->addWidget(pushButton_4);

        btnOptions = new QPushButton(footer);
        btnOptions->setObjectName(QStringLiteral("btnOptions"));
        btnOptions->setStyleSheet(QStringLiteral(""));

        horizontalLayout_9->addWidget(btnOptions);

        btnContinue = new QPushButton(footer);
        btnContinue->setObjectName(QStringLiteral("btnContinue"));
        btnContinue->setStyleSheet(QStringLiteral(""));

        horizontalLayout_9->addWidget(btnContinue);


        verticalLayout_5->addWidget(footer);

        mainStack->addWidget(pageInitial);
        pageOptions = new QWidget();
        pageOptions->setObjectName(QStringLiteral("pageOptions"));
        verticalLayout_6 = new QVBoxLayout(pageOptions);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        optionsContent = new QWidget(pageOptions);
        optionsContent->setObjectName(QStringLiteral("optionsContent"));
        verticalLayout_7 = new QVBoxLayout(optionsContent);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        commonInstall = new QCheckBox(optionsContent);
        commonInstall->setObjectName(QStringLiteral("commonInstall"));
        commonInstall->setStyleSheet(QStringLiteral(""));
        commonInstall->setChecked(false);

        verticalLayout_7->addWidget(commonInstall);

        installPathChooser = new PathChooser(optionsContent);
        installPathChooser->setObjectName(QStringLiteral("installPathChooser"));
        installPathChooser->setMaximumSize(QSize(16777215, 90));

        verticalLayout_7->addWidget(installPathChooser);

        commonData = new QCheckBox(optionsContent);
        commonData->setObjectName(QStringLiteral("commonData"));

        verticalLayout_7->addWidget(commonData);

        dataPathChooser = new PathChooser(optionsContent);
        dataPathChooser->setObjectName(QStringLiteral("dataPathChooser"));
        dataPathChooser->setMaximumSize(QSize(16777215, 90));

        verticalLayout_7->addWidget(dataPathChooser);

        autoInject = new QCheckBox(optionsContent);
        autoInject->setObjectName(QStringLiteral("autoInject"));
        autoInject->setChecked(true);

        verticalLayout_7->addWidget(autoInject);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer);


        verticalLayout_6->addWidget(optionsContent);

        optionsFooter = new QWidget(pageOptions);
        optionsFooter->setObjectName(QStringLiteral("optionsFooter"));
        optionsFooter->setStyleSheet(QLatin1String("QPushButton {\n"
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
        horizontalLayout_3 = new QHBoxLayout(optionsFooter);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        btnCancelOptions = new QPushButton(optionsFooter);
        btnCancelOptions->setObjectName(QStringLiteral("btnCancelOptions"));

        horizontalLayout_3->addWidget(btnCancelOptions);

        btnApplyOptions = new QPushButton(optionsFooter);
        btnApplyOptions->setObjectName(QStringLiteral("btnApplyOptions"));
        btnApplyOptions->setMinimumSize(QSize(70, 28));

        horizontalLayout_3->addWidget(btnApplyOptions);


        verticalLayout_6->addWidget(optionsFooter);

        mainStack->addWidget(pageOptions);
        pageInstall = new QWidget();
        pageInstall->setObjectName(QStringLiteral("pageInstall"));
        verticalLayout_9 = new QVBoxLayout(pageInstall);
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        installContent = new QWidget(pageInstall);
        installContent->setObjectName(QStringLiteral("installContent"));
        verticalLayout_10 = new QVBoxLayout(installContent);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        productsToRemoveHeader = new QWidget(installContent);
        productsToRemoveHeader->setObjectName(QStringLiteral("productsToRemoveHeader"));
        productsToRemoveHeader->setMaximumSize(QSize(16777215, 20));
        productsToRemoveHeader->setStyleSheet(QLatin1String("border-bottom: 1px solid rgb(62, 204, 156);\n"
"color: rgb(62, 204, 156);\n"
"margin-left: 75px;"));
        verticalLayout_11 = new QVBoxLayout(productsToRemoveHeader);
        verticalLayout_11->setSpacing(0);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(productsToRemoveHeader);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font1);

        verticalLayout_11->addWidget(label);


        verticalLayout_10->addWidget(productsToRemoveHeader);

        productsToRemove = new QWidget(installContent);
        productsToRemove->setObjectName(QStringLiteral("productsToRemove"));
        productsToRemove->setStyleSheet(QStringLiteral(""));
        verticalLayout_13 = new QVBoxLayout(productsToRemove);
        verticalLayout_13->setSpacing(20);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        verticalLayout_13->setContentsMargins(0, 0, 0, 0);

        verticalLayout_10->addWidget(productsToRemove);

        productsToInstallHeader = new QWidget(installContent);
        productsToInstallHeader->setObjectName(QStringLiteral("productsToInstallHeader"));
        productsToInstallHeader->setMaximumSize(QSize(16777215, 20));
        productsToInstallHeader->setStyleSheet(QLatin1String("border-bottom: 1px solid rgb(62, 204, 156);\n"
"color: rgb(62, 204, 156);\n"
"margin-left: 75px;"));
        verticalLayout_12 = new QVBoxLayout(productsToInstallHeader);
        verticalLayout_12->setSpacing(0);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(productsToInstallHeader);
        label_4->setObjectName(QStringLiteral("label_4"));
        QFont font5;
        font5.setFamily(QStringLiteral("Roboto"));
        font5.setPointSize(10);
        font5.setBold(false);
        font5.setWeight(50);
        label_4->setFont(font5);

        verticalLayout_12->addWidget(label_4);


        verticalLayout_10->addWidget(productsToInstallHeader);

        productsToInstall = new QWidget(installContent);
        productsToInstall->setObjectName(QStringLiteral("productsToInstall"));
        productsToInstall->setStyleSheet(QStringLiteral(""));
        verticalLayout_14 = new QVBoxLayout(productsToInstall);
        verticalLayout_14->setSpacing(20);
        verticalLayout_14->setContentsMargins(11, 11, 11, 11);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        verticalLayout_14->setContentsMargins(0, 0, 0, 0);

        verticalLayout_10->addWidget(productsToInstall);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_2);


        verticalLayout_9->addWidget(installContent);

        installFooter = new QWidget(pageInstall);
        installFooter->setObjectName(QStringLiteral("installFooter"));
        installFooter->setStyleSheet(QLatin1String("QPushButton {\n"
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
        horizontalLayout_4 = new QHBoxLayout(installFooter);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        lblDone = new QLabel(installFooter);
        lblDone->setObjectName(QStringLiteral("lblDone"));

        horizontalLayout_4->addWidget(lblDone);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        spinner = new QLabel(installFooter);
        spinner->setObjectName(QStringLiteral("spinner"));
        spinner->setMinimumSize(QSize(400, 0));

        horizontalLayout_4->addWidget(spinner);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        btnExit = new QPushButton(installFooter);
        btnExit->setObjectName(QStringLiteral("btnExit"));
        btnExit->setEnabled(true);

        horizontalLayout_4->addWidget(btnExit);


        verticalLayout_9->addWidget(installFooter);

        mainStack->addWidget(pageInstall);

        verticalLayout->addWidget(mainStack);

        MainWindowClass->setCentralWidget(centralWidget);

        retranslateUi(MainWindowClass);
        QObject::connect(captionClose, SIGNAL(clicked()), MainWindowClass, SLOT(captionCloseClicked()));
        QObject::connect(captionHelp, SIGNAL(clicked()), MainWindowClass, SLOT(captionHelpClicked()));
        QObject::connect(captionMin, SIGNAL(clicked()), MainWindowClass, SLOT(captionMinClicked()));
        QObject::connect(btnOptions, SIGNAL(clicked()), MainWindowClass, SLOT(btnOptionsClicked()));
        QObject::connect(btnApplyOptions, SIGNAL(clicked()), MainWindowClass, SLOT(btnApplyOptionsClicked()));
        QObject::connect(btnCancelOptions, SIGNAL(clicked()), MainWindowClass, SLOT(btnCancelOptionsClicked()));
        QObject::connect(commonData, SIGNAL(toggled(bool)), MainWindowClass, SLOT(dataCheckboxCheckedChanged(bool)));
        QObject::connect(commonInstall, SIGNAL(toggled(bool)), MainWindowClass, SLOT(installCheckboxCheckedChanged(bool)));
        QObject::connect(btnContinue, SIGNAL(clicked()), MainWindowClass, SLOT(btnContinueClicked()));
        QObject::connect(btnExit, SIGNAL(clicked()), MainWindowClass, SLOT(captionCloseClicked()));

        mainStack->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", nullptr));
        icon->setText(QString());
        label_2->setText(QApplication::translate("MainWindowClass", "<html><head/><body><p><span style=\" color:#3ecc9c;\">Better</span><span style=\" color:#ffffff;\">Discord</span></p></body></html>", nullptr));
        captionHelp->setText(QString());
        captionMin->setText(QString());
        captionClose->setText(QString());
        label_3->setText(QApplication::translate("MainWindowClass", "Available Products", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindowClass", "Secret", nullptr));
        btnOptions->setText(QApplication::translate("MainWindowClass", "Options", nullptr));
        btnContinue->setText(QApplication::translate("MainWindowClass", "Continue", nullptr));
        commonInstall->setText(QApplication::translate("MainWindowClass", "Use common path for BetterDiscord core files", nullptr));
        commonData->setText(QApplication::translate("MainWindowClass", "Use common path for BetterDiscord content", nullptr));
        autoInject->setText(QApplication::translate("MainWindowClass", "Autoinjection routine(attempts to survive Discord updates but could break if Discord changes their structure)", nullptr));
        btnCancelOptions->setText(QApplication::translate("MainWindowClass", "Cancel", nullptr));
        btnApplyOptions->setText(QApplication::translate("MainWindowClass", "Apply", nullptr));
        label->setText(QApplication::translate("MainWindowClass", "Products to Remove", nullptr));
        label_4->setText(QApplication::translate("MainWindowClass", "Products to Install", nullptr));
        lblDone->setText(QApplication::translate("MainWindowClass", "All Done", nullptr));
        spinner->setText(QString());
        btnExit->setText(QApplication::translate("MainWindowClass", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
