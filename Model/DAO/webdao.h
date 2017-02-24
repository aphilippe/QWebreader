#ifndef WEBDAO_H
#define WEBDAO_H

#include <QJSonDocument>

class WebDAO
{
public:
    WebDAO();

    QJsonDocument get();
    void save(const QJsonDocument& document);
};

#endif // WEBDAO_H
