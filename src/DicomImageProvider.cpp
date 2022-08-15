#include "DicomImageProvider.h"

DicomImageProvider::DicomImageProvider()
        : QQuickImageProvider(QQuickImageProvider::Pixmap)
{}

QPixmap DicomImageProvider::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
{
    Q_UNUSED(size);
    Q_UNUSED(requestedSize);

    // TODO: Tutaj musi byc wczytywanie plikow dicom i konwersja na QPixmap

    QPixmap pixmap(":/images/" + id);
    return pixmap;
}
