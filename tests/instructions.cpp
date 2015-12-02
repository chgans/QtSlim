#include "instructions.h"

#include "instructions/instructionexecutor.h"
#include "instructions/assigninstruction.h"
#include "instructions/callandassigninstruction.h"
#include "instructions/callinstruction.h"

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
    CallAndAssignInstruction instruction("id", "symbol", "instance", "method", QVariantList() << "value1" << "value2");
    QCOMPARE(instruction.instructionId(), QString("id"));
    QCOMPARE(instruction.symbolName(), QString("symbol"));
    QCOMPARE(instruction.instanceName(), QString("instance"));
    QCOMPARE(instruction.methodName(), QString("method"));
    QCOMPARE(instruction.arguments(), QVariantList() << "value1" << "value2");
}

void InstructionTestSuite::testCallInstruction()
{

}

void InstructionTestSuite::testImportInstruction()
{

}

void InstructionTestSuite::testMakeInstruction()
{

}


#if 0
class InstructionExecutorMock: public InstructionExecutor
{
public:
    InstructionExecutorMock() {}

    // InstructionExecutor interface
public:
    void assign(const QString &name, const QString &value)
    {
    }

    QString callAndAssign(const QString &symbolName, const QString &instanceName, const QString &methodName, const QVariantList &arguments)
    {
    }

    QString call(const QString &instanceName, const QString &methodName, const QVariantList &arguments)
    {
    }

    void import(const QString &path)
    {
    }

    void make(const QString &instanceName, const QString &className, const QVariantList &arguments)
    {
    }
};
#endif
