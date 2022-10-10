include(../common/common.pri)

INCLUDEPATH += \
    $$PWD \
    $$PWD/../3dparty/mavlink_v2 \
    $$PWD/../3dparty/mavlink_v2/AGU_MAVLINK

HEADERS += \
    $$PWD/handlers/agu_guidance_handler.h \
    $$PWD/handlers/agu_radiolink_handler.h \
    $$PWD/handlers/agu_storage_handler.h \
    $$PWD/receiver_communicator_factory.h \
    $$PWD/handlers/agu_motor_handler.h \
    $$PWD/handlers/agu_system_handler.h \
    $$PWD/handlers/agu_telemetry_handler.h \
    $$PWD/radio_link.h

SOURCES += \
    $$PWD/handlers/agu_guidance_handler.cpp \
    $$PWD/handlers/agu_radiolink_handler.cpp \
    $$PWD/handlers/agu_storage_handler.cpp \
    $$PWD/receiver_communicator_factory.cpp \
    $$PWD/handlers/agu_motor_handler.cpp \
    $$PWD/handlers/agu_system_handler.cpp \
    $$PWD/handlers/agu_telemetry_handler.cpp \
    $$PWD/radio_link.cpp
