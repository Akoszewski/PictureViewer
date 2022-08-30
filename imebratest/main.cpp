#include <imebra/imebra.h>
#include <iostream>
using namespace std;

int main()
{
    // pobranie danych z pliku DICOM:
    imebra::DataSet
        loadedDataSet(imebra::CodecFactory::load("image-000001.dcm", 2048));
    string studyId_S =
        loadedDataSet.getString(imebra::TagId(imebra::tagId_t::StudyInstanceUID_0020_000D), 0);
    imebra::UnicodePatientName patientName =
        loadedDataSet.getUnicodePatientName(imebra::TagId(imebra::tagId_t::PatientName_0010_0010),
                                            0);
    wstring patientNameCharacter =
        patientName.getAlphabeticRepresentation();
    string patientNameCharacter_S(patientNameCharacter.begin(),
                                  patientNameCharacter.end());
    string patientId_S =
        loadedDataSet.getString(imebra::TagId(imebra::tagId_t::PatientID_0010_0020), 0);
    uint32_t patientAge =
        loadedDataSet.getAge(imebra::TagId(imebra::tagId_t::PatientAge_0010_1010), 0, imebra::Age(0, imebra::ageUnit_t::years)).getAgeValue();
    // zapis obrazu
    imebra::Image image =
        loadedDataSet.getImageApplyModalityTransform(0);
    imebra::Image *pFinalImage = &image;
    imebra::FileStreamOutput writeJpeg("image.jpg");
    imebra::StreamWriter writer(writeJpeg);
    const std::string jpegTransferSyntax("1.2.840.10008.1.2.4.50");
    imebra::CodecFactory::saveImage(writer, *pFinalImage,
                                    jpegTransferSyntax, imebra::imageQuality_t::veryHigh, 8, false,
                                    false, true, false);
    cout << "Study_id: " << studyId_S << endl;
    return 0;
}
