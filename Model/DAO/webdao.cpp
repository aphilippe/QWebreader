#include "webdao.h"
#include <QDebug>
#include <QFile>
#include <QCoreApplication>

WebDAO::WebDAO()
{

}

QJsonDocument WebDAO::get()
{

    QFile file(QCoreApplication::applicationDirPath().append("/save.json"));
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Can not open file";
    }


    QJsonDocument document = QJsonDocument::fromJson(file.readAll());
    return document;
}

void WebDAO::save(const QJsonDocument &document)
{
    qWarning() << QCoreApplication::applicationDirPath().append("/save.json");
    QFile file(QCoreApplication::applicationDirPath().append("/save.json"));
    if (!file.open(QIODevice::WriteOnly)) {
        qWarning() << "Can not open file";
    }

    file.write(document.toJson());

}
