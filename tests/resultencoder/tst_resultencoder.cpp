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

#include "instructions/resultencoder.h"
#include "instructions/errorinstructionresult.h"
#include "instructions/okinstructionresult.h"
#include "instructions/voidinstructionresult.h"

class ResultEncoderTest : public QObject
{
    Q_OBJECT
public:
    explicit ResultEncoderTest(QObject *parent = 0);

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testEncodeResult();
    void testEncodeOkResult();
    void testEncodeErrorResult();
    void testEncodeVoidResult();
};

ResultEncoderTest::ResultEncoderTest(QObject *parent) : QObject(parent)
{

}

void ResultEncoderTest::initTestCase()
{

}

void ResultEncoderTest::cleanupTestCase()
{

}

void ResultEncoderTest::testEncodeResult()
{
    QEXPECT_FAIL("", "TODO", Continue);
    QVERIFY(false);
}

void ResultEncoderTest::testEncodeOkResult()
{
    QEXPECT_FAIL("", "TODO", Continue);
    QVERIFY(false);
}

void ResultEncoderTest::testEncodeErrorResult()
{
    QEXPECT_FAIL("", "TODO", Continue);
    QVERIFY(false);
}

void ResultEncoderTest::testEncodeVoidResult()
{
    QEXPECT_FAIL("", "TODO", Continue);
    QVERIFY(false);
}

QTEST_MAIN(ResultEncoderTest)

#include "tst_resultencoder.moc"
