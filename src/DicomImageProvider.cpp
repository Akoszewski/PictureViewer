#include "DicomImageProvider.h"
#include <imebra/imebra.h>

DicomImageProvider::DicomImageProvider()
        : QQuickImageProvider(QQuickImageProvider::Pixmap)
{}

QPixmap DicomImageProvider::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
{
    Q_UNUSED(size);
    Q_UNUSED(requestedSize);

    qDebug() << "id: " << id;
    // TODO: Tutaj musi byc wczytywanie plikow dicom i konwersja na QPixmap
    imebra::DataSet loadedDataSet(imebra::CodecFactory::load(("/home/arek/PictureViewer/images/DICOM/" + id).toStdString()));
    
    imebra::UnicodePatientName patientName = loadedDataSet.getUnicodePatientName(imebra::TagId(imebra::tagId_t::PatientName_0010_0010), 0);
    qDebug() << "Patient name: " << QString::fromStdWString(patientName.getAlphabeticRepresentation());
    imebra::Image image(loadedDataSet.getImageApplyModalityTransform(0));
    
    const char *const xpm[] = {""};
    QPixmap pixmap(xpm);
    return pixmap;
}
