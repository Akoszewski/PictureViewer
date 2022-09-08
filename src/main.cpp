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

    QQmlContext* context = engine.rootContext();

    DicomImporter dicomImporter;
    // dicomImporter.importFiles(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/images/DICOM/");

    DicomTableModel dicomTableModel;
    context->setContextProperty("dicomTableModel", &dicomTableModel);
    context->setContextProperty("dicomImporter", &dicomImporter);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}        
