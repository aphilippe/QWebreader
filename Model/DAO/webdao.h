#ifndef WEBDAO_H
#define WEBDAO_H

#include <QJSonDocument>

class WebDAO
{
public:
    WebDAO(const QString& folder);

    QJsonDocument get();
    void save(const QJsonDocument& document);

    QString folder() const;

private:
    QString _folder;
};

#endif // WEBDAO_H
