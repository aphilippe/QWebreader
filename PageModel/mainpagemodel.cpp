#include "mainpagemodel.h"

#include <Model/Repositories/webrepository.h>

MainPageModel::MainPageModel(QObject *parent):
    QObject(parent), _webOpened(false)
{
}

MainPageModel::~MainPageModel()
{
}

void MainPageModel::setUrl(QString url)
{
    _url = url;
    _webOpened = true;
    emit isWebOpenedChanged();
}
