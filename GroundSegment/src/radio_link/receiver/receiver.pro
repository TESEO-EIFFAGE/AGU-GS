TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += sdk_no_version_check
CONFIG += c++11

include(../common/common.pri)

HEADERS += \
    gcs_communicator_factory.h \
    handlers/agu_motor_handler.h \
    handlers/agu_system_handler.h \
    handlers/agu_telemetry_handler.h \
    handlers/attitude_handler.h

SOURCES += \
    gcs_communicator_factory.cpp \
    handlers/agu_motor_handler.cpp \
    handlers/agu_system_handler.cpp \
    handlers/agu_telemetry_handler.cpp \
    handlers/attitude_handler.cpp \
    main.cpp

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
