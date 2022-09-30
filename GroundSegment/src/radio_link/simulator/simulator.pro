TEMPLATE = app

CONFIG += sdk_no_version_check

include(../common/common.pri)

HEADERS += \
    uav_model.h \
    handlers/send_attitude_handler.h \
    handlers/send_gps_raw_handler.h \
    handlers/send_home_position_handler.h \
    handlers/send_position_handler.h \
    handlers/send_system_status_handler.h \
    handlers/send_vfr_hud_handler.h

SOURCES += \
    uav_model.cpp \
    main.cpp \
    uav_communicator_factory.cpp \
    handlers/send_attitude_handler.cpp \
    handlers/send_gps_raw_handler.cpp \
    handlers/send_home_position_handler.cpp \
    handlers/send_position_handler.cpp \
    handlers/send_system_status_handler.cpp \
    handlers/send_vfr_hud_handler.cpp
