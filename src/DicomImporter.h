#include "DatabaseConnection.h"

#include <imebra/imebra.h>

class DicomImporter
{
public:
    void importFiles(const QString &path);
private:
    QString getPatientName(const imebra::DataSet &loadedDataSet);
    QString getTag(const imebra::DataSet &loadedDataSet, const imebra::tagId_t &tag);
    void importDicomData(DatabaseConnection &db, const QString &filePath);
};
