#include <imebra/imebra.h>
#include <iostream>

#include "CopyPatientInfo.h"

#include <cstdint>
#include <QStandardPaths>

using namespace std;

int main()
{



qDebug() << "id: " << id;

    // pobranie danych z pliku DICOM:
    
    imebra::DataSet loadedDataSet(imebra::CodecFactory::load((QStandardPaths::DocumentsLocation + "/images/DICOM/" + id).toStdString()));

  
        //sex
    string sex =
        loadedDataSet.getString(imebra::TagId(imebra::tagId_t::PatientSex_0010_0040), 0);
        
        //modality
        string modality =
        loadedDataSet.getString(imebra::TagId(imebra::tagId_t::Modality_0008_0060),0);
        
        //patientName
    imebra::UnicodePatientName patientName =
        loadedDataSet.getUnicodePatientName(imebra::TagId(imebra::tagId_t::PatientName_0010_0010),
                                            0);
    wstring patientNameCharacter =
        patientName.getAlphabeticRepresentation();
        
        
    string patientNameCharacter_S(patientNameCharacter.begin(),
                                  patientNameCharacter.end());
                                  
        //patientId                  
    string patientId_S =
        loadedDataSet.getString(imebra::TagId(imebra::tagId_t::PatientID_0010_0020), 0);
        
        //patientAge
        
        uint32_t patientAge =
        loadedDataSet.getAge(imebra::TagId(imebra::tagId_t::PatientAge_0010_1010), 0, imebra::Age(0, imebra::ageUnit_t::years)).getAgeValue();
        
        // do baz
                
   
   
    return 0;
}
