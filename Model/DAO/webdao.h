#ifndef WEBDAO_H
#define WEBDAO_H

#include <QJsonDocument>
#include <vector>

class WebDAO
{
public:
    WebDAO(const QString& folder);

    std::vector<QByteArray> get();
    void save(const QByteArray& document, const int id);

    QString folder() const;
    void setFolder(const QString &folder);

private:
    QString _folder;
};

#endif // WEBDAO_H
