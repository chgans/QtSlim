QT       += network testlib network

QT       -= gui

TARGET = qtslim-unit-test
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += \
    main.cpp \
    protocolserialisation.cpp \
    protocoldeserialisation.cpp \
    protocol.cpp \
    instructions.cpp

HEADERS += \
    protocol.h \
    protocolserialisation.h \
    protocoldeserialisation.h \
    instructions.h

INCLUDEPATH += $$PWD/../lib
LIBS += ../lib/libqtslim.a

DEFINES += SRCDIR=\\\"$$PWD/\\\"
