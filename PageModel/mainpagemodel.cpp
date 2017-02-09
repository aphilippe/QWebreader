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
    _web = new Web(url.toStdString());
    emit isWebOpenedChanged();
}
