#ifndef SETTINGSDAO_H
#define SETTINGSDAO_H

#include <QString>

class SettingsDAO
{
public:
    SettingsDAO();
    QByteArray get();
};

#endif // SETTINGSDAO_H
