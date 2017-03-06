#include "mainpagemodel.h"
#include <Utils/ioccontainer.h>
#include <Model/Repositories/settingsrepository.h>

MainPageModel::MainPageModel(QObject *parent)
    : QObject(parent), _settingsRepo(IOCContainer::instance().get<SettingsRepository>())
{}

MainPageModel::~MainPageModel()
{}

bool MainPageModel::isSaveDirectorySet()
{
    return !_settingsRepo->get()->saveDirectory().isEmpty();
}
