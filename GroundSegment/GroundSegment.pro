QT       += core qml quick location serialport

CONFIG += c++17

include($$PWD/src/gnss/gnss.pri)
include($$PWD/src/radio_link/receiver/radio_link.pri)
include($$PWD/src/storage/storage.pri)
include($$PWD/src/hmi/hmi.pri)

SOURCES += \
    gs_core.cpp \
    main.cpp

HEADERS += \
    gs_core.h

RESOURCES += \
    GroundSegmentUI/GroundSegmentUI.qrc

QML_IMPORT_PATH += \
    GroundSegmentUI/ \
    GroundSegmentUI/imports

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
