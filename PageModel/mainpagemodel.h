#ifndef MAINPAGEMODEL_H
#define MAINPAGEMODEL_H

#include <QObject>
#include <QUrl>

class Web;

class MainPageModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isWebOpened READ isWebOpened NOTIFY isWebOpenedChanged)
    Q_PROPERTY(QUrl url READ url NOTIFY urlChanged)
public:
    explicit MainPageModel(QObject *parent = 0);
    ~MainPageModel();


    bool isWebOpened();
    QUrl url();

public slots:
    void onNewUrlChosed(const QString& url);

private:
    std::shared_ptr<Web> _web;

signals:
    void isWebOpenedChanged();
    void urlChanged();
};

#endif // MAINPAGEMODEL_H
