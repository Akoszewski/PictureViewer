#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "database.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    Database db;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}
