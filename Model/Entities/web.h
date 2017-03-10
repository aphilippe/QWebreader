#ifndef WEB_H
#define WEB_H

#include <string>

class Web
{
public:
    Web(int _index, const std::string& url);

    std::string getUrl();
    void setUrl(const std::string& url);

    int getId() const;

private:
    int _id;
    std::string _url;
};

#endif // WEB_H
