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
    instructions/successinstructionresult.cpp \
    instructions/voidinstructionresult.cpp \
    instructions/resultencoder.cpp \
    protocol/slimserialiser.cpp \
    protocol/slimdeserialiser.cpp \
    execution/division.cpp \
    execution/metaobjectexecutor.cpp

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
    instructions/successinstructionresult.h \
    instructions/voidinstructionresult.h \
    instructions/resultencoder.h \
    protocol/slimserialiser.h \
    protocol/slimdeserialiser.h \
    execution/division.h \
    execution/metaobjectexecutor.h
