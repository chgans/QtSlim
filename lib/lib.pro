QT += core network
QT -= gui

CONFIG += c++11

TARGET = qtslim
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    slimserver.cpp \
    slimservice.cpp \
    slimstring.cpp \
    slimexecutioncontext.cpp \
    slimstringreader.cpp \
    slimstringwriter.cpp \
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
    slimapplication.cpp

HEADERS += \
    slimserver.h \
    slimservice.h \
    slimexecutioncontext.h \
    slimstring.h \
    slimstringreader.h \
    slimstringwriter.h \
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
    slimapplication.h
