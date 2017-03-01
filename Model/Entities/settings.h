#ifndef SETTINGS_H
#define SETTINGS_H

#include <QString>



class Settings
{
public:
    Settings(const QString& saveDirectory);

    QString saveDirectory() const;

private:
    QString _saveDirectory;
};

#endif // SETTINGS_H
