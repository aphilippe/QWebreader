#ifndef WEBDAO_H
#define WEBDAO_H

#include <QJSonDocument>

class WebDAO
{
public:
    WebDAO(const QString& folder);

    QByteArray get();
    void save(const QByteArray& document);

    QString folder() const;
    void setFolder(const QString &folder);

private:
    QString _folder;
};

#endif // WEBDAO_H
