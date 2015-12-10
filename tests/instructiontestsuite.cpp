#include "instructiontestsuite.h"

#include "instructions/instructionexecutor.h"
#include "instructions/assigninstruction.h"
#include "instructions/callandassigninstruction.h"
#include "instructions/callinstruction.h"
#include "instructions/importinstruction.h"
#include "instructions/makeinstruction.h"

#include <QtTest>

InstructionTestSuite::InstructionTestSuite(QObject *parent) : QObject(parent)
{

}

void InstructionTestSuite::initTestCase()
{

}

void InstructionTestSuite::cleanupTestCase()
{

}

void InstructionTestSuite::testAssignInstruction()
{
    AssignInstruction instruction("id", "symbol", "value");

    QCOMPARE(instruction.instructionId(), QString("id"));
    QCOMPARE(instruction.symbolName(), QString("symbol"));
    QCOMPARE(instruction.symbolValue(), QString("value"));
}

void InstructionTestSuite::testCallAndAssignInstruction()
{
    CallAndAssignInstruction instruction("id", "symbol", "instance", "method",
                                         QVariantList() << "value1" << "value2");

    QCOMPARE(instruction.instructionId(), QString("id"));
    QCOMPARE(instruction.symbolName(), QString("symbol"));
    QCOMPARE(instruction.instanceName(), QString("instance"));
    QCOMPARE(instruction.methodName(), QString("method"));
    QCOMPARE(instruction.arguments(), QVariantList() << "value1" << "value2");
}

void InstructionTestSuite::testCallInstruction()
{
    CallInstruction instruction("id", "instance", "method",
                                QVariantList() << "value1" << "value2");

    QCOMPARE(instruction.instructionId(), QString("id"));
    QCOMPARE(instruction.instanceName(), QString("instance"));
    QCOMPARE(instruction.methodName(), QString("method"));
    QCOMPARE(instruction.arguments(), QVariantList() << "value1" << "value2");
}

void InstructionTestSuite::testImportInstruction()
{
    ImportInstruction instruction("id", "path");

    QCOMPARE(instruction.instructionId(), QString("id"));
    QCOMPARE(instruction.path(), QString("path"));
}

void InstructionTestSuite::testMakeInstruction()
{
    MakeInstruction instruction("id", "instance", "class",
                                QVariantList() << "value1" << "value2");

    QCOMPARE(instruction.instructionId(), QString("id"));
    QCOMPARE(instruction.instanceName(), QString("instance"));
    QCOMPARE(instruction.className(), QString("class"));
    QCOMPARE(instruction.arguments(), QVariantList() << "value1" << "value2");
}
