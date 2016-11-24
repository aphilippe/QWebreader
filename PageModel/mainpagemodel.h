#ifndef MAINPAGEMODEL_H
#define MAINPAGEMODEL_H

#include <QObject>

class MainPageModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isWebOpened READ isWebOpened NOTIFY isWebOpenedChanged)
public:
    explicit MainPageModel(QObject *parent = 0);
    ~MainPageModel();

    bool isWebOpened() const;

signals:
    void isWebOpenedChanged();
};

#endif // MAINPAGEMODEL_H
