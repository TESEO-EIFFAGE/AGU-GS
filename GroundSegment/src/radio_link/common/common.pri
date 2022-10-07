QT += serialport positioning network

INCLUDEPATH += \
    $$PWD/../3dparty/mavlink_v2 \
    $$PWD/../3dparty/mavlink_v2/AGU_MAVLINK

HEADERS += \
    $$PWD/links/endpoint.h \
    $$PWD/abstract_communicator_factory.h \
    $$PWD/mavlink_communicator.h \
    $$PWD/mavlink_protocol_helpers.h \
    $$PWD/handlers/heartbeat_handler.h \
    $$PWD/handlers/abstract_handler.h \
    $$PWD/links/abstract_link.h \
    $$PWD/links/serial_link.h \
    $$PWD/links/udp_link.h

SOURCES += \
    $$PWD/abstract_communicator_factory.cpp \
    $$PWD/links/endpoint.cpp \
    $$PWD/mavlink_communicator.cpp \
    $$PWD/handlers/abstract_handler.cpp \
    $$PWD/handlers/heartbeat_handler.cpp \
    $$PWD/links/abstract_link.cpp \
    $$PWD/links/serial_link.cpp \
    $$PWD/links/udp_link.cpp

OTHER_FILES += \
    $$PWD/../3dparty/mavlink_v2/message_definitions/AGU_MAVLINK.xml
