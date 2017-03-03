#include "webdao.h"
#include <QDebug>
#include <QFile>

WebDAO::WebDAO(const QString& folder)
    : _folder(folder)
{
    qWarning() << folder;
}

QByteArray WebDAO::get()
{

    QFile file(this->folder().append("/save.json"));
    if (!file.open(QIODevice::ReadOnly)) {
        return "";
    }

    return file.readAll();
}

void WebDAO::save(const QByteArray& document)
{
    QFile file(this->folder().append("/save.json"));
    if (!file.open(QIODevice::WriteOnly)) {
        qWarning() << "Can not open file";
    }

    file.write(document);
}

QString WebDAO::folder() const
{
    return _folder;
}
