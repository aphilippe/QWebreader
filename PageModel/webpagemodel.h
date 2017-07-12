#ifndef WEBPAGEMODEL_H
#define WEBPAGEMODEL_H

#include <QObject>
#include <memory>

class Web;
class WebRepository;

class WebPageModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString url READ url NOTIFY urlChanged)
public:
    explicit WebPageModel(QObject *parent = 0);
    ~WebPageModel();

    QString url();

public slots:
    void onUrlUpdated(const QString& url);
    void onWebIdChanged(int webId);

private:
    std::shared_ptr<Web> _web;
    std::shared_ptr<WebRepository> _webRepo;

signals:
    void urlChanged();
};

#endif // WEBPAGEMODEL_H
