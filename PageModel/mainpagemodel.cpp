#include "mainpagemodel.h"

#include <Model/Repositories/webrepository.h>

MainPageModel::MainPageModel(QObject *parent):
    QObject(parent)
{
}

MainPageModel::~MainPageModel()
{
}

bool MainPageModel::isWebOpened() const
{
    WebRepository repo;
    return repo.getOpenedWeb() != nullptr;
}


