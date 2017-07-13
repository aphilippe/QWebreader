#ifndef WEBLISTPAGEMODEL_H
#define WEBLISTPAGEMODEL_H

#include <QObject>
#include <QQmlListProperty>

class WebRepository;
class Web;

class WebListPageModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList webs READ webs NOTIFY websChanged)
public:
    explicit WebListPageModel(QObject *parent = 0);
    ~WebListPageModel();

    QStringList webs();

public slots:
    void selectItem(int index);

private:
    std::vector<std::shared_ptr<Web>> _webs;
    std::shared_ptr<WebRepository> _webRepository;

signals:
    void websChanged();
    void webIdChanged(int newWebId);
};

#endif // WEBLISTPAGEMODEL_H
