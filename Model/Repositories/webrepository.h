#ifndef WEBREPOSITORY_H
#define WEBREPOSITORY_H

#include <memory>

#include <Model/Entities/web.h>
#include <Model/DAO/webdao.h>

class WebRepository
{
public:
    WebRepository();

    std::shared_ptr<Web> getOpenedWeb();
    void save(std::shared_ptr<Web> web);

private:
    std::shared_ptr<Web> _web;
    WebDAO _dao;
};

#endif // WEBREPOSITORY_H
