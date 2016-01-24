/****************************************************************************
**
** Copyright (C) 2016 Christian Gagneraud <chgans@gna.org>
** All rights reserved.
**
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 3 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL3 included in the packaging of this file.
** Please review the following information to ensure the GNU Lesser General
** Public License version 3 requirements will be met:
** https://www.gnu.org/licenses/lgpl-3.0.html.
**
****************************************************************************/

#include <QtTest>
#include <QCoreApplication>

#include "instructions/errorinstructionresult.h"
#include "instructions/okinstructionresult.h"
#include "instructions/voidinstructionresult.h"

class InstructionResultTest : public QObject
{
    Q_OBJECT
public:
    explicit InstructionResultTest(QObject *parent = 0);

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testInstructionResultWithValue();
    void testInstructionResultWithoutValue();
    void testOkInstructionResult();
    void testErrorInstructionResult();
    void testVoidInstructionResult();
};

InstructionResultTest::InstructionResultTest(QObject *parent) : QObject(parent)
{

}

void InstructionResultTest::initTestCase()
{

}

void InstructionResultTest::cleanupTestCase()
{

}

void InstructionResultTest::testInstructionResultWithValue()
{
    InstructionResult result("instruction_0", "some_value");
    QCOMPARE(result.id(), QString("instruction_0"));
    QCOMPARE(result.hasError(), false);
    QCOMPARE(result.hasResult(), true);
    QCOMPARE(result.result(), QVariant::fromValue<QString>("some_value"));
}

void InstructionResultTest::testInstructionResultWithoutValue()
{
    InstructionResult result("instruction_0");
    QCOMPARE(result.id(), QString("instruction_0"));
    QCOMPARE(result.hasError(), false);
    QCOMPARE(result.hasResult(), false);
}

void InstructionResultTest::testOkInstructionResult()
{
    OkInstructionResult result("ok_0");
    QCOMPARE(result.id(), QString("ok_0"));
    QCOMPARE(result.hasError(), false);
    QCOMPARE(result.hasResult(), true);
    QCOMPARE(result.result(), QVariant(QString("OK")));
}

// TBD: Do we need two InstructionResult classes? One for Application error and one for SLim error (exception?)
void InstructionResultTest::testErrorInstructionResult()
{
    ErrorInstructionResult result("error_0", "Error 42: bad luck!");
    QCOMPARE(result.id(), QString("error_0"));
    QCOMPARE(result.hasError(), true);
    QCOMPARE(result.hasResult(), false);
    QCOMPARE(result.result(), QVariant(QString("__EXCEPTION__:message:<<Error 42: bad luck!>>")));
}

void InstructionResultTest::testVoidInstructionResult()
{
    VoidInstructionResult result("void_0");
    QCOMPARE(result.id(), QString("void_0"));
    QCOMPARE(result.hasError(), false);
    QCOMPARE(result.hasResult(), false);
    QCOMPARE(result.result(), QVariant(QString("/__VOID__/")));
}

QTEST_MAIN(InstructionResultTest)

#include "tst_instructionresult.moc"
