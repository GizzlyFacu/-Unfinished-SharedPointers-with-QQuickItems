#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "src/creatorbase.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    //creo el singleton
    CreatorBase* creatorBase=new CreatorBase(&app);
    //seteo el engine donde estan las webadas qml
    creatorBase->setQmlEngine(&engine);
    //register
    qmlRegisterSingletonInstance<CreatorBase>("com.facu.utils", 1, 0, "CreatorBases", creatorBase);
    qmlRegisterType<BaseTemplate>("com.facu.utils", 1, 0, "BaseTemplate");


    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("PortfolioExtender", "Main");

    return app.exec();
}
