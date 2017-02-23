#include "webrepository.h"
#include <Model/DAO/webdao.h>
#include <QJsonObject>

WebRepository::WebRepository()
    : _web(nullptr)
{
    //_web = std::shared_ptr<Web>(new Web("http://www.mspaintadventures.com?s=6&p=005595"));
}

std::shared_ptr<Web> WebRepository::getOpenedWeb()
{
    if (_web == nullptr)
    {
        WebDAO dao;
        QJsonDocument document = dao.get();
        QJsonObject object = document.object();
        _web = std::make_shared<Web>(object["url"].toString().toStdString());
    }

    return _web;
}

void WebRepository::save(std::shared_ptr<Web> web)
{
    _web = web;
}
