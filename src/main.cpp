#include "DatabaseConnection.h"
#include "DicomImageProvider.h"
#include "DicomImporter.h"
#include "DicomTableModel.h"
#include "DatabaseCreator.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

using namespace std;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    
    engine.addImageProvider(QLatin1String("DicomImageProvider"), new DicomImageProvider);
    
    Q_INIT_RESOURCE(app);

    DatabaseCreator dbCreator;
    dbCreator.setupDatabase();
    engine.rootContext()->setContextProperty("dbCreator", &dbCreator);

    DicomImporter dicomImporter;
    engine.rootContext()->setContextProperty("dicomImporter", &dicomImporter);

    DicomTableModel dicomTableModel;
    engine.rootContext()->setContextProperty("dicomTableModel", &dicomTableModel);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}        
