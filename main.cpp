#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <qtwebengineglobal.h>
#include <PageModel/mainpagemodel.h>
#include <PageModel/readerpagemodel.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QtWebEngine::initialize();

    qmlRegisterType<MainPageModel>("PageModel", 1, 0, "MainPageModel");
    qmlRegisterType<ReaderPageModel>("PageModel", 1, 0, "ReaderPageModel");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}
