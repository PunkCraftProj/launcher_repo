/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QLabel *label;
    QLineEdit *ramLine;
    QPushButton *saveBtn;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName("Settings");
        Settings->resize(850, 470);
        label = new QLabel(Settings);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 30, 108, 16));
        label->setAlignment(Qt::AlignCenter);
        ramLine = new QLineEdit(Settings);
        ramLine->setObjectName("ramLine");
        ramLine->setGeometry(QRect(30, 60, 201, 24));
        saveBtn = new QPushButton(Settings);
        saveBtn->setObjectName("saveBtn");
        saveBtn->setGeometry(QRect(370, 430, 80, 24));

        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QCoreApplication::translate("Settings", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Settings", "\320\236\320\261\321\212\320\265\320\274 \320\277\320\260\320\274\321\217\321\202\320\270", nullptr));
        saveBtn->setText(QCoreApplication::translate("Settings", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
