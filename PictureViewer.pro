QT += quick
QT += quickcontrols2
QT += sql

SOURCES += \
    src/DatabaseConnection.cpp \
    src/DicomImageProvider.cpp \
    src/DicomImporter.cpp \
    src/DicomTableModel.cpp \
    src/main.cpp

HEADERS += \
    src/DatabaseConnection.h \
    src/DicomImageProvider.h \
    src/DicomImporter.h \
    src/DicomTableModel.h \
    src/DatabaseCreator.h

RESOURCES += \
    src/app.qrc

LIBS += -limebra

DISTFILES += \
    README.md \
    src/Components/TableItem.qml \
    src/main.qml
