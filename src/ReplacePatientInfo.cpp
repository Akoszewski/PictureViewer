#include <imebra/imebra.h>
#include <iostream>

#include "ReplacePatientInfo.h"
#include "Database.h"

#include<sql.h>
#include<sqlext.h> //dwie biblioteki do obslugi sql
#include<string.h> //bibloteka do obslugi lancuchow znakow

#include <cstdint>
#include <QStandardPaths>

using namespace std;

int main()
{
srand (time(NULL));

qDebug() << "id: " << id;


//wbor rand liczb
int liczba = rand() % 10 + 1;

//liczba z noraaki 


    // pobranie danych z pliku DICOM:
    
    imebra::DataSet loadedDataSet(imebra::CodecFactory::load((QStandardPaths::DocumentsLocation + "/home/sim/Downloads/PictureViewer-master/images/DICOM/case1_008.dcm").toStdString()));

   //zapis danch do pliku
loadedDataSet.setUnicodePatientName(TagId(imebra::tagId_t::PatientName_0010_0010), UnicodePatientName(L"Patient^Name", "strImie", "strNazwisko")); 
   
   
   
    return 0;
}

//t()
//