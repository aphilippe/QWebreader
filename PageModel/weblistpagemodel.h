#ifndef WEBLISTPAGEMODEL_H
#define WEBLISTPAGEMODEL_H

#include <QObject>
#include <QQmlListProperty>

class WebRepository;

class WebListPageModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList webs READ webs NOTIFY websChanged)
public:
    explicit WebListPageModel(QObject *parent = 0);
    ~WebListPageModel();

    QStringList webs();

private:
    QStringList _webs;
    std::shared_ptr<WebRepository> _webRepository;

signals:
    void websChanged();
};

#endif // WEBLISTPAGEMODEL_H
