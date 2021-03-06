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

#include <QString>
#include <QtTest>
#include <QCoreApplication>

#include "instructions/instructionexecutor.h"
#include "instructions/assigninstruction.h"
#include "instructions/callandassigninstruction.h"
#include "instructions/callinstruction.h"
#include "instructions/importinstruction.h"
#include "instructions/makeinstruction.h"

class InstructionTest : public QObject
{
    Q_OBJECT
public:
    explicit InstructionTest(QObject *parent = 0);

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testAssignInstruction();
    void testCallAndAssignInstruction();
    void testCallInstruction();
    void testImportInstruction();
    void testMakeInstruction();

};

InstructionTest::InstructionTest(QObject *parent) : QObject(parent)
{

}

void InstructionTest::initTestCase()
{

}

void InstructionTest::cleanupTestCase()
{

}

void InstructionTest::testAssignInstruction()
{
    AssignInstruction instruction("id", "symbol", "value");

    QCOMPARE(instruction.instructionId(), QString("id"));
    QCOMPARE(instruction.symbolName(), QString("symbol"));
    QCOMPARE(instruction.symbolValue(), QString("value"));
}

void InstructionTest::testCallAndAssignInstruction()
{
    CallAndAssignInstruction instruction("id", "symbol", "instance", "method",
                                         QVariantList() << "value1" << "value2");

    QCOMPARE(instruction.instructionId(), QString("id"));
    QCOMPARE(instruction.symbolName(), QString("symbol"));
    QCOMPARE(instruction.instanceName(), QString("instance"));
    QCOMPARE(instruction.methodName(), QString("method"));
    QCOMPARE(instruction.arguments(), QVariantList() << "value1" << "value2");
}

void InstructionTest::testCallInstruction()
{
    CallInstruction instruction("id", "instance", "method",
                                QVariantList() << "value1" << "value2");

    QCOMPARE(instruction.instructionId(), QString("id"));
    QCOMPARE(instruction.instanceName(), QString("instance"));
    QCOMPARE(instruction.methodName(), QString("method"));
    QCOMPARE(instruction.arguments(), QVariantList() << "value1" << "value2");
}

void InstructionTest::testImportInstruction()
{
    ImportInstruction instruction("id", "path");

    QCOMPARE(instruction.instructionId(), QString("id"));
    QCOMPARE(instruction.path(), QString("path"));
}

void InstructionTest::testMakeInstruction()
{
    MakeInstruction instruction("id", "instance", "class",
                                QVariantList() << "value1" << "value2");

    QCOMPARE(instruction.instructionId(), QString("id"));
    QCOMPARE(instruction.instanceName(), QString("instance"));
    QCOMPARE(instruction.className(), QString("class"));
    QCOMPARE(instruction.arguments(), QVariantList() << "value1" << "value2");
}

QTEST_MAIN(InstructionTest)

#include "tst_instruction.moc"
