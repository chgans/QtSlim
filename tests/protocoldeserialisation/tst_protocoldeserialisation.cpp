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

#include "protocol/slimdeserialiser.h"

class ProtocolDeserialisationTest : public QObject
{
    Q_OBJECT

public:
    ProtocolDeserialisationTest(QObject *parent = 0);

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testCanDeserialiseString_data();
    void testCanDeserialiseString();
    void testCanDeserialiseInteger_data();
    void testCanDeserialiseInteger();
    void testCanDeserialiseFloat_data();
    void testCanDeserialiseFloat();
    void testCanDeserialiseBoolean_data();
    void testCanDeserialiseBoolean();
    void testCanDeserialiseStringList_data();
    void testCanDeserialiseStringList();
};

// TODO: Do not check for data conversion here

ProtocolDeserialisationTest::ProtocolDeserialisationTest(QObject *parent):
    QObject(parent)
{

}

void ProtocolDeserialisationTest::initTestCase()
{

}

void ProtocolDeserialisationTest::cleanupTestCase()
{

}

void ProtocolDeserialisationTest::testCanDeserialiseString_data()
{
    QTest::addColumn<QString>("input");
    QTest::addColumn<QString>("output");

    QTest::newRow("Null string")
            << "000000:"
            << QString();
    QTest::newRow("Empty string")
            << "000000:"
            << "";
    QTest::newRow("Simple string")
            << "000012:Hello World!"
            << "Hello World!";
    QTest::newRow("UTF-8 string")
            << "000014:مرحبا بالعالم!"
            << "مرحبا بالعالم!";
}

void ProtocolDeserialisationTest::testCanDeserialiseString()
{
    QFETCH(QString, input);
    QFETCH(QString, output);
    QString deserialised = SlimDeserialiser::deserialise(input).value<QString>();
    QCOMPARE(deserialised, output);
    QCOMPARE(deserialised.isEmpty(), output.isEmpty());
    QEXPECT_FAIL("Null string", "TBD", Continue);
    QCOMPARE(deserialised.isNull(), output.isNull());
}

void ProtocolDeserialisationTest::testCanDeserialiseInteger_data()
{
    QTest::addColumn<QString>("input");
    QTest::addColumn<int>("output");

    QTest::newRow("Small negative")
            << "000004:-123"
            << int(-123);
    QTest::newRow("Zero")
            << "000001:0"
            << int(0);
    QTest::newRow("Small positive")
            << "000003:321"
            << int(321);
    QTest::newRow("Big positive")
            << "000010:2147483647"
            << int(qPow(2, 31) - 1);
}

void ProtocolDeserialisationTest::testCanDeserialiseInteger()
{
    QFETCH(QString, input);
    QFETCH(int, output);
    int deserialised = SlimDeserialiser::deserialise(input).value<int>();
    QCOMPARE(deserialised, output);
}

void ProtocolDeserialisationTest::testCanDeserialiseFloat_data()
{
    QTest::addColumn<QString>("input");
    QTest::addColumn<qreal>("output");

    QTest::newRow("Standard format")
            << "000004:3.14"
            << qreal(3.14);
    QTest::newRow("Scientific format")
            << "000008:-1.3e+11"
            << qreal(-1.3E11);
    QTest::newRow("No restricted precision")
            << "000077:3.141592653589793238462643383279502884197169399375105820974944592307816406286"
            << qreal(3.141592653589793238462643383279502884197169399375105820974944592307816406286);

}

void ProtocolDeserialisationTest::testCanDeserialiseFloat()
{
    QFETCH(QString, input);
    QFETCH(qreal, output);
    qreal deserialised = SlimDeserialiser::deserialise(input).value<qreal>();
    QCOMPARE(deserialised, output);
}

void ProtocolDeserialisationTest::testCanDeserialiseBoolean_data()
{
    QTest::addColumn<QString>("input");
    QTest::addColumn<bool>("output");

    QTest::newRow("False as \"false\"")
            << "000005:false"
            << false;
    QTest::newRow("False as \"False\"")
            << "000005:False"
            << false;
    QTest::newRow("False as \"0\"")
            << "000001:0"
            << false;
    QTest::newRow("True as \"true\"")
            << "000004:true"
            << true;
    QTest::newRow("True as \"True\"")
            << "000004:True"
            << true;
    QTest::newRow("True as \"1\"")
            << "000001:1"
            << true;
    QTest::newRow("True as Non-zero number")
            << "000002:21"
            << true;
}

void ProtocolDeserialisationTest::testCanDeserialiseBoolean()
{
    QFETCH(QString, input);
    QFETCH(bool, output);
    bool deserialised = SlimDeserialiser::deserialise(input).value<bool>();
    QCOMPARE(deserialised, output);
}

void ProtocolDeserialisationTest::testCanDeserialiseStringList_data()
{
    QTest::addColumn<QString>("input");
    QTest::addColumn<QVariantList>("output");

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

void ProtocolDeserialisationTest::testCanDeserialiseStringList()
{
    QFETCH(QString, input);
    QFETCH(QVariantList, output);

    QVariantList deserialised = SlimDeserialiser::deserialise(input).value<QVariantList>();

    QCOMPARE(deserialised, output);
}

QTEST_MAIN(ProtocolDeserialisationTest)

#include "tst_protocoldeserialisation.moc"
