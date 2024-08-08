#ifndef AUTHMANAGER_H
#define AUTHMANAGER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class AuthManager : public QObject {
    Q_OBJECT
public:
    explicit AuthManager(QObject *parent = nullptr);
    void registerUser(const QString &login, const QString &password);
    void loginUser(const QString &login, const QString &password);

signals:
    void registrationSuccessful();
    void registrationFailed(const QString &reason);
    void loginSuccessful();
    void loginFailed(const QString &reason);

private slots:
    void onRegisterFinished(QNetworkReply *reply);
    void onLoginFinished(QNetworkReply *reply);

private:
    QNetworkAccessManager *networkManager;
};

#endif // AUTHMANAGER_H
