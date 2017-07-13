#include "web.h"

using namespace std;

Web::Web(int id, const string& url, const string& name)
    : _id(id), _url(url), _name(name)
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

std::string Web::getName() const
{
    return _name;
}
