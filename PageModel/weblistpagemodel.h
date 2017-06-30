#ifndef WEBLISTPAGEMODEL_H
#define WEBLISTPAGEMODEL_H

#include <QObject>

class WebListPageModel : public QObject
{
       Q_OBJECT
public:
    explicit WebListPageModel(QObject *parent = 0);
    ~WebListPageModel();
};

#endif // WEBLISTPAGEMODEL_H
