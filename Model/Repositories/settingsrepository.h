#ifndef SETTINGSREPOSITORY_H
#define SETTINGSREPOSITORY_H

#include <memory>
#include <Model/Entities/settings.h>

class SettingsRepository
{
public:
    SettingsRepository();

    Settings* get();

private:
    std::unique_ptr<Settings> _cache;
};

#endif // SETTINGSREPOSITORY_H
