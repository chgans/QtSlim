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

#include "protocol/slimserialiser.h"

class ProtocolSerialisationTest : public QObject
{
    Q_OBJECT

public:
    ProtocolSerialisationTest(QObject *parent = 0);

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testCanSerialiseString_data();
    void testCanSerialiseString();
    void testCanSerialiseInteger_data();
    void testCanSerialiseInteger();
    void testCanSerialiseFloat_data();
    void testCanSerialiseFloat();
    void testCanSerialiseBoolean_data();
    void testCanSerialiseBoolean();
    void testCanSerialiseStringList_data();
    void testCanSerialiseStringList();
};

ProtocolSerialisationTest::ProtocolSerialisationTest(QObject *parent):
    QObject(parent)
{
}

void ProtocolSerialisationTest::initTestCase()
{
}

void ProtocolSerialisationTest::cleanupTestCase()
{
}

void ProtocolSerialisationTest::testCanSerialiseString_data()
{
    QTest::addColumn<QString>("input");
    QTest::addColumn<QString>("output");

    QTest::newRow("Null string")
            << QString()
            << "000000:";
    QTest::newRow("Empty string")
            << ""
            << "000000:";
    QTest::newRow("Simple string")
            << "Hello World!"
            << "000012:Hello World!";
    QTest::newRow("UTF-8 string")
            << "مرحبا بالعالم!"
            << "000014:مرحبا بالعالم!";
}

void ProtocolSerialisationTest::testCanSerialiseString()
{
    QFETCH(QString, input);
    QFETCH(QString, output);
    QString deserialised = SlimSerialiser::serialise(QVariant::fromValue<QString>(input));
    QCOMPARE(deserialised, output);
    QEXPECT_FAIL("Null string", "TBD", Continue);
    QEXPECT_FAIL("Empty string", "TBD", Continue);
    QCOMPARE(deserialised.isEmpty(), input.isEmpty());
    QEXPECT_FAIL("Null string", "TBD", Continue);
    QCOMPARE(deserialised.isNull(), input.isNull());
}

void ProtocolSerialisationTest::testCanSerialiseInteger_data()
{
    QTest::addColumn<int>("input");
    QTest::addColumn<QString>("output");

    QTest::newRow("Small negative")
            << int(-123)
            << "000004:-123";
    QTest::newRow("Zero")
            << int(0)
            << "000001:0";
    QTest::newRow("Small positive")
            << int(321)
            << "000003:321";
    QTest::newRow("Big positive")
            << int(qPow(2, 31) - 1)
            << "000010:2147483647";
}

void ProtocolSerialisationTest::testCanSerialiseInteger()
{
    QFETCH(int, input);
    QFETCH(QString, output);
    QCOMPARE(SlimSerialiser::serialise(QVariant::fromValue<int>(input)), output);
}

void ProtocolSerialisationTest::testCanSerialiseFloat_data()
{
    QTest::addColumn<qreal>("input");
    QTest::addColumn<QString>("output");

    QTest::newRow("Standard format")
            << qreal(3.14)
            << "000004:3.14";
    QTest::newRow("Scientific format")
            << qreal(-1.3E11)
            << "000008:-1.3e+11";
    QTest::newRow("Restricted precision")
            << qreal(3.141592654)
            << "000008:3.141593";
}

void ProtocolSerialisationTest::testCanSerialiseFloat()
{
    QFETCH(qreal, input);
    QFETCH(QString, output);
    QCOMPARE(SlimSerialiser::serialise(QVariant::fromValue<qreal>(input)), output);
}

void ProtocolSerialisationTest::testCanSerialiseBoolean_data()
{
    QTest::addColumn<bool>("input");
    QTest::addColumn<QString>("output");

    QTest::newRow("False")
            << false
            << "000005:false";
    QTest::newRow("True")
            << true
            << "000004:true";
}

void ProtocolSerialisationTest::testCanSerialiseBoolean()
{
    QFETCH(bool, input);
    QFETCH(QString, output);
    QCOMPARE(SlimSerialiser::serialise(QVariant::fromValue<bool>(input)), output);
}

void ProtocolSerialisationTest::testCanSerialiseStringList_data()
{
    QTest::addColumn<QString>("serialised");
    QTest::addColumn<QVariantList>("deserialised");

    QTest::newRow("Empty list")
            << "000009:[000000:]"
            << QVariantList();
    QTest::newRow("List with one string element")
            << "000025:[000001:000008:Hi doug.:]"
            << (QVariantList()
                << "Hi doug."
                );
    QTest::newRow("List with two string elements")
            << "000032:[000002:000002:Hi:000005:doug.:]"
            << (QVariantList()
                << "Hi"
                << "doug."
                );
    QTest::newRow("List with one list of string")
            << "000049:[000001:000032:[000002:000002:Hi:000005:doug.:]:]"
            << (QVariantList()
                << QVariant::fromValue<QVariantList>(QVariantList()
                    << QVariant::fromValue<QString>("Hi")
                    << QVariant::fromValue<QString>("doug.")
                    )
                );
    QTest::newRow("List with two lists of string")
            << "000101:[000002:000032:[000002:000002:Hi:000005:doug.:]:000044:[000003:000005:Hello:000005:World:000001:!:]:]"
            << (QVariantList()
                << QVariant::fromValue<QVariantList>(QVariantList()
                    << QVariant::fromValue<QString>("Hi")
                    << QVariant::fromValue<QString>("doug.")
                    )
                << QVariant::fromValue<QVariantList>(QVariantList()
                    << QVariant::fromValue<QString>("Hello")
                    << QVariant::fromValue<QString>("World")
                    << QVariant::fromValue<QString>("!")
                    )
                );
    QTest::newRow("List with nested lists")
            << "000181:[000005:000017:decisionTable_0_1:000004:call:000015:decisionTable_0:000005:table:000091:[000002:000035:[000002:000004:Name:000006:Value?:]:000031:[000002:000003:foo:000003:bar:]:]:]"
            << (QVariantList()
                << "decisionTable_0_1"
                << "call"
                << "decisionTable_0"
                << "table"
                << QVariant::fromValue<QVariantList>(QVariantList()
                    << QVariant::fromValue<QVariantList>(QVariantList()
                        << "Name"
                        << "Value?"
                        )
                    << QVariant::fromValue<QVariantList>(QVariantList()
                        << "foo"
                        << "bar"
                        )
                    )
                );
}

void ProtocolSerialisationTest::testCanSerialiseStringList()
{
    QFETCH(QString, serialised);
    QFETCH(QVariantList, deserialised);
    QCOMPARE(SlimSerialiser::serialise(deserialised), serialised);
}

QTEST_MAIN(ProtocolSerialisationTest)

#include "tst_protocolserialisation.moc"
