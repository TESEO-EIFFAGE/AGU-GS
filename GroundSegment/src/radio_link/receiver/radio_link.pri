include(../common/common.pri)

HEADERS += \
    $$PWD/receiver_communicator_factory.h \
    $$PWD/handlers/agu_motor_handler.h \
    $$PWD/handlers/agu_system_handler.h \
    $$PWD/handlers/agu_telemetry_handler.h \
    $$PWD/handlers/attitude_handler.h \
    $$PWD/radio_link.h

SOURCES += \
    $$PWD/receiver_communicator_factory.cpp \
    $$PWD/handlers/agu_motor_handler.cpp \
    $$PWD/handlers/agu_system_handler.cpp \
    $$PWD/handlers/agu_telemetry_handler.cpp \
    $$PWD/handlers/attitude_handler.cpp \
    $$PWD/radio_link.cpp
