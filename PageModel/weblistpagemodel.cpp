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
    if (_webs.empty())
    {
        _webs = _webRepository->getAll();
    }
    QStringList list;
    for_each(_webs.begin(), _webs.end(), [&list](shared_ptr<Web> w) {
        list.append(QString::fromStdString(w->getName()));
    });


    return list;
}

void WebListPageModel::selectItem(int index)
{
    emit webIdChanged(_webs[index]->getId());
}
