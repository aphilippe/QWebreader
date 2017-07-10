#include "weblistpagemodel.h"
#include <Utils/ioccontainer.h>
#include <Model/Repositories/webrepository.h>

using namespace std;

WebListPageModel::WebListPageModel(QObject *parent)
    :QObject(parent), _webRepository(IOCContainer::instance().get<WebRepository>())
{
}

WebListPageModel::~WebListPageModel()
{}

QStringList WebListPageModel::webs()
{
    if (_webs.isEmpty())
    {
        auto webs = _webRepository->getAll();
        for_each(webs.begin(), webs.end(), [this](shared_ptr<Web> w) {
           _webs.append(QString::number(w->getId()));
        });
    }

    return _webs;
}

void WebListPageModel::selectItem(QString item)
{
    emit webIdChanged(item.toInt());
}
