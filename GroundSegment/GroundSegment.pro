QT       += core qml quick location serialport

CONFIG += c++17

QMAKE_CXXFLAGS += -Wall -Wextra -Wno-narrowing -std=c++11 -shared -fPIC -O3 -mtune=native -march=native -DNDEBUG -fopenmp -ltbb
QMAKE_LFLAGS += -DHAVE_CBLAS=1

include($$PWD/src/gnss/gnss.pri)
include($$PWD/src/radio_link/receiver/radio_link.pri)

SOURCES += \
#    configreader.cpp \
    gs_core.cpp \
    hmi.cpp \
    main.cpp \
    mavlinkprotocol.cpp \
    storage.cpp

HEADERS += \
#    configreader.h \
    gs_core.h \
    hmi.h \
    mavlinkprotocol.h \
    storage.h

RESOURCES += \
    GroundSegmentUI/GroundSegmentUI.qrc

QML_IMPORT_PATH += \
    GroundSegmentUI/ \
    GroundSegmentUI/imports

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
