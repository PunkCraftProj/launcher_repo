/********************************************************************************
** Form generated from reading UI file 'registration.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATION_H
#define UI_REGISTRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Registration
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLineEdit *loginLine;
    QLineEdit *passLine;
    QPushButton *registrationBtn;

    void setupUi(QDialog *Registration)
    {
        if (Registration->objectName().isEmpty())
            Registration->setObjectName("Registration");
        Registration->resize(429, 427);
        horizontalLayout = new QHBoxLayout(Registration);
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        loginLine = new QLineEdit(Registration);
        loginLine->setObjectName("loginLine");
        loginLine->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(loginLine);

        passLine = new QLineEdit(Registration);
        passLine->setObjectName("passLine");
        passLine->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(passLine);

        registrationBtn = new QPushButton(Registration);
        registrationBtn->setObjectName("registrationBtn");

        verticalLayout->addWidget(registrationBtn);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(Registration);

        QMetaObject::connectSlotsByName(Registration);
    } // setupUi

    void retranslateUi(QDialog *Registration)
    {
        Registration->setWindowTitle(QCoreApplication::translate("Registration", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        loginLine->setPlaceholderText(QCoreApplication::translate("Registration", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        passLine->setPlaceholderText(QCoreApplication::translate("Registration", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        registrationBtn->setText(QCoreApplication::translate("Registration", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Registration: public Ui_Registration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATION_H
