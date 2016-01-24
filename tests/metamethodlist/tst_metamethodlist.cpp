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

#include "introspection/metaobjectinspector.h"
#include "../fixtures/basicqobectfixture.h"

class MetaMethodListTest : public QObject
{
    Q_OBJECT
public:
    explicit MetaMethodListTest(QObject *parent = 0);

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testFilterByName();
    void testFilterByName_NullName();
    void testFilterByName_EmptyName();
    void testFilterByName_NoneFound();
    void testFilterByArgumentCount();
    void testFilterByArgumentCount_NegativeCount();
    void testFilterByArgumentCount_NoneFound();

private:
    static const QMetaObject META_OBJECT;
};

const QMetaObject MetaMethodListTest::META_OBJECT = BasicQObectFixture::staticMetaObject;

MetaMethodListTest::MetaMethodListTest(QObject *parent) : QObject(parent)
{

}

void MetaMethodListTest::initTestCase()
{

}

void MetaMethodListTest::cleanupTestCase()
{

}

void MetaMethodListTest::testFilterByName()
{
    MetaObjectInspector inspector(META_OBJECT);
    MetaMethodList methods = inspector.allMethods().filterByName("functionMethod");
    QCOMPARE(methods.count(), 3);
    QCOMPARE(methods[0].methodSignature(), QByteArray("functionMethod()"));
    QCOMPARE(methods[1].methodSignature(), QByteArray("functionMethod(int)"));
    QCOMPARE(methods[2].methodSignature(), QByteArray("functionMethod(int,bool)"));
}

void MetaMethodListTest::testFilterByName_NullName()
{
    MetaObjectInspector inspector(META_OBJECT);
    MetaMethodList methods = inspector.allMethods().filterByName(QString());
    QCOMPARE(methods.count(), 0);
}

void MetaMethodListTest::testFilterByName_EmptyName()
{
    MetaObjectInspector inspector(META_OBJECT);
    MetaMethodList methods = inspector.allMethods().filterByName(QString(""));
    QCOMPARE(methods.count(), 0);
}

void MetaMethodListTest::testFilterByName_NoneFound()
{
    MetaObjectInspector inspector(META_OBJECT);
    MetaMethodList methods = inspector.allMethods().filterByName("doesntexist");
    QCOMPARE(methods.count(), 0);
}

void MetaMethodListTest::testFilterByArgumentCount()
{
    MetaObjectInspector inspector(META_OBJECT);
    MetaMethodList methods = inspector.allMethods().filterByArgumentCount(2);
    QCOMPARE(methods.count(), 3);
    QCOMPARE(methods[0].methodSignature(), QByteArray("signalMethodWithTwoParams(bool,double)"));
    QCOMPARE(methods[1].methodSignature(), QByteArray("slotMethodWithTwoParams(QString,QString)"));
    QCOMPARE(methods[2].methodSignature(), QByteArray("functionMethod(int,bool)"));
}

void MetaMethodListTest::testFilterByArgumentCount_NegativeCount()
{
    MetaObjectInspector inspector(META_OBJECT);
    MetaMethodList methods = inspector.allMethods().filterByArgumentCount(-1);
    QCOMPARE(methods.count(), 0);
}

void MetaMethodListTest::testFilterByArgumentCount_NoneFound()
{
    MetaObjectInspector inspector(META_OBJECT);
    MetaMethodList methods = inspector.allMethods().filterByArgumentCount(42);
    QCOMPARE(methods.count(), 0);
}

QTEST_MAIN(MetaMethodListTest)

#include "tst_metamethodlist.moc"
