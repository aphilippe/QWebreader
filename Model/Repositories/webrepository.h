#ifndef WEBREPOSITORY_H
#define WEBREPOSITORY_H

#include <memory>

#include <Model/Entities/web.h>
#include <vector>

class SettingsRepository;

class WebRepository
{
public:
    WebRepository();

    std::vector<std::shared_ptr<Web>> getAll();
    std::shared_ptr<Web> get(int index);
    void save(std::shared_ptr<Web> web);

private:
    std::shared_ptr<Web> _web;
    std::shared_ptr<SettingsRepository> _settingsRepo;
    std::vector<std::shared_ptr<Web>> _webs;
};

#endif // WEBREPOSITORY_H
