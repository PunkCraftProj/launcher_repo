#ifndef CONNECTION_H
#define CONNECTION_H

#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

inline bool connectToDataBase() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");

    db.setHostName("95.165.135.233");
    db.setDatabaseName("PunkCraft_DB");
    db.setUserName("postgres");
    db.setPassword("rootkit123123\\");
    db.setPort(5432);

    if (!db.open()) {
        qDebug() << "Failed to connect to PostgreSQL: " << db.lastError();
        return false;
    }

    qDebug() << "Connected!";
    return true;
}

#endif // CONNECTION_H
