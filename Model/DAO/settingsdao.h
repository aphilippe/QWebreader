#ifndef SETTINGSDAO_H
#define SETTINGSDAO_H

#include <QException>
#include <QString>

class NoFileSettingsDAOException : QException
{
public:
    void raise() const { throw *this; }
    NoFileSettingsDAOException *clone() const { return new NoFileSettingsDAOException(*this); }
};

class SettingsDAO
{
public:
    SettingsDAO();
    QByteArray get();
    void save(const QByteArray& data);
};

#endif // SETTINGSDAO_H
