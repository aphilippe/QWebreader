#include "webdao.h"
#include <QDebug>
#include <QFile>

WebDAO::WebDAO(const QString& folder)
    : _folder(folder)
{
    qWarning() << folder;
}

QJsonDocument WebDAO::get()
{

    QFile file(this->folder().append("/save.json"));
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Can not open file";
    }


    QJsonDocument document = QJsonDocument::fromJson(file.readAll());
    return document;
}

void WebDAO::save(const QJsonDocument &document)
{
    QFile file(this->folder().append("/save.json"));
    if (!file.open(QIODevice::WriteOnly)) {
        qWarning() << "Can not open file";
    }

    file.write(document.toJson());
}

QString WebDAO::folder() const
{
    return _folder;
}
