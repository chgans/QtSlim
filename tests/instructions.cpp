#include "instructions.h"

#include "instructions/instructionexecutor.h"
#include "instructions/assigninstruction.h"
#include "instructions/callandassigninstruction.h"
#include "instructions/callinstruction.h"

#include <QtTest>

instructions::instructions(QObject *parent) : QObject(parent)
{

}

void instructions::initTestCase()
{

}

void instructions::cleanupTestCase()
{

}

void instructions::testAssignInstruction()
{
    AssignInstruction instruction("id", "symbol", "value");
    QCOMPARE(instruction.instructionId(), "id");
    QCOMPARE(instruction.symbolName(), "symbol");
    QCOMPARE(instruction.symbolValue(), "value");
}

void instructions::testCallAndAssignInstruction()
{
    CallAndAssignInstruction instruction("id", "symbol", "instance", "method", QVariantList() << "value1" << "value2");
    QCOMPARE(instruction.instructionId(), "id");
    QCOMPARE(instruction.symbolName(), "symbol");
    QCOMPARE(instruction.instanceName(), "instance");
    QCOMPARE(instruction.methodName(), "method");
    QCOMPARE(instruction.methodName(), QVariantList() << "value1" << "value2");
}

void instructions::testCallInstruction()
{

}

void instructions::testImportInstruction()
{

}

void instructions::testMakeInstruction()
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
