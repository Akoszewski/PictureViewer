#ifndef DICOM_IMAGE_PROVIDER
#define DICOM_IMAGE_PROVIDER

#include <QQuickImageProvider>

class DicomImageProvider : public QQuickImageProvider
{
public:
   DicomImageProvider();
   QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize) override;
};

#endif
