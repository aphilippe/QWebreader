#include "settings.h"

Settings::Settings(const QString& saveDirectory)
    : _saveDirectory(saveDirectory)
{}

QString Settings::saveDirectory() const
{
    return _saveDirectory;
}

void Settings::setSaveDirectory(const QString &saveDirectory)
{
    _saveDirectory = saveDirectory;
}
