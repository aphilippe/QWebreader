#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <qtwebengineglobal.h>
#include <PageModel/webpagemodel.h>
#include <PageModel/mainpagemodel.h>
#include <PageModel/weblistpagemodel.h>
#include <Utils/ioccontainer.h>
#include <Model/Repositories/webrepository.h>
#include <Model/Repositories/settingsrepository.h>

void initializeIoc();

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    initializeIoc();

    QtWebEngine::initialize();

    qmlRegisterType<WebPageModel>("PageModel", 1, 0, "WebPageModel");
    qmlRegisterType<MainPageModel>("PageModel", 1, 0, "MainPageModel");
    qmlRegisterType<WebListPageModel>("PageModel", 1, 0, "WebListPageModel");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}

void initializeIoc()
{
    IOCContainer::instance().add(std::make_shared<SettingsRepository>());
    IOCContainer::instance().add(std::make_shared<WebRepository>());
}
