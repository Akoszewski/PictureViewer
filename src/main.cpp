#include "DatabaseConnection.h"
#include "DicomImageProvider.h"
#include "DicomImporter.h"
#include "DicomTableModel.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

using namespace std;

void createDatabase(const QString& databaseName)
{
    DatabaseConnection postgresDb("postgres");
    postgresDb.executeQuery("create database " + databaseName + ";");
}

void setupDatabase()
{
    createDatabase("app_database");
    DatabaseConnection db("app_database");
    db.executeSqlFile(":/setupdb.sql");
}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    
    engine.addImageProvider(QLatin1String("DicomImageProvider"), new DicomImageProvider);
    
    Q_INIT_RESOURCE(app);

    setupDatabase();

    DicomImporter dicomImporter;
    dicomImporter.importFiles(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/images/DICOM/");

    DicomTableModel dicomTableModel;

    QQmlContext* context = engine.rootContext();
    context->setContextProperty("dicomTableModel", &dicomTableModel);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}        
