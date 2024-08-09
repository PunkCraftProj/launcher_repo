#ifndef JSON_H
#define JSON_H

#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QString>

QString loadJSON() {
    QFile file("settingsGame.json");
    if (!file.open(QIODevice::ReadOnly)) {
        return "";
    }
    QByteArray byteArray = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(byteArray);
    QJsonObject jsonObj = jsonDoc.object();

    return jsonObj["RAM"].toString();
}

void saveJSON(const QString &value) {
    QJsonObject jsonObj;
    jsonObj["RAM"] = value;

    QJsonDocument jsonDoc(jsonObj);
    QFile file("settingsGame.json");
    if (file.open(QIODevice::WriteOnly)) {
        file.write(jsonDoc.toJson());
        file.close();
    }
}

#endif // JSON_H
