QT       += network testlib

QT       -= gui

TARGET = qtslim-unit-test
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += \
    main.cpp \
    protocolserialisation.cpp \
    protocoldeserialisation.cpp \
    protocol.cpp

HEADERS += \
    protocol.h \
    protocolserialisation.h \
    protocoldeserialisation.h

DEFINES += SRCDIR=\\\"$$PWD/\\\"
