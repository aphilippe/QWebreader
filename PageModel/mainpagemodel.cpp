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
    _web = WebRepository().getOpenedWeb();
    if (_web != nullptr) {
        std::string plop = _web->getUrl();
        return QString::fromStdString(_web->getUrl());

    }
}

void MainPageModel::onUrlUpdated(const QString &url)
{
    if (_web != nullptr) {
        //_web->setUrl(url.toStdString());
    }
}
