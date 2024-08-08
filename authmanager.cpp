#include "authmanager.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkRequest>

AuthManager::AuthManager(QObject *parent) : QObject(parent) {
    networkManager = new QNetworkAccessManager(this);
}

void AuthManager::registerUser(const QString &login, const QString &password) {
    QUrl url("server");
    QNetworkRequest request(url);

    QJsonObject jsonObj;
    jsonObj["login"] = login;
    jsonObj["password"] = password;
    QJsonDocument jsonDoc(jsonObj);
    QByteArray data = jsonDoc.toJson();

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = networkManager->post(request, data);
    connect(reply, &QNetworkReply::finished, this, &AuthManager::onRegisterFinished);
}

void AuthManager::loginUser(const QString &login, const QString &password) {
    QUrl url("server");
    QNetworkRequest request(url);

    QJsonObject jsonObj;
    jsonObj["login"] = login;
    jsonObj["password"] = password;
    QJsonDocument jsonDoc(jsonObj);
    QByteArray data = jsonDoc.toJson();

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = networkManager->post(request, data);
    connect(reply, &QNetworkReply::finished, this, &AuthManager::onLoginFinished);
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
