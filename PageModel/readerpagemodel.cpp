#include "readerpagemodel.h"

#include <Model/Repositories/webrepository.h>

ReaderPageModel::ReaderPageModel(QObject *parent):
    QObject(parent), _web(nullptr)
{
}

ReaderPageModel::~ReaderPageModel()
{

}

QUrl ReaderPageModel::url() const
{
    if (_web == nullptr)
    {
        return QUrl();
    }

    return QUrl(QString::fromStdString(_web->getUrl()));
}

void ReaderPageModel::setWebId(int id)
{
    WebRepository repo;
    _web = repo.getOpenedWeb();
    emit urlChanged();
}

void ReaderPageModel::setUrl(const QUrl &url)
{
// TODO
}
