QT += core network
QT -= gui

CONFIG += c++11

TARGET = qtslim
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    slimapplication.cpp \
    slimserver.cpp \
    slimservice.cpp \
    slimexecutioncontext.cpp \
    protocol/slimstringreader.cpp \
    protocol/slimstringwriter.cpp \
    instructions/assigninstruction.cpp \
    instructions/callandassigninstruction.cpp \
    instructions/callinstruction.cpp \
    instructions/errorinstructionresult.cpp \
    instructions/importinstruction.cpp \
    instructions/instruction.cpp \
    instructions/instructionexecutor.cpp \
    instructions/instructionfactory.cpp \
    instructions/instructionresult.cpp \
    instructions/invalidinstruction.cpp \
    instructions/makeinstruction.cpp \
    instructions/okinstructionresult.cpp \
    instructions/voidinstructionresult.cpp \
    instructions/resultencoder.cpp \
    protocol/slimserialiser.cpp \
    protocol/slimdeserialiser.cpp \
    execution/metaobjectexecutor.cpp \
    introspection/metamethodlist.cpp \
    introspection/metamethodinspector.cpp \
    introspection/metaobjectinspector.cpp \
    introspection/metamethodinvoker.cpp \
    introspection/metaobjectmaker.cpp \
    fixtureloader.cpp \
    slimlibraryhelper.cpp \
    fixture/idecisiontable.cpp

HEADERS += \
    slimapplication.h \
    slimserver.h \
    slimservice.h \
    slimexecutioncontext.h \
    protocol/slimstringreader.h \
    protocol/slimstringwriter.h \
    instructions/assigninstruction.h \
    instructions/callandassigninstruction.h \
    instructions/callinstruction.h \
    instructions/errorinstructionresult.h \
    instructions/importinstruction.h \
    instructions/instruction.h \
    instructions/instructionexecutor.h \
    instructions/instructionfactory.h \
    instructions/instructionresult.h \
    instructions/invalidinstruction.h \
    instructions/makeinstruction.h \
    instructions/okinstructionresult.h \
    instructions/voidinstructionresult.h \
    instructions/resultencoder.h \
    protocol/slimserialiser.h \
    protocol/slimdeserialiser.h \
    execution/metaobjectexecutor.h \
    introspection/metamethodlist.h \
    introspection/metamethodinspector.h \
    introspection/metaobjectinspector.h \
    introspection/metamethodinvoker.h \
    introspection/metaobjectmaker.h \
    ifixtureprovider.h \
    fixtureloader.h \
    slimlibraryhelper.h \
    fixture/idecisiontable.h \
    fixture/irowfixture.h
