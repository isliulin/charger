#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "client_controller.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
        
    ClientMessagingController controller;
    controller.init(20001, 2002);
    
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("comms", &controller);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    
    return app.exec();
}
