#include "mainpagemodel.h"
#include <Utils/ioccontainer.h>

#include <Model/Repositories/webrepository.h>
#include <Model/Entities/web.h>

MainPageModel::MainPageModel(QObject *parent):
    QObject(parent), _web(nullptr), _webRepo(IOCContainer::instance().get<WebRepository>())
{
}

MainPageModel::~MainPageModel()
{
}

QString MainPageModel::url()
{
    _web = _webRepo->getOpenedWeb();

    if (_web != nullptr) {
        return QString::fromStdString(_web->getUrl());
    }

    return "";
}

void MainPageModel::onUrlUpdated(const QString &url)
{
    if (_web != nullptr) {
        _web->setUrl(url.toStdString());
        _webRepo->save(_web);

    }
}
