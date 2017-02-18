#ifndef MAINPAGEMODEL_H
#define MAINPAGEMODEL_H

#include <QObject>

class Web;

class MainPageModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isWebOpened READ isWebOpened NOTIFY isWebOpenedChanged)
    Q_PROPERTY(int openedWebId READ getOpenedWebId NOTIFY openedWebId)
public:
    explicit MainPageModel(QObject *parent = 0);
    ~MainPageModel();

    int getOpenedWebId();
    bool isWebOpened();

public slots:
    void onUrlChanged(const QString & url);

private:
    Web* _web;

signals:
    void isWebOpenedChanged();
    void openedWebId();
};

#endif // MAINPAGEMODEL_H
