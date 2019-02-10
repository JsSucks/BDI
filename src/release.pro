TEMPLATE = app
TARGET = BDI
DESTDIR = ../bin/x64/Release
QT += core network gui svg widgets
CONFIG += debug
DEFINES += _UNICODE QT_NETWORK_LIB QT_SVG_LIB QT_WIDGETS_LIB
INCLUDEPATH += ./GeneratedFiles \
    . \
    ./GeneratedFiles/Release
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/Release
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
include(BDI.pri)
win32:RC_FILE = BDI.rc
