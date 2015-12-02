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
CONFIG   += c++11

TEMPLATE = app

SOURCES += main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../lib/release/ -lqtslim
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../lib/debug/ -lqtslim
else:unix: LIBS += -L$$OUT_PWD/../lib/ -lqtslim

INCLUDEPATH += $$PWD/../lib
DEPENDPATH += $$PWD/../lib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../lib/release/libqtslim.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../lib/debug/libqtslim.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../lib/release/qtslim.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../lib/debug/qtslim.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../lib/libqtslim.a
