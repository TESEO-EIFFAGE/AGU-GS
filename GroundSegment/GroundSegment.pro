QT       += quick widgets

CONFIG += c++17

#CONFIG += c++11
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    gs_core.cpp \
    hmi.cpp \
    main.cpp \
#    mainwindow.cpp \
    mavlinkprotocol.cpp \
    storage.cpp \
#    topdialog.cpp

HEADERS += \
    gs_core.h \
    hmi.h \
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
