#include "webrepository.h"
#include <QJsonObject>
#include <Utils/ioccontainer.h>
#include <Model/Repositories/settingsrepository.h>
#include <Model/Entities/settings.h>

WebRepository::WebRepository()
    : _web(nullptr),
      _settingsRepo(IOCContainer::instance().get<SettingsRepository>())
{
    _dao = std::unique_ptr<WebDAO>(new WebDAO(_settingsRepo->get()->saveDirectory()));
}

std::shared_ptr<Web> WebRepository::getOpenedWeb()
{
    if (_web == nullptr)
    {
        QString json = _dao->get();
        QJsonDocument document = QJsonDocument::fromJson(json.toUtf8());
        QJsonObject object = document.object();
        _web = std::make_shared<Web>(object["url"].toString().toStdString());
    }

    return _web;
}

void WebRepository::save(std::shared_ptr<Web> web)
{
    _web = web;

    QJsonObject object;
    object.insert("url", QJsonValue(QString::fromStdString(web->getUrl())));

    QJsonDocument document(object);

    _dao->save(document.toJson());
}
