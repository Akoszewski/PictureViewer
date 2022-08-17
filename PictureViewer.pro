QT += quick
QT += quickcontrols2
QT += sql

SOURCES += \
    src/Database.cpp \
    src/DicomImageProvider.cpp \
    src/main.cpp

HEADERS += \
    src/Database.h
    src/DicomImageProvider.h

RESOURCES += \
    src/app.qrc

DISTFILES += \
    README.md \
    src/Components/FileListItem.qml \
    src/images/DICOM/series-000001/image-000001.dcm \
    src/images/DICOM/series-000001/image-000002.dcm \
    src/images/DICOM/series-000001/image-000003.dcm \
    src/images/DICOM/series-000001/image-000004.dcm \
    src/images/DICOM/series-000001/image-000005.dcm \
    src/images/pic.jpg \
    src/images/pic2.jpg \
    src/images/pic3.jpeg \
    src/images/pic3.jpg \
    src/images/pic4.jpg \
    src/images/pic5.jpg \
    src/images/pic6.jpg \
    src/main.qml
