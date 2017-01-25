#include "readerpagemodel.h"

#include <Model/Repositories/webrepository.h>

ReaderPageModel::ReaderPageModel(QObject *parent):
    QObject(parent)
{
}

ReaderPageModel::~ReaderPageModel()
{

}

QUrl ReaderPageModel::getOpenedWeb() const
{
    WebRepository repo;
    return QUrl(QString::fromStdString(repo.getOpenedWeb()->getUrl()));
}
