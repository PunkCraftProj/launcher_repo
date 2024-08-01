#include "mainwindow.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include "registration.h"

bool connectToDataBase(const QString& host, const QString& dbName, const QString& user, const QString& password, int port) {
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");

    db.setHostName(host);
    db.setDatabaseName(dbName);
    db.setUserName(user);
    db.setPassword(password);
    db.setPort(5432);

    if (!db.open()) {
        qDebug() << "Failed to connect to PostgreSQL: " << db.lastError();
        return false;
    }

    qDebug() << "Connected!";
    return true;
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString host = "95.165.135.233";
    QString dbName = "PunkCraft_DB";
    QString user = "postgres";
    QString password = "rootkit123123\\";
    QString port = "5432";

    if (!connectToDataBase(host, dbName, user, password, 5432)) {
        return -1;
    }


    MainWindow w;
    w.setFixedSize(1000, 600);
    w.show();



    return a.exec();
}
