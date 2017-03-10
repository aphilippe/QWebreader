#include "webrepository.h"
#include <QJsonObject>
#include <Utils/ioccontainer.h>
#include <Model/Repositories/settingsrepository.h>
#include <Model/Entities/settings.h>
#include <Model/DAO/webdao.h>

WebRepository::WebRepository()
    : _web(nullptr),
      _settingsRepo(IOCContainer::instance().get<SettingsRepository>())
{}

std::shared_ptr<Web> WebRepository::getOpenedWeb()
{
    if (_web == nullptr)
    {
        WebDAO dao(_settingsRepo->get()->saveDirectory());
        QString json = dao.get();
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

    WebDAO dao(_settingsRepo->get()->saveDirectory());
    dao.save(document.toJson());
}
