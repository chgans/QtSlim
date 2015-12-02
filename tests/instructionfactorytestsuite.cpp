#include "instructionfactorytestsuite.h"

#include "instructions/instructionfactory.h"
#include "instructions/assigninstruction.h"
#include "instructions/callinstruction.h"
#include "instructions/callandassigninstruction.h"
#include "instructions/importinstruction.h"
#include "instructions/makeinstruction.h"

#include <QtTest>

InstructionFactoryTestSuite::InstructionFactoryTestSuite(QObject *parent) : QObject(parent)
{

}

void InstructionFactoryTestSuite::testCreateAssignInstruction()
{
    QVariantList words;
    words << "id"
          << "assign"
          << "symbol"
          << "value";

    Instruction *abstractInstruction = InstructionFactory::createInstruction(words);

    AssignInstruction *instruction = dynamic_cast<AssignInstruction*>(abstractInstruction);
    QVERIFY(instruction != nullptr);

    QCOMPARE(instruction->instructionId(), QString("id"));
    QCOMPARE(instruction->symbolName(), QString("symbol"));
    QCOMPARE(instruction->symbolValue(), QString("value"));
}

void InstructionFactoryTestSuite::testCreateCallInstruction()
{
    QVariantList words;
    words << "id"
          << "call"
          << "instance"
          << "method"
          << "arg1"
          << "arg2";

    Instruction *abstractInstruction = InstructionFactory::createInstruction(words);

    CallInstruction *instruction = dynamic_cast<CallInstruction*>(abstractInstruction);
    QVERIFY(instruction != nullptr);

    QCOMPARE(instruction->instructionId(), QString("id"));
    QCOMPARE(instruction->instanceName(), QString("instance"));
    QCOMPARE(instruction->methodName(), QString("method"));
    QCOMPARE(instruction->arguments(), QVariantList() << "arg1" << "arg2");
}

void InstructionFactoryTestSuite::testCreateCallAndAssignInstruction()
{
    QVariantList words;
    words << "id"
          << "callandassign"
          << "symbol"
          << "instance"
          << "method"
          << "arg1"
          << "arg2";

    Instruction *abstractInstruction = InstructionFactory::createInstruction(words);

    CallAndAssignInstruction *instruction = dynamic_cast<CallAndAssignInstruction*>(abstractInstruction);
    QVERIFY(instruction != nullptr);

    QCOMPARE(instruction->instructionId(), QString("id"));
    QCOMPARE(instruction->symbolName(), QString("symbol"));
    QCOMPARE(instruction->instanceName(), QString("instance"));
    QCOMPARE(instruction->methodName(), QString("method"));
    QCOMPARE(instruction->arguments(), QVariantList() << "arg1" << "arg2");
}

void InstructionFactoryTestSuite::testCreateImportInstruction()
{
    QVariantList words;
    words << "id"
          << "import"
          << "path";

    Instruction *abstractInstruction = InstructionFactory::createInstruction(words);

    ImportInstruction *instruction = dynamic_cast<ImportInstruction*>(abstractInstruction);
    QVERIFY(instruction != nullptr);

    QCOMPARE(instruction->instructionId(), QString("id"));
    QCOMPARE(instruction->path(), QString("path"));
}

void InstructionFactoryTestSuite::testCreateMakeInstruction()
{
    QVariantList words;
    words << "id"
          << "make"
          << "instance"
          << "class"
          << "arg1"
          << "arg2";

    Instruction *abstractInstruction = InstructionFactory::createInstruction(words);

    MakeInstruction *instruction = dynamic_cast<MakeInstruction*>(abstractInstruction);
    QVERIFY(instruction != nullptr);

    QCOMPARE(instruction->instructionId(), QString("id"));
    QCOMPARE(instruction->instanceName(), QString("instance"));
    QCOMPARE(instruction->className(), QString("class"));
    QCOMPARE(instruction->arguments(), QVariantList() << "arg1" << "arg2");
}

