#include "instructionfactorytestsuite.h"

#include "instructions/instructionfactory.h"
#include "instructions/assigninstruction.h"
#include "instructions/callinstruction.h"
#include "instructions/callandassigninstruction.h"
#include "instructions/importinstruction.h"
#include "instructions/makeinstruction.h"
#include "slimstring.h"

#include <QtTest>

InstructionFactoryTestSuite::InstructionFactoryTestSuite(QObject *parent) : QObject(parent)
{

}

void InstructionFactoryTestSuite::testCreateAssignInstruction()
{
    SlimStringList words;
    words << SlimString("000002:id")
          << SlimString("000006:assign")
          << SlimString("000006:symbol")
          << SlimString("000005:value");

    Instruction *abstractInstruction = InstructionFactory::createInstruction(words);

    AssignInstruction *instruction = dynamic_cast<AssignInstruction*>(abstractInstruction);
    QVERIFY(instruction != nullptr);

    QCOMPARE(instruction->instructionId(), QString("id"));
    QCOMPARE(instruction->symbolName(), QString("symbol"));
    QCOMPARE(instruction->symbolValue(), QString("value"));
}

void InstructionFactoryTestSuite::testCreateCallInstruction()
{
    SlimStringList words;
    words << SlimString("000002:id")
          << SlimString("000004:call")
          << SlimString("000008:instance")
          << SlimString("000006:method")
          << SlimString("000009:arguments");

    Instruction *abstractInstruction = InstructionFactory::createInstruction(words);

    CallInstruction *instruction = dynamic_cast<CallInstruction*>(abstractInstruction);
    QVERIFY(instruction != nullptr);

    QCOMPARE(instruction->instructionId(), QString("id"));
    QCOMPARE(instruction->instanceName(), QString("instance"));
    QCOMPARE(instruction->methodName(), QString("method"));
    QEXPECT_FAIL("", "FIXME", Continue);
    QCOMPARE(instruction->arguments(), QStringList() << "arg1" << "arg2");
}

void InstructionFactoryTestSuite::testCreateCallAndAssignInstruction()
{
    SlimStringList words;
    words << SlimString("000002:id")
          << SlimString("000013:callandassign")
          << SlimString("000006:symbol")
          << SlimString("000008:instance")
          << SlimString("000006:method")
          << SlimString("000009:arguments");

    Instruction *abstractInstruction = InstructionFactory::createInstruction(words);

    CallAndAssignInstruction *instruction = dynamic_cast<CallAndAssignInstruction*>(abstractInstruction);
    QVERIFY(instruction != nullptr);

    QCOMPARE(instruction->instructionId(), QString("id"));
    QCOMPARE(instruction->symbolName(), QString("symbol"));
    QCOMPARE(instruction->instanceName(), QString("instance"));
    QCOMPARE(instruction->methodName(), QString("method"));
    QEXPECT_FAIL("", "FIXME", Continue);
    QCOMPARE(instruction->arguments(), QStringList() << "arg1" << "arg2");
}

void InstructionFactoryTestSuite::testCreateImportInstruction()
{
    SlimStringList words;
    words << SlimString("000002:id")
          << SlimString("000006:import")
          << SlimString("000004:path");

    Instruction *abstractInstruction = InstructionFactory::createInstruction(words);

    ImportInstruction *instruction = dynamic_cast<ImportInstruction*>(abstractInstruction);
    QVERIFY(instruction != nullptr);

    QCOMPARE(instruction->instructionId(), QString("id"));
    QCOMPARE(instruction->path(), QString("path"));
}

void InstructionFactoryTestSuite::testCreateMakeInstruction()
{
    SlimStringList words;
    words << SlimString("000002:id")
          << SlimString("000004:make")
          << SlimString("000008:instance")
          << SlimString("000005:class")
          << SlimString("000009:arguments");

    Instruction *abstractInstruction = InstructionFactory::createInstruction(words);

    MakeInstruction *instruction = dynamic_cast<MakeInstruction*>(abstractInstruction);
    QVERIFY(instruction != nullptr);

    QCOMPARE(instruction->instructionId(), QString("id"));
    QCOMPARE(instruction->instanceName(), QString("instance"));
    QCOMPARE(instruction->className(), QString("class"));
    QEXPECT_FAIL("", "FIXME", Continue);
    QCOMPARE(instruction->arguments(), QStringList() << "arg1" << "arg2");
}

