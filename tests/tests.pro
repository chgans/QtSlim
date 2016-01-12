QT       += network testlib network

QT       -= gui

TARGET = qtslim-unit-test
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++11

TEMPLATE = app

SOURCES += \
    main.cpp \
    protocolserialisation.cpp \
    protocoldeserialisation.cpp \
    instructionfactorytestsuite.cpp \
    resultencodertestsuite.cpp \
    instructionresulttestsuite.cpp \
    metamethodlisttestsuite.cpp \
    metaobjectinspectortestsuite.cpp \
    metamethodinvokertestsuite.cpp \
    metamethodinspectortestsuite.cpp \
    fixtures/basicqobectfixture.cpp \
    fixtures/division.cpp \
    instructiontestsuite.cpp \
    metaobjectmakertestsuite.cpp

HEADERS += \
    protocolserialisation.h \
    protocoldeserialisation.h \
    instructionfactorytestsuite.h \
    resultencodertestsuite.h \
    instructionresulttestsuite.h \
    metamethodlisttestsuite.h \
    metaobjectinspectortestsuite.h \
    metamethodinvokertestsuite.h \
    metamethodinspectortestsuite.h \
    fixtures/basicqobectfixture.h \
    fixtures/division.h \
    instructiontestsuite.h \
    metaobjectmakertestsuite.h

DEFINES += SRCDIR=\\\"$$PWD/\\\"

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
