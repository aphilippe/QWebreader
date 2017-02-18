#include "mainpagemodel.h"

#include <Model/Repositories/webrepository.h>
#include <Model/Entities/web.h>
#include <Model/Services/webservice.h>

MainPageModel::MainPageModel(QObject *parent):
    QObject(parent), _web(nullptr)
{
}

MainPageModel::~MainPageModel()
{
}

int MainPageModel::getOpenedWebId()
{
    return 10;
}

bool MainPageModel::isWebOpened()
{
    return this->_web != nullptr;
}

void MainPageModel::onUrlChanged(const QString &url)
{
    WebService service;
    _web = service.createWebWithUrl(url.toStdString());
    emit isWebOpenedChanged();
}
