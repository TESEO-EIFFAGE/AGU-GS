TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += sdk_no_version_check
CONFIG += c++11

include(../common/common.pri)

HEADERS += \
    handlers/agu_send_system_handler.h \
    uav_communicator_factory.h \
    uav_model.h

SOURCES += \
    handlers/agu_send_system_handler.cpp \
    uav_communicator_factory.cpp \
    uav_model.cpp \
    main.cpp

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
