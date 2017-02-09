#ifndef READERPAGEMODLE_H
#define READERPAGEMODLE_H

#include <QObject>
#include <QUrl>

class Web;

class ReaderPageModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QUrl url READ url WRITE setUrl NOTIFY urlChanged)
public:
    explicit ReaderPageModel(QObject* parent = 0);
    ~ReaderPageModel();

    QUrl url() const;

public slots:
    void setWebId(int id);
    void setUrl(const QUrl& url);

signals:
    void openedWebChanged();
    void urlChanged();

private:
    Web* _web;
};

#endif // READERPAGEMODLE_H
