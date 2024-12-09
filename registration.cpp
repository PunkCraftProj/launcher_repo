#include "registration.h"
#include "ui_registration.h"

#include <QLineEdit>

Registration::Registration(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Registration)
{
    ui->setupUi(this);
    ui->passLine->setEchoMode(QLineEdit::Password);
    setFixedSize(300, 300);
}

Registration::~Registration()
{
    delete ui;
}
