#ifndef MAINPAGEMODEL_H
#define MAINPAGEMODEL_H

#include <QObject>

class Web;
class WebRepository;

class MainPageModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString url READ url NOTIFY urlChanged)
public:
    explicit MainPageModel(QObject *parent = 0);
    ~MainPageModel();

    QString url();

public slots:
    void onUrlUpdated(const QString& url);

private:
    std::shared_ptr<Web> _web;
    std::shared_ptr<WebRepository> _webRepo;

signals:
    void urlChanged();
};

#endif // MAINPAGEMODEL_H
