#include "webdao.h"

WebDAO::WebDAO()
{

}

QJsonDocument WebDAO::get()
{
    return QJsonDocument::fromJson(QString::fromStdString("{\"url\":\"https://www.google.com\"}").toUtf8());
}
