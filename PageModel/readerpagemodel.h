#ifndef READERPAGEMODLE_H
#define READERPAGEMODLE_H

#include <QObject>
#include <QUrl>

class Web;

class ReaderPageModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QUrl openedWeb READ getOpenedWeb NOTIFY openedWebChanged)
public:
    explicit ReaderPageModel(QObject* parent = 0);
    ~ReaderPageModel();

    QUrl getOpenedWeb() const;

signals:
    void openedWebChanged();
};

#endif // READERPAGEMODLE_H
