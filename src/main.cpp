#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <imebra/imebra.h>

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

class DicomDataLoader
{
public:
    QString getPatientName(const imebra::DataSet &loadedDataSet)
    {
        imebra::UnicodePatientName patientName = loadedDataSet.getUnicodePatientName(imebra::TagId(imebra::tagId_t::PatientName_0010_0010), 0);
        std::wstring patientNameCharacter = patientName.getAlphabeticRepresentation();   
        std::string patientNameCharacter_S(patientNameCharacter.begin(), patientNameCharacter.end());
        return QString::fromStdString(patientNameCharacter_S);
    }

    QString getTag(const imebra::DataSet &loadedDataSet, const imebra::tagId_t &tag)
    {
        std::string info;
        try {
            info = loadedDataSet.getString(imebra::TagId(tag), 0);
        } catch (imebra::MissingTagError &e) {
            qDebug() << "Exception on tag: " << QString::number(static_cast<int>(tag));
            info = "Unknown";
        }
        return QString::fromStdString(info);
    }

    void storeDicomDataInDatabase(Database &db, const QString &fileName)
    {
        try {
            imebra::DataSet loadedDataSet(imebra::CodecFactory::load(fileName.toStdString()));
            QString patientName = getPatientName(loadedDataSet);
            // pobranie danych z pliku DICOM:
            QString sex = getTag(loadedDataSet, imebra::tagId_t::PatientSex_0010_0040);
            QString modality = getTag(loadedDataSet, imebra::tagId_t::Modality_0008_0060);  
            QString patientId_S = getTag(loadedDataSet, imebra::tagId_t::PatientID_0010_0020);
                        
            QString patientAge = QString::number(loadedDataSet.getAge(imebra::TagId(imebra::tagId_t::PatientAge_0010_1010), 0, imebra::Age(0, imebra::ageUnit_t::years)).getAgeValue());

            qDebug() << "name: " <<  patientName;
            qDebug() << "age: " <<  patientAge;
            qDebug() << "gender: " << sex;
            qDebug() << "modality: " << modality;

            // db.executeQuery("INSERT INTO patients (name, gender, age) VALUES ('" + patientName + "', '" + sex + "', '" + patientAge + "')");
            // db.executeQuery("INSERT INTO exams (modality, filePath) VALUES ('" + modality + "', '" + fileName + "')");

        } catch (imebra::StreamReadError &e) {
            qDebug() << "Exception: " << e.what();
        }
    }

    void importData(const QString &path)
    {
        Database db("app_database");
        QDirIterator it(path);
        while (it.hasNext())
        {
            QString fileName = it.next();
            storeDicomDataInDatabase(db, fileName);
        }
        // db.executeQuery("select * from patients", Database::ExecutionMode::Print);
    }
};

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    
    engine.addImageProvider(QLatin1String("DicomImageProvider"), new DicomImageProvider);
    
    Q_INIT_RESOURCE(app);

    setupDatabase();

    DicomDataLoader dicomLoader;
    dicomLoader.importData(QStandardPaths::DocumentsLocation + "/images/DICOM/");

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}        
