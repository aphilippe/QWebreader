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

bool MainPageModel::isWebOpened()
{
    return this->_web != nullptr;
}

QUrl MainPageModel::url()
{
    return QUrl(QString::fromStdString(_web->getUrl()));
}

void MainPageModel::onNewUrlChosed(const QString &url)
{
    _web = std::make_shared<Web>(url.toStdString());
    emit isWebOpenedChanged();
}

void MainPageModel::onUrlUpdated(const QString &url)
{
    _web->setUrl(url.toStdString());
}
