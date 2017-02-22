#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <qtwebengineglobal.h>
#include <PageModel/mainpagemodel.h>
#include <Utils/ioccontainer.h>
#include <Model/Repositories/webrepository.h>

void initializeIoc();

int main(int argc, char *argv[])
{
    initializeIoc();

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QtWebEngine::initialize();

    qmlRegisterType<MainPageModel>("PageModel", 1, 0, "MainPageModel");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}

void initializeIoc()
{
    IOCContainer::instance().add(std::make_shared<WebRepository>());
}
