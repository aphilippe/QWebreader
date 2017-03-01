QT += qml quick webengine

CONFIG += c++11

SOURCES += main.cpp \
    PageModel/mainpagemodel.cpp \
    Model/Repositories/webrepository.cpp \
    Model/Entities/web.cpp \
    Model/DAO/webdao.cpp \
    Model/Entities/settings.cpp \
    Model/Repositories/settingsrepository.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    PageModel/mainpagemodel.h \
    Model/Repositories/webrepository.h \
    Model/Entities/web.h \
    Utils/ioccontainer.h \
    Model/DAO/webdao.h \
    Model/Entities/settings.h \
    Model/Repositories/settingsrepository.h
