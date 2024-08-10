/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *loginLineLog;
    QLineEdit *passLineLog;
    QCheckBox *dontLeaveCheck;
    QLabel *infoLabel;
    QPushButton *loginBtn;
    QLabel *label;
    QPushButton *regBtn;
    QPushButton *startBtn;
    QPushButton *settingsBtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1000, 571);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(50, 110, 201, 241));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        loginLineLog = new QLineEdit(verticalLayoutWidget);
        loginLineLog->setObjectName("loginLineLog");
        loginLineLog->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(loginLineLog);

        passLineLog = new QLineEdit(verticalLayoutWidget);
        passLineLog->setObjectName("passLineLog");
        passLineLog->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(passLineLog);

        dontLeaveCheck = new QCheckBox(verticalLayoutWidget);
        dontLeaveCheck->setObjectName("dontLeaveCheck");

        verticalLayout->addWidget(dontLeaveCheck);

        infoLabel = new QLabel(verticalLayoutWidget);
        infoLabel->setObjectName("infoLabel");
        infoLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(infoLabel);

        loginBtn = new QPushButton(verticalLayoutWidget);
        loginBtn->setObjectName("loginBtn");

        verticalLayout->addWidget(loginBtn);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        regBtn = new QPushButton(verticalLayoutWidget);
        regBtn->setObjectName("regBtn");

        verticalLayout->addWidget(regBtn);

        startBtn = new QPushButton(centralwidget);
        startBtn->setObjectName("startBtn");
        startBtn->setGeometry(QRect(450, 500, 80, 24));
        settingsBtn = new QPushButton(centralwidget);
        settingsBtn->setObjectName("settingsBtn");
        settingsBtn->setGeometry(QRect(10, 10, 80, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1000, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "PunkLauncher", nullptr));
        loginLineLog->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        passLineLog->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        dontLeaveCheck->setText(QCoreApplication::translate("MainWindow", "\320\235\320\265 \320\262\321\213\321\205\320\276\320\264\320\270\321\202\321\214 \321\201 \320\260\320\272\320\272\320\260\321\203\320\275\321\202\320\260", nullptr));
        infoLabel->setText(QString());
        loginBtn->setText(QCoreApplication::translate("MainWindow", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\235\320\265\321\202 \320\260\320\272\320\272\320\260\321\203\320\275\321\202\320\260? \320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\321\203\320\271\321\201\321\217", nullptr));
        regBtn->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        startBtn->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\321\203\321\201\321\202\320\270\321\202\321\214", nullptr));
        settingsBtn->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
