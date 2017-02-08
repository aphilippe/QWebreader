#ifndef MAINPAGEMODEL_H
#define MAINPAGEMODEL_H

#include <QObject>

class MainPageModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isWebOpened MEMBER _webOpened NOTIFY isWebOpenedChanged)
    Q_PROPERTY(QString url WRITE setUrl MEMBER _url)
public:
    explicit MainPageModel(QObject *parent = 0);
    ~MainPageModel();

    void setUrl(QString url);

private:
    QString _url;
    bool _webOpened;

signals:
    void isWebOpenedChanged();
};

#endif // MAINPAGEMODEL_H
