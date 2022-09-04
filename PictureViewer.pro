QT += quick
QT += quickcontrols2
QT += sql

SOURCES += \
    src/DatabaseConnection.cpp \
    src/DicomImageProvider.cpp \
    src/DicomImporter.cpp \
    src/main.cpp

HEADERS += \
    src/DatabaseConnection.h \
    src/DicomImageProvider.h \
    src/DicomImporter.h

RESOURCES += \
    src/app.qrc

LIBS += -limebra

DISTFILES += \
    README.md \
    src/Components/FileListItem.qml \
    src/main.qml
