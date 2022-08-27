#include "DicomImageProvider.h"
#include <imebra/imebra.h>

DicomImageProvider::DicomImageProvider()
        : QQuickImageProvider(QQuickImageProvider::Pixmap)
{}

QPixmap DicomImageProvider::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
{
    Q_UNUSED(size);
    Q_UNUSED(requestedSize);

    // TODO: Tutaj musi byc wczytywanie plikow dicom i konwersja na QPixmap
    loadedDataSet(imebra::CodecFactory::load(":/images/" + id, 2048));
    
    //imebra::UnicodePatientName patientName = loadedDataSet.getUnicodePatientName(imebra::tagId_t::PatientName)

    QPixmap pixmap(":/images/" + id);
    return pixmap;
}
