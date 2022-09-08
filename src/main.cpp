#include "DatabaseConnection.h"
#include "DicomImageProvider.h"
#include "DicomImporter.h"
#include "DicomTableModel.h"
#include "DatabaseSetuper.h"

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

    DatabaseSetuper dbSetuper;
    dbSetuper.setupDatabase();

    QQmlContext* context = engine.rootContext();

    DicomImporter dicomImporter;
    DicomTableModel dicomTableModel;
    context->setContextProperty("dicomTableModel", &dicomTableModel);
    context->setContextProperty("dicomImporter", &dicomImporter);
    context->setContextProperty("dbSetuper", &dbSetuper);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}        
