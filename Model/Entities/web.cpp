#include "web.h"

using namespace std;

Web::Web(const string& url)
    : _url(url)
{

}

std::string Web::getUrl()
{
    return _url;
}
