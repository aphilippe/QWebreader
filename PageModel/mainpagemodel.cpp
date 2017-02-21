#include "mainpagemodel.h"

#include <Model/Repositories/webrepository.h>
#include <Model/Entities/web.h>

MainPageModel::MainPageModel(QObject *parent):
    QObject(parent), _web(nullptr)
{
}

MainPageModel::~MainPageModel()
{
}

QString MainPageModel::url()
{
    WebRepository repo;
    _web = repo.getOpenedWeb();
    if (_web != nullptr) {
        return QString::fromStdString(_web->getUrl());
    }

    return "";
}

void MainPageModel::onUrlUpdated(const QString &url)
{
    if (_web != nullptr) {
        //_web->setUrl(url.toStdString());
    }
}
