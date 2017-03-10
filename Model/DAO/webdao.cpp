#include "webdao.h"
#include <QDebug>
#include <QFile>
#include <QDirIterator>

WebDAO::WebDAO(const QString& folder)
    : _folder(folder)
{
    qWarning() << folder;
}

std::vector<QByteArray> WebDAO::get()
{
    std::vector<QByteArray> list;
    QDirIterator it(this->folder(), QDir::Files | QDir::Readable);
    while(it.hasNext())
    {
        QFile file(it.next());
        file.open(QIODevice::ReadOnly);
        list.push_back(file.readAll());
    }
    return list;
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

void WebDAO::setFolder(const QString &folder)
{
    _folder = folder;
}
