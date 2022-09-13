#TEMPLATE = app
#CONFIG += console

QMAKE_CFLAGS += -std=gnu11

INCLUDEPATH += $$PWD/include/mavlink/v2.0/AGU/AGU_MAVLINK

SOURCES += simulate_flying_vehicle.c

