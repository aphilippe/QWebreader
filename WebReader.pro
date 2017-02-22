QT += qml quick webengine

CONFIG += c++11

SOURCES += main.cpp \
    PageModel/mainpagemodel.cpp \
    Model/Repositories/webrepository.cpp \
    Model/Entities/web.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    PageModel/mainpagemodel.h \
    Model/Repositories/webrepository.h \
    Model/Entities/web.h \
    Utils/ioccontainer.h
