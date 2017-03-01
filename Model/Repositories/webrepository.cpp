#include "webrepository.h"
#include <QJsonObject>
#include <QTextStream>
#include <Utils/ioccontainer.h>
#include <Model/Repositories/settingsrepository.h>
#include <Model/Entities/settings.h>

WebRepository::WebRepository()
    : _web(nullptr),
      _settingsRepo(IOCContainer::instance().get<SettingsRepository>())
{
    //_web = std::shared_ptr<Web>(new Web("http://www.mspaintadventures.com?s=6&p=005595"));
    _dao = std::unique_ptr<WebDAO>(new WebDAO(_settingsRepo->get()->saveDirectory()));
}

std::shared_ptr<Web> WebRepository::getOpenedWeb()
{
    if (_web == nullptr)
    {
        QJsonDocument document = _dao->get();
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

    _dao->save(document);
}
