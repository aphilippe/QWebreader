#ifndef WEBREPOSITORY_H
#define WEBREPOSITORY_H

#include <memory>

#include <Model/Entities/web.h>

class WebRepository
{
public:
    WebRepository();

    Web* getOpenedWeb();

private:
    std::unique_ptr<Web> _web;
};

#endif // WEBREPOSITORY_H
