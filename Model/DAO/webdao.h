#ifndef WEBDAO_H
#define WEBDAO_H

#include <QJSonDocument>

class WebDAO
{
public:
    WebDAO();

    QJsonDocument get();
};

#endif // WEBDAO_H
