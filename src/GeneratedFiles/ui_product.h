/********************************************************************************
** Form generated from reading UI file 'product.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCT_H
#define UI_PRODUCT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Product
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *mainContainer;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *icon;
    QWidget *infoWidget;
    QVBoxLayout *verticalLayout_5;
    QLabel *lblInfo;
    QSpacerItem *spacer;
    QStackedWidget *rsStack;
    QWidget *pageButtons;
    QHBoxLayout *horizontalLayout;
    QWidget *btnGroup;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btnInstall;
    QPushButton *btnSkip;
    QPushButton *btnUninstall;
    QWidget *pageStatus;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblStatus;

    void setupUi(QWidget *Product)
    {
        if (Product->objectName().isEmpty())
            Product->setObjectName(QStringLiteral("Product"));
        Product->resize(839, 68);
        Product->setStyleSheet(QLatin1String("color: #aeaeae;\n"
"font-family: \"Roboto\";\n"
"background: #2d2d30;\n"
"background: rgb(30, 30, 38);"));
        verticalLayout = new QVBoxLayout(Product);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        mainContainer = new QWidget(Product);
        mainContainer->setObjectName(QStringLiteral("mainContainer"));
        mainContainer->setMinimumSize(QSize(0, 50));
        mainContainer->setMaximumSize(QSize(16777215, 100));
        horizontalLayout_3 = new QHBoxLayout(mainContainer);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(mainContainer);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMaximumSize(QSize(50, 16777215));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        icon = new QLabel(widget);
        icon->setObjectName(QStringLiteral("icon"));
        icon->setMinimumSize(QSize(40, 40));
        icon->setMaximumSize(QSize(40, 40));
        icon->setStyleSheet(QStringLiteral(""));
        icon->setPixmap(QPixmap(QString::fromUtf8(":/images/zere")));
        icon->setScaledContents(true);

        verticalLayout_2->addWidget(icon, 0, Qt::AlignVCenter);


        horizontalLayout_3->addWidget(widget);

        infoWidget = new QWidget(mainContainer);
        infoWidget->setObjectName(QStringLiteral("infoWidget"));
        verticalLayout_5 = new QVBoxLayout(infoWidget);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        lblInfo = new QLabel(infoWidget);
        lblInfo->setObjectName(QStringLiteral("lblInfo"));

        verticalLayout_5->addWidget(lblInfo);


        horizontalLayout_3->addWidget(infoWidget);

        spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(spacer);

        rsStack = new QStackedWidget(mainContainer);
        rsStack->setObjectName(QStringLiteral("rsStack"));
        pageButtons = new QWidget();
        pageButtons->setObjectName(QStringLiteral("pageButtons"));
        horizontalLayout = new QHBoxLayout(pageButtons);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnGroup = new QWidget(pageButtons);
        btnGroup->setObjectName(QStringLiteral("btnGroup"));
        btnGroup->setEnabled(true);
        btnGroup->setStyleSheet(QLatin1String("QPushButton {\n"
"	background: transparent;\n"
"	border: 1px solid #30313a;\n"
"	color: #fff;\n"
"	padding: 7px 10px;\n"
"	min-width: 50px;\n"
"}\n"
"\n"
"QPushButton::disabled {\n"
"	color: #5e5e60;\n"
"}\n"
"\n"
"QPushButton::checked,\n"
"QPushButton::hover {\n"
"	background: rgb(62, 204, 156);\n"
"}\n"
"\n"
"QPushButton::checked::disabled {\n"
"	background: gray;\n"
"}"));
        horizontalLayout_4 = new QHBoxLayout(btnGroup);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        btnInstall = new QPushButton(btnGroup);
        btnInstall->setObjectName(QStringLiteral("btnInstall"));
        btnInstall->setStyleSheet(QStringLiteral("border-right: 0;"));
        btnInstall->setCheckable(true);

        horizontalLayout_4->addWidget(btnInstall);

        btnSkip = new QPushButton(btnGroup);
        btnSkip->setObjectName(QStringLiteral("btnSkip"));
        btnSkip->setEnabled(true);
        btnSkip->setStyleSheet(QLatin1String("border-left: 0;\n"
"border-right: 0;"));
        btnSkip->setCheckable(true);
        btnSkip->setChecked(true);

        horizontalLayout_4->addWidget(btnSkip);

        btnUninstall = new QPushButton(btnGroup);
        btnUninstall->setObjectName(QStringLiteral("btnUninstall"));
        btnUninstall->setEnabled(false);
        btnUninstall->setStyleSheet(QStringLiteral("border-left: 0;"));
        btnUninstall->setCheckable(true);
        btnUninstall->setFlat(false);

        horizontalLayout_4->addWidget(btnUninstall);


        horizontalLayout->addWidget(btnGroup);

        rsStack->addWidget(pageButtons);
        pageStatus = new QWidget();
        pageStatus->setObjectName(QStringLiteral("pageStatus"));
        horizontalLayout_2 = new QHBoxLayout(pageStatus);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lblStatus = new QLabel(pageStatus);
        lblStatus->setObjectName(QStringLiteral("lblStatus"));
        lblStatus->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(lblStatus);

        rsStack->addWidget(pageStatus);

        horizontalLayout_3->addWidget(rsStack);


        verticalLayout->addWidget(mainContainer);


        retranslateUi(Product);
        QObject::connect(btnInstall, SIGNAL(clicked(bool)), Product, SLOT(checkBtn(bool)));
        QObject::connect(btnSkip, SIGNAL(clicked(bool)), Product, SLOT(checkBtn(bool)));
        QObject::connect(btnUninstall, SIGNAL(clicked(bool)), Product, SLOT(checkBtn(bool)));

        rsStack->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Product);
    } // setupUi

    void retranslateUi(QWidget *Product)
    {
        icon->setText(QString());
        lblInfo->setText(QApplication::translate("Product", "<html><head/><body><p>BetterDiscord v2.0.0 for Discord</p></body></html>", nullptr));
        btnInstall->setText(QApplication::translate("Product", "Install", nullptr));
        btnSkip->setText(QApplication::translate("Product", "Skip", nullptr));
        btnUninstall->setText(QApplication::translate("Product", "Remove", nullptr));
        lblStatus->setText(QApplication::translate("Product", "Status", nullptr));
        Q_UNUSED(Product);
    } // retranslateUi

};

namespace Ui {
    class Product: public Ui_Product {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCT_H
