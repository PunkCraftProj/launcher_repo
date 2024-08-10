#include "registration.h"
#include "ui_registration.h"

#include <QLineEdit>
#include <QJsonObject>
#include <QtNetwork>

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

    QUrl url = QUrl(QString("http://95.165.135.233:5000/api/registration"));
    QNetworkRequest request(url);

    if (login.isEmpty() || password.isEmpty()) {
        qDebug() << "Login or password is empty!";
        return;
    }

    QJsonObject jsonObj;
    jsonObj["login"] = login;
    jsonObj["password"] = password;

    QJsonDocument jsonDoc(jsonObj);
    QByteArray data = jsonDoc.toJson();

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    reply = manager->post(request, data);
    connect(reply, SIGNAL(finished()), this, SLOT(getReplyFinished()));
    connect(reply, SIGNAL(finished()), this, SLOT(readyReadReply()));
}

void Registration::getReplyFinished() {
    reply->deleteLater();
}

void Registration::readyReadReply() {
    QString answer = QString::fromUtf8(reply->readAll());
    qDebug() << "Reply: " << answer;
}

