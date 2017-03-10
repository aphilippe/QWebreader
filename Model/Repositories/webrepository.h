#ifndef WEBREPOSITORY_H
#define WEBREPOSITORY_H

#include <memory>

#include <Model/Entities/web.h>

class SettingsRepository;

class WebRepository
{
public:
    WebRepository();

    std::shared_ptr<Web> getOpenedWeb();
    void save(std::shared_ptr<Web> web);

private:
    std::shared_ptr<Web> _web;
    std::shared_ptr<SettingsRepository> _settingsRepo;
};

#endif // WEBREPOSITORY_H
