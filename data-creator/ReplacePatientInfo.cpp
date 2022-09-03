#include <imebra/imebra.h>
#include <iostream>

#include <string.h>

#include <cstdint>

using namespace std;

int main()
{
    srand (time(NULL));

    int liczba = rand() % 10 + 1;

    imebra::DataSet dataSet(imebra::CodecFactory::load("test.dcm"));

    auto handler = dataSet.getWritingDataHandler();

    dataSet.setUnicodePatientName(TagId(imebra::tagId_t::PatientName_0010_0010), UnicodePatientName(wstring{}, wstring{}, wstring{}));
    //zapis danch do pliku
    dataSet.setUnicodePatientName(TagId(imebra::tagId_t::PatientName_0010_0010), UnicodePatientName(L"Patient^Name", "", ""));
    // .setUnicodePatientName(imebra::TagId(imebra::tagId_t::PatientName_0010_0010), imebra::UnicodePatientName(L"Patient^Name", "strImie", "strNazwisko")); 
    return 0;
}
