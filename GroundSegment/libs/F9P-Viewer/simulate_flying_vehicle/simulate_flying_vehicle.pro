#TEMPLATE = app
#CONFIG += console

QMAKE_CFLAGS += -std=gnu11

INCLUDEPATH += $$PWD/include/mavlink/v2.0 \
               $$PWD/include/mavlink/v2.0/common

SOURCES += simulate_flying_vehicle.c

