#include "mainpagemodel.h"
#include <Utils/ioccontainer.h>
#include <Model/Repositories/settingsrepository.h>
#include <QUrl>

MainPageModel::MainPageModel(QObject *parent)
    : QObject(parent), _settingsRepo(IOCContainer::instance().get<SettingsRepository>())
{}

MainPageModel::~MainPageModel()
{}

bool MainPageModel::isSaveDirectorySet()
{
    return !_settingsRepo->get()->saveDirectory().isEmpty();
}

void MainPageModel::onSaveDirectoryChange(const QUrl &path)
{
    QString stringPath = path.toLocalFile();
    _settingsRepo->get()->setSaveDirectory(stringPath);
    _settingsRepo->save();
}
