#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "Database.h"
#include "DicomImageProvider.h"

using namespace std;

void createDatabase(const QString& databaseName)
{
    Database postgresDb("postgres");
    postgresDb.executeQuery("create database " + databaseName + ";");
}

void setupDatabase()
{
    createDatabase("app_database");
    Database db("app_database");
    db.executeSqlFile(":/setupdb.sql");
}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.addImageProvider(QLatin1String("DicomImageProvider"), new DicomImageProvider);
    Q_INIT_RESOURCE(app);

    setupDatabase();

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}        
