#ifndef WEB_H
#define WEB_H

#include <string>

class Web
{
public:
    Web(int _index, const std::string& url, const std::string& name);

    std::string getUrl();
    void setUrl(const std::string& url);

    int getId() const;
    std::string getName() const;

private:
    int _id;
    std::string _url;
    std::string _name;
};

#endif // WEB_H
