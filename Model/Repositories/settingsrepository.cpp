#include "settingsrepository.h"
#include <QCoreApplication>
#include <Model/DAO/settingsdao.h>

#include <QJsonDocument>
#include <QJsonObject>

SettingsRepository::SettingsRepository()
    : _cache(nullptr)
{
}

Settings* SettingsRepository::get()
{
    if (_cache == nullptr) {
        SettingsDAO dao;
        try
        {
            QString json = dao.get();
            // TODO put it in an other class
            QJsonDocument doc = QJsonDocument::fromJson(json.toUtf8());
            QJsonObject object = doc.object();
            _cache = std::unique_ptr<Settings>(new Settings(object["save_directory"].toString()));
        }
        catch(NoFileSettingsDAOException &e)
        {
            _cache = std::unique_ptr<Settings>(new Settings(""));

            QJsonObject object;
            object.insert("save_directory", QJsonValue(_cache->saveDirectory()));
            QJsonDocument document(object);

            dao.save(document.toJson());
        }
    }
    return _cache.get();
}
