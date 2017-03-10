#ifndef WEBDAO_H
#define WEBDAO_H

#include <QJSonDocument>
#include <vector>

class WebDAO
{
public:
    WebDAO(const QString& folder);

    std::vector<QByteArray> get();
    void save(const QByteArray& document);

    QString folder() const;
    void setFolder(const QString &folder);

private:
    QString _folder;
};

#endif // WEBDAO_H
