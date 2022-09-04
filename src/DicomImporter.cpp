#include "DicomImporter.h"

QString DicomImporter::getPatientName(const imebra::DataSet &loadedDataSet)
{
    imebra::UnicodePatientName patientName = loadedDataSet.getUnicodePatientName(imebra::TagId(imebra::tagId_t::PatientName_0010_0010), 0);
    std::wstring patientNameCharacter = patientName.getAlphabeticRepresentation();   
    std::string patientNameCharacter_S(patientNameCharacter.begin(), patientNameCharacter.end());
    return QString::fromStdString(patientNameCharacter_S);
}

QString DicomImporter::getTag(const imebra::DataSet &loadedDataSet, const imebra::tagId_t &tag)
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

void DicomImporter::importDicomData(DatabaseConnection &db, const QString &filePath)
{
    try {
        imebra::DataSet loadedDataSet(imebra::CodecFactory::load(filePath.toStdString()));
        QString patientName = getPatientName(loadedDataSet);
        // pobranie danych z pliku DICOM:
        QString sex = getTag(loadedDataSet, imebra::tagId_t::PatientSex_0010_0040);
        QString modality = getTag(loadedDataSet, imebra::tagId_t::Modality_0008_0060);  
        QString patientId_S = getTag(loadedDataSet, imebra::tagId_t::PatientID_0010_0020);
                    
        QString patientAge = QString::number(loadedDataSet.getAge(imebra::TagId(imebra::tagId_t::PatientAge_0010_1010), 0, imebra::Age(0, imebra::ageUnit_t::years)).getAgeValue());

        db.executeQuery("INSERT INTO patients (name, gender, age) VALUES ('" + patientName + "', '" + sex + "', '" + patientAge + "')");
        db.executeQuery("INSERT INTO exams (modality, filePath) VALUES ('" + modality + "', '" + filePath + "')");

    } catch (imebra::StreamReadError &e) {
        qDebug() << "Exception: " << e.what();
    }
}

void DicomImporter::importFiles(const QString &path)
{
    DatabaseConnection db("app_database");
    QDirIterator it(path);
    while (it.hasNext())
    {
        QString fileName = it.next();
        importDicomData(db, fileName);
    }
    db.executeQuery("select * from patients", DatabaseConnection::ExecutionMode::Print);
}
