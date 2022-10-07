TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += sdk_no_version_check
CONFIG += c++11

include(../common/common.pri)

HEADERS += \
    handlers/agu_send_guidance_handler.h \
    handlers/agu_send_motor_handler.h \
    handlers/agu_send_radiolink_handler.h \
    handlers/agu_send_storage_handler.h \
    handlers/agu_send_system_handler.h \
    handlers/agu_send_telemetry_handler.h \
    uav_communicator_factory.h \
    uav_model.h

SOURCES += \
    handlers/agu_send_guidance_handler.cpp \
    handlers/agu_send_motor_handler.cpp \
    handlers/agu_send_radiolink_handler.cpp \
    handlers/agu_send_storage_handler.cpp \
    handlers/agu_send_system_handler.cpp \
    handlers/agu_send_telemetry_handler.cpp \
    uav_communicator_factory.cpp \
    uav_model.cpp \
    main.cpp

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
