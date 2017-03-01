#include "settingsrepository.h"
#include <QCoreApplication>

SettingsRepository::SettingsRepository()
{
    _cache = std::unique_ptr<Settings>(new Settings(QCoreApplication::applicationDirPath()));
}

Settings* SettingsRepository::get()
{
    return _cache.get();
}
