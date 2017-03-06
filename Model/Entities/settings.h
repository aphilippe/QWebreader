#ifndef SETTINGS_H
#define SETTINGS_H

#include <QString>



class Settings
{
public:
    Settings(const QString& saveDirectory);

    QString saveDirectory() const;
    void setSaveDirectory(const QString &saveDirectory);

private:
    QString _saveDirectory;
};

#endif // SETTINGS_H
