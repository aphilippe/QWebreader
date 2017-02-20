#ifndef WEB_H
#define WEB_H

#include <string>

class Web
{
public:
    Web(const std::string& url);

    std::string getUrl();
    void setUrl(const std::string& url);

private:
    std::string _url;
};

#endif // WEB_H
