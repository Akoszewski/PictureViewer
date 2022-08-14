#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "database.h"

void createDatabase(const QString& databaseName)
{
    Database postgresDb("postgres");
    postgresDb.executeQuery("create database " + databaseName + ";");
}

void setupDatabase()
{
    createDatabase("app_database");
    Database db("app_database");
    db.executeSqlFile("database.sql");
}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    setupDatabase();

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}
