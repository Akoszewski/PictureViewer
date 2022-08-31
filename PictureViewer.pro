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

LIBS += -limebra

DISTFILES += \
    README.md \
    src/Components/FileListItem.qml \
    src/main.qml
