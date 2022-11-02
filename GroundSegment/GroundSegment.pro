QT       += core qml quick location serialport

CONFIG += c++17

include($$PWD/src/gnss/gnss.pri)
include($$PWD/src/radio_link/receiver/radio_link.pri)
include($$PWD/src/storage/storage.pri)
include($$PWD/src/hmi/hmi.pri)

SOURCES += \
    gs_core.cpp \
    main.cpp

HEADERS += \
    gs_core.h

RESOURCES += \
    GroundSegmentUI/GroundSegmentUI.qrc

OTHER_FILES += \
    conf/params-descriptions-template.ini \
    conf/map-boundaries-template.ini

QML_IMPORT_PATH += \
    GroundSegmentUI/ \
    GroundSegmentUI/imports

# Copy settings INI files to agu-settings folder

CONFIG_DESTDIR = $$(HOME)/Documents/agu-settings
confcreatedir.commands = $$shell_path($$CONFIG_DESTDIR) & $(MKDIR) $$shell_path($$CONFIG_DESTDIR)
QMAKE_EXTRA_TARGETS += confcreatedir
PRE_TARGETDEPS += confcreatedir

PARAM_DESC_TPL = params-descriptions-template.ini
PARAM_DESC_SRC = $$PWD/conf/$$PARAM_DESC_TPL
PARAM_DESC_DESTTPL = $$CONFIG_DESTDIR/$$PARAM_DESC_TPL
desccopy.commands = $(COPY) $${PARAM_DESC_SRC} $${PARAM_DESC_DESTTPL}
POST_TARGETDEPS += desccopy
QMAKE_EXTRA_TARGETS += desccopy

MAP_BOUND_TPL = map-boundaries-template.ini
MAP_BOUND_SRC = $$PWD/conf/$$MAP_BOUND_TPL
MAP_BOUND_DESTTPL = $$CONFIG_DESTDIR/$$MAP_BOUND_TPL
mapcopy.commands = $(COPY) $${MAP_BOUND_SRC} $${MAP_BOUND_DESTTPL}
POST_TARGETDEPS += mapcopy
QMAKE_EXTRA_TARGETS += mapcopy

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
