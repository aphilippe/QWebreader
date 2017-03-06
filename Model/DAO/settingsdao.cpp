#include "settingsdao.h"

#include <QCoreApplication>
#include <QFile>

SettingsDAO::SettingsDAO()
{

}

QByteArray SettingsDAO::get()
{
    QFile file(QCoreApplication::applicationDirPath().append("/settings.json"));
    if (!file.open(QIODevice::ReadOnly)) {
        throw NoFileSettingsDAOException{};
    }

    return file.readAll();
}

void SettingsDAO::save(const QByteArray &data)
{
    QFile file(QCoreApplication::applicationDirPath().append("/settings.json"));
    if(!file.open(QIODevice::WriteOnly))
    {
        // Do nothing
    }

    file.write(data);
}
