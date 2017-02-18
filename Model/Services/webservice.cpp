#include "webservice.h"
#include "Model/Entities/web.h"
#include <Model/Repositories/webrepository.h>

WebService::WebService()
{

}

Web *WebService::createWebWithUrl(const std::string &url)
{
    return new Web(url);
}
