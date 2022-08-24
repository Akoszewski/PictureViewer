#include <QGuiApplication>
#include <QQuickView>

#include "Database.h"
#include "DicomImageProvider.h"

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

    QQuickView view;

    
    QQmlEngine *engine = view.engine();
    engine->addImageProvider(QLatin1String("DicomImageProvider"), new DicomImageProvider);
    
    view.setSource(QUrl(QStringLiteral("qrc:/main.qml")));
    view.show();
    // engine.addImageProvider(QLatin1String("DicomImageProvider"), new DicomImageProvider);
    // Q_INIT_RESOURCE(app);

    setupDatabase();

    return app.exec();
}

