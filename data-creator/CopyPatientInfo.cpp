#include <imebra/imebra.h>
#include <iostream>

// #include "CopyPatientInfo.h"

#include <cstdint>

using namespace std;

int main()
{
    // pobranie danych z pliku DICOM:
    imebra::DataSet loadedDataSet(imebra::CodecFactory::load("../images/DICOM/case5b.dcm"));

    string sex = loadedDataSet.getString(imebra::TagId(imebra::tagId_t::PatientSex_0010_0040), 0);
        
    string modality = loadedDataSet.getString(imebra::TagId(imebra::tagId_t::Modality_0008_0060), 0);
        
    imebra::UnicodePatientName patientName = loadedDataSet.getUnicodePatientName(imebra::TagId(imebra::tagId_t::PatientName_0010_0010), 0);
    wstring patientNameCharacter = patientName.getAlphabeticRepresentation();   
    string patientNameCharacter_S(patientNameCharacter.begin(), patientNameCharacter.end());
                                  
    string patientId_S = loadedDataSet.getString(imebra::TagId(imebra::tagId_t::PatientID_0010_0020), 0);
                
    uint32_t patientAge = 
            loadedDataSet.getAge(imebra::TagId(imebra::tagId_t::PatientAge_0010_1010), 0, imebra::Age(0, imebra::ageUnit_t::years)).getAgeValue();

    cout << "name: " << patientNameCharacter_S << endl;
    cout << "age: " << patientAge << endl;
    cout << "gender: " << sex << endl;
    cout << "modality: " << modality << endl;

    return 0;
}
