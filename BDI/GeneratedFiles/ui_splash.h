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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

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
    QWidget *content;
    QVBoxLayout *verticalLayout_2;

    void setupUi(QWidget *Splash)
    {
        if (Splash->objectName().isEmpty())
            Splash->setObjectName(QStringLiteral("Splash"));
        Splash->resize(426, 237);
        Splash->setStyleSheet(QLatin1String("#Splash {\n"
"	background: rgb(62, 204, 156);\n"
"}\n"
"\n"
"#centralWidget {\n"
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

        content = new QWidget(centralWidget);
        content->setObjectName(QStringLiteral("content"));
        verticalLayout_2 = new QVBoxLayout(content);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));

        verticalLayout_3->addWidget(content);


        verticalLayout->addWidget(centralWidget);


        retranslateUi(Splash);
        QObject::connect(captionBtnX, SIGNAL(clicked()), Splash, SLOT(attemptClose()));

        QMetaObject::connectSlotsByName(Splash);
    } // setupUi

    void retranslateUi(QWidget *Splash)
    {
        Splash->setWindowTitle(QApplication::translate("Splash", "Form", nullptr));
        captionBtnX->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Splash: public Ui_Splash {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPLASH_H
