#-------------------------------------------------
#
# Project created by QtCreator 2015-12-02T19:51:12
#
#-------------------------------------------------

QT       += core network

QT       -= gui

TARGET = app
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app
LIBS += ../lib/libqtslim.a
INCLUDEPATH += $$PWD/../lib

SOURCES += main.cpp
