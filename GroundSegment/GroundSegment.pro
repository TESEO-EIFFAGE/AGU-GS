QT       += core qml quick location serialport

CONFIG += c++17

include($$PWD/src/gnss/gnss.pri)
include($$PWD/src/radio_link/receiver/radio_link.pri)
include($$PWD/src/storage/storage.pri)

SOURCES += \
#    configreader.cpp \
    gs_core.cpp \
    hmi.cpp \
    main.cpp

HEADERS += \
#    configreader.h \
    gs_core.h \
    hmi.h

RESOURCES += \
    GroundSegmentUI/GroundSegmentUI.qrc

QML_IMPORT_PATH += \
    GroundSegmentUI/ \
    GroundSegmentUI/imports

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
