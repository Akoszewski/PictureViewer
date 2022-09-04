#include "DicomImageProvider.h"

#include <imebra/imebra.h>
#include <cstdint>
#include <QStandardPaths>

DicomImageProvider::DicomImageProvider()
        : QQuickImageProvider(QQuickImageProvider::Pixmap)
{}

QPixmap DicomImageProvider::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
{
    Q_UNUSED(size);
    Q_UNUSED(requestedSize);

    qDebug() << "id: " << id;
    try {
        // wczytywanie plikow dicom i konwersja na QPixmap
        imebra::DataSet loadedDataSet(imebra::CodecFactory::load((QStandardPaths::DocumentsLocation + "/" + id).toStdString()));

        imebra::Image image(loadedDataSet.getImageApplyModalityTransform(0));
        imebra::ReadingDataHandlerNumeric dataHandler(image.getReadingDataHandler());

        imebra::FileStreamOutput writeJpeg("/dev/shm/image.jpg"); // powinno sie utworzyc w tymczasowym pliku w pamieci RAM (nie na dysku)
        imebra::StreamWriter writer(writeJpeg);
        const std::string jpegTransferSyntax("1.2.840.10008.1.2.4.50");
        imebra::CodecFactory::saveImage(writer, image,
                                        jpegTransferSyntax, imebra::imageQuality_t::veryHigh, 8, false,
                                        false, true, false);

        QPixmap pixmap("/dev/shm/image.jpg");
        return pixmap;
    } catch (imebra::StreamOpenError& e) {
        QPixmap pixmap;
        return pixmap;
    }
}

// QPixmap DicomImageProvider::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
// {
//     Q_UNUSED(size);
//     Q_UNUSED(requestedSize);

//     qDebug() << "id: " << id;
//     // TODO: Tutaj musi byc wczytywanie plikow dicom i konwersja na QPixmap
//     imebra::DataSet loadedDataSet(imebra::CodecFactory::load(("./PictureViewer/images/DICOM/" + id).toStdString()));
    
//     imebra::UnicodePatientName patientName = loadedDataSet.getUnicodePatientName(imebra::TagId(imebra::tagId_t::PatientName_0010_0010), 0);
//     qDebug() << "Patient name: " << QString::fromStdWString(patientName.getAlphabeticRepresentation());

//     imebra::Image image(loadedDataSet.getImageApplyModalityTransform(0));

//     std::string colorSpace = image.getColorSpace();
//     qDebug() << "colorSpace: " << QString::fromStdString(colorSpace);

//     long width = image.getWidth();
//     long height = image.getHeight();

//     imebra::ReadingDataHandlerNumeric dataHandler(image.getReadingDataHandler());
//     // const char * xpm[height];
//     // int noOfColors = 2;
//     // int charsPerPixel = 1;
//     // xpm[0] = (std::to_string(width) + " " + std::to_string(height) + " " + std::to_string(noOfColors) + " " + std::to_string(charsPerPixel)).c_str();
//     unsigned char data[width * height * 3];
//     for (std::uint32_t scanY(0); scanY != height; ++scanY)
//     {
//         for(std::uint32_t scanX(0); scanX != width; ++scanX)
//         {
//             // For monochrome images
//             std::int32_t luminance = dataHandler.getSignedLong(scanY * width + scanX);
//             // qDebug() << "luminance: " << luminance;

//             // For RGB images
//             // std::int32_t r = dataHandler.getSignedLong((scanY * width + scanX) * 3);
//             // std::int32_t g = dataHandler.getSignedLong((scanY * width + scanX) * 3 + 1);
//             // std::int32_t b = dataHandler.getSignedLong((scanY * width + scanX) * 3 + 2);
//         }
//     }

//     QImage image(const uchar *data, int width, int height, qsizetype bytesPerLine, QImage::Format format);
//     QPixmap pixmap(width, height);
//     pixmap.convertFromImage(image);
//     return pixmap;
// }
