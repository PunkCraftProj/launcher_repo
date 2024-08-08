#include "authmanager.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkRequest>
#include <QFile>
#include <QDebug>

AuthManager::AuthManager(QObject *parent) : QObject(parent) {
    networkManager = new QNetworkAccessManager(this);
}

void AuthManager::registerUser(const QString &login, const QString &password) {
    QUrl url("http://localhost:5000/api/endpoint");
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

    QNetworkReply*reply = networkManager->post(request, data);

    qDebug() << "Request Data: " << data;

    QObject::connect(reply, &QNetworkReply::finished, [reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray response_data = reply->readAll();
            qDebug() << "Response: " << response_data;
        } else {
            qDebug() << "Error: " << reply->errorString();
            qDebug() << "HTTP Status code:" << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        }
        reply->deleteLater();
    });
}

void AuthManager::loginUser(const QString &login, const QString &password) {
    QUrl url("http://localhost:5000/api/endpoint");
    QNetworkRequest request(url);

    QJsonObject jsonObj;
    jsonObj["login"] = login;
    jsonObj["password"] = password;
    QJsonDocument jsonDoc(jsonObj);
    QByteArray data = jsonDoc.toJson();

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = networkManager->post(request, data);

}

void AuthManager::onRegisterFinished(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        emit registrationSuccessful();
    } else {
        emit registrationFailed(reply->errorString());
    }
    reply->deleteLater();
}

void AuthManager::onLoginFinished(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        emit loginSuccessful();
    } else {
        emit loginFailed(reply->errorString());
    }
    reply->deleteLater();
}
