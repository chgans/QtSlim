#include "instructionresulttestsuite.h"

#include "instructions/errorinstructionresult.h"
#include "instructions/okinstructionresult.h"
#include "instructions/voidinstructionresult.h"

#include <QtTest>


InstructionResultTestSuite::InstructionResultTestSuite(QObject *parent) : QObject(parent)
{

}

void InstructionResultTestSuite::initTestCase()
{

}

void InstructionResultTestSuite::cleanupTestCase()
{

}

void InstructionResultTestSuite::testInstructionResultWithValue()
{
    InstructionResult result("instruction_0", "some_value");
    QCOMPARE(result.id(), QString("instruction_0"));
    QCOMPARE(result.hasError(), false);
    QCOMPARE(result.hasResult(), true);
    QCOMPARE(result.result(), QVariant::fromValue<QString>("some_value"));
}

void InstructionResultTestSuite::testInstructionResultWithoutValue()
{
    InstructionResult result("instruction_0");
    QCOMPARE(result.id(), QString("instruction_0"));
    QCOMPARE(result.hasError(), false);
    QCOMPARE(result.hasResult(), false);
}

void InstructionResultTestSuite::testOkInstructionResult()
{
    OkInstructionResult result("ok_0");
    QCOMPARE(result.id(), QString("ok_0"));
    QCOMPARE(result.hasError(), false);
    QCOMPARE(result.hasResult(), true);
    QCOMPARE(result.result(), QVariant(QString("OK")));
}

// TBD: Do we need two InstructionResult classes? One for Application error and one for SLim error (exception?)
void InstructionResultTestSuite::testErrorInstructionResult()
{
    ErrorInstructionResult result("error_0", "Error 42: bad luck!");
    QCOMPARE(result.id(), QString("error_0"));
    QCOMPARE(result.hasError(), true);
    QCOMPARE(result.hasResult(), false);
    QCOMPARE(result.result(), QVariant(QString("__EXCEPTION__:message:<<Error 42: bad luck!>>")));
}

void InstructionResultTestSuite::testVoidInstructionResult()
{
    VoidInstructionResult result("void_0");
    QCOMPARE(result.id(), QString("void_0"));
    QCOMPARE(result.hasError(), false);
    QCOMPARE(result.hasResult(), false);
    QCOMPARE(result.result(), QVariant(QString("/__VOID__/")));
}

