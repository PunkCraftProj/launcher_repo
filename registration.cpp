#include "registration.h"
#include "ui_registration.h"

#include <QLineEdit>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QCryptographicHash>

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

void Registration::on_registrationBtn_clicked()
{
    QString login = this->ui->loginLine->text();
    QString password = this->ui->passLine->text();
    // QString hashedPassword = QString(QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex());

    QSqlQuery query;
    query.prepare("INSERT INTO users VALUES (:login, :password)");
    query.bindValue(":login", login);
    query.bindValue(":password", password);

    if (!query.exec()) {
        qDebug() << "Failed to register: " << query.lastError();
    }

    qDebug() << "User registered successfully!";
}

