#include "webrepository.h"


WebRepository *WebRepository::instance()
{
    static std::unique_ptr<WebRepository> _instance = nullptr;
    if (_instance == nullptr)
    {
        _instance = std::unique_ptr<WebRepository>(new WebRepository());
    }

    return _instance.get();
}

WebRepository::WebRepository()
{
    _web = std::unique_ptr<Web>(new Web("http://www.mspaintadventures.com?s=6&p=005595"));
    //_web = nullptr;
}

Web* WebRepository::getOpenedWeb()
{
    return _web.get();
}
