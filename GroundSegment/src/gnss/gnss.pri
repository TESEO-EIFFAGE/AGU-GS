
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0



LIBS += -lblas -llapack -ltbb -lserial

INCLUDEPATH += $$PWD

SOURCES += \
    $$PWD/CustomCursor.cpp \
    $$PWD/gnss.cpp \
    $$PWD/gps_driver/GPSFix.cpp \
    $$PWD/gps_driver/GPSService.cpp \
    $$PWD/gps_driver/NMEACommand.cpp \
    $$PWD/gps_driver/NMEAParser.cpp \
    $$PWD/gps_driver/NumberConversion.cpp \
    $$PWD/gps_driver/drotek_f9p_rover.cpp \
    $$PWD/gps_driver/HAL_Sirius_F9P_Rover.cc

HEADERS += \
    $$PWD/CustomCursor.h \
    $$PWD/gnss.h \
    $$PWD/gps_driver/nmeaparse/*

CONFIG += qmltypes
QML_IMPORT_NAME = io.qt.examples.gps_data
QML_IMPORT_MAJOR_VERSION = 1

#DISTFILES += \
#    readme.md \
#    presentation_image.png \
#    import_tiles.sh \
#    .gitignore
