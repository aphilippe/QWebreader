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
        return "";
    }

    return file.readAll();
}
