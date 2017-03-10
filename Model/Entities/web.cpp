#include "web.h"

using namespace std;

Web::Web(int id, const string& url)
    : _id(id), _url(url)
{

}

std::string Web::getUrl()
{
    return _url;
}

void Web::setUrl(const string &url)
{
    _url = url;
}

int Web::getId() const
{
    return _id;
}
