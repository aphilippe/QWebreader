#include "mainpagemodel.h"

MainPageModel::MainPageModel(QObject *parent):
    QObject(parent)
{
}

MainPageModel::~MainPageModel()
{
}

bool MainPageModel::isWebOpened() const
{
    return false;
}


