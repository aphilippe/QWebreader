#include "webrepository.h"
#include <QJsonObject>
#include <Utils/ioccontainer.h>
#include <Model/Repositories/settingsrepository.h>
#include <Model/Entities/settings.h>
#include <Model/DAO/webdao.h>

using namespace std;

WebRepository::WebRepository()
    : _web(nullptr),
      _settingsRepo(IOCContainer::instance().get<SettingsRepository>())
{}

std::vector<std::shared_ptr<Web>> WebRepository::getAll()
{
    if (_webs.empty())
    {
        WebDAO dao(_settingsRepo->get()->saveDirectory());
        std::vector<QByteArray> list = dao.get();

        foreach (QString json, list) {
            QJsonDocument document = QJsonDocument::fromJson(json.toUtf8());
            QJsonObject object = document.object();
            auto web = std::make_shared<Web>(
                        object["id"].toInt(),
                        object["url"].toString().toStdString());
            _webs.push_back(web);
        }
    }

    return _webs;
}

std::shared_ptr<Web> WebRepository::get(int index)
{
    getAll();
    auto it = find_if(_webs.begin(), _webs.end(), [index] (std::shared_ptr<Web>& w)->bool{
        return w->getId() == index;
    } );

    if(it == _webs.end())
    {
        // not cool
    }

    return *it;
}

void WebRepository::save(std::shared_ptr<Web> web)
{
    _web = web;

    QJsonObject object;
    object.insert("id", QJsonValue(web->getId()));
    object.insert("url", QJsonValue(QString::fromStdString(web->getUrl())));

    QJsonDocument document(object);

    WebDAO dao(_settingsRepo->get()->saveDirectory());
    dao.save(document.toJson());
}
