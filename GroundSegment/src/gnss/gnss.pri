QMAKE_CXXFLAGS += -Wall -Wextra -Wno-narrowing -std=c++11 -shared -fPIC -O3 -mtune=native -march=native -DNDEBUG -fopenmp -ltbb
QMAKE_LFLAGS += -DHAVE_CBLAS=1

LIBS += -lblas -llapack -ltbb -lserial

INCLUDEPATH += $$PWD

SOURCES += \
    $$PWD/custom_cursor.cpp \
    $$PWD/gnss.cpp \
    $$PWD/gps_driver/GPSFix.cpp \
    $$PWD/gps_driver/GPSService.cpp \
    $$PWD/gps_driver/NMEACommand.cpp \
    $$PWD/gps_driver/NMEAParser.cpp \
    $$PWD/gps_driver/NumberConversion.cpp \
    $$PWD/gps_driver/drotek_f9p_rover.cpp \
    $$PWD/gps_driver/HAL_Sirius_F9P_Rover.cc

HEADERS += \
    $$PWD/custom_cursor.h \
    $$PWD/gnss.h \
    $$PWD/gps_driver/nmeaparse/*

CONFIG += qmltypes
QML_IMPORT_NAME = agu.gnss
QML_IMPORT_MAJOR_VERSION = 1
