
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0



LIBS += -lblas -llapack -ltbb -lserial

INCLUDEPATH += $$PWD/headers/

SOURCES += \
    $$PWD/src/CustomCursor.cpp \
    $$PWD/src/GPSData.cpp \
    #src/main.cpp\
    $$PWD/src/gps_driver/GPSFix.cpp \
    $$PWD/src/gps_driver/GPSService.cpp \
    $$PWD/src/gps_driver/NMEACommand.cpp \
    $$PWD/src/gps_driver/NMEAParser.cpp \
    $$PWD/src/gps_driver/NumberConversion.cpp \
    $$PWD/src/gps_driver/drotek_f9p_rover.cpp \
    $$PWD/src/gps_driver/HAL_Sirius_F9P_Rover.cc

HEADERS += \
    $$PWD/headers/CustomCursor.h \
    $$PWD/headers/GPSData.h \
    $$PWD/headers/gps_driver/nmeaparse/Event.h \
    $$PWD/headers/gps_driver/nmeaparse/GPSFix.h \
    $$PWD/headers/gps_driver/nmeaparse/GPSService.h \
    $$PWD/headers/gps_driver/nmeaparse/nmea.h \
    $$PWD/headers/gps_driver/nmeaparse/NMEACommand.h \
    $$PWD/headers/gps_driver/nmeaparse/NMEAParser.h \
    $$PWD/headers/gps_driver/nmeaparse/NumberConversion.h


CONFIG += qmltypes
QML_IMPORT_NAME = io.qt.examples.gps_data
QML_IMPORT_MAJOR_VERSION = 1

DISTFILES += \
    readme.md \
    presentation_image.png \
    import_tiles.sh \
    .gitignore
