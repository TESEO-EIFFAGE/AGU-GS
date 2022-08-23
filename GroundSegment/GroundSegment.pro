QT       += widgets core qml quick location

CONFIG += c++17

QMAKE_CXXFLAGS += -Wall -Wextra -Wno-narrowing -std=c++11 -shared -fPIC -O3 -mtune=native -march=native -DNDEBUG -fopenmp -ltbb
QMAKE_LFLAGS += -DHAVE_CBLAS=1
#CONFIG += c++11
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
include($$PWD/libs/F9P-Coordinates-Viewer/F9P_Coordinates_Viewer.pri)

SOURCES += \
    hmi.cpp \
    hmi_controller.cpp \
    main.cpp \
#    mainwindow.cpp \
    mavlinkprotocol.cpp \
    storage.cpp \
#    topdialog.cpp

HEADERS += \
    hmi.h \
    hmi_controller.h \
#    mainwindow.h \
    mavlinkprotocol.h \
    storage.h \
#    topdialog.h

RESOURCES += \
    GroundSegmentUI/GroundSegmentUI.qrc

QML_IMPORT_PATH += \
    GroundSegmentUI/ \
    GroundSegmentUI/imports

QT       += serialport
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
