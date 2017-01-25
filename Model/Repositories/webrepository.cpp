#include "webrepository.h"


WebRepository::WebRepository()
{
    _web = std::unique_ptr<Web>(new Web("http://www.mspaintadventures.com?s=6&p=005595"));
}

Web* WebRepository::getOpenedWeb()
{
    return _web.get();
}
