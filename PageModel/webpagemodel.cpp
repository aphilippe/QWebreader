#include "webpagemodel.h"
#include <Utils/ioccontainer.h>

#include <Model/Repositories/webrepository.h>
#include <Model/Entities/web.h>

WebPageModel::WebPageModel(QObject *parent):
    QObject(parent), _web(nullptr), _webRepo(IOCContainer::instance().get<WebRepository>())
{
}

WebPageModel::~WebPageModel()
{
}

QString WebPageModel::url()
{
    if (_web != nullptr) {
        return QString::fromStdString(_web->getUrl());
    }

    return "";
}

void WebPageModel::onUrlUpdated(const QString &url)
{
    if (_web != nullptr) {
        _web->setUrl(url.toStdString());
        _webRepo->save(_web);

    }
}

void WebPageModel::onWebIdChanged(int webId)
{
    _web = _webRepo->get(webId);
    urlChanged();
}
