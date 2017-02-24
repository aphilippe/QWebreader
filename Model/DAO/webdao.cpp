#include "webdao.h"

#include <QFile>
#include <QDebug>

WebDAO::WebDAO()
{

}

QJsonDocument WebDAO::get()
{
    QFile file("");
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Can not open file";
    }


    QJsonDocument document = QJsonDocument::fromJson(file.readAll());
    return document;
}

void WebDAO::save(const QJsonDocument &document)
{
    QFile file("");
    if (!file.open(QIODevice::WriteOnly)) {
        qWarning() << "Can not open file";
    }

    file.write(document.toJson());

}
