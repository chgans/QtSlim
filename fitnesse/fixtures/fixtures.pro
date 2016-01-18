#-------------------------------------------------
#
# Project created by QtCreator 2016-01-13T14:46:26
#
#-------------------------------------------------

QT       -= gui

TARGET = qtslim-fitnesse-fixtures
TEMPLATE = lib
CONFIG += plugin no_plugin_name_prefix

DEFINES += FIXTURES_LIBRARY

SOURCES += fixtureprovider.cpp \
    division.cpp \
    echofixture.cpp \
    testslim.cpp \
    pagedriver.cpp \
    testquery.cpp \
    setup.cpp \
    teardown.cpp

HEADERS += fixtureprovider.h \
    division.h \
    echofixture.h \
    testslim.h \
    pagedriver.h \
    testquery.h \
    setup.h \
    teardown.h

INCLUDEPATH += $$PWD/../../lib

unix {
    target.path = /usr/lib
    INSTALLS += target
}

DISTFILES += \
    qtslim-fitnesse-fixtures.json
