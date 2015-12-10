#include "metamethodlisttestsuite.h"
#include "introspection/metaobjectinspector.h"
#include "fixtures/basicqobectfixture.h"

#include <QtTest>

const QMetaObject MetaMethodListTestSuite::META_OBJECT = BasicQObectFixture::staticMetaObject;

MetaMethodListTestSuite::MetaMethodListTestSuite(QObject *parent) : QObject(parent)
{

}

void MetaMethodListTestSuite::initTestCase()
{

}

void MetaMethodListTestSuite::cleanupTestCase()
{

}

void MetaMethodListTestSuite::testFilterByName()
{
    MetaObjectInspector inspector(META_OBJECT);
    MetaMethodList methods = inspector.allMethods().filterByName("functionMethod");
    QCOMPARE(methods.count(), 3);
    QCOMPARE(methods[0].methodSignature(), QByteArray("functionMethod()"));
    QCOMPARE(methods[1].methodSignature(), QByteArray("functionMethod(int)"));
    QCOMPARE(methods[2].methodSignature(), QByteArray("functionMethod(int,bool)"));
}

void MetaMethodListTestSuite::testFilterByName_NullName()
{
    MetaObjectInspector inspector(META_OBJECT);
    MetaMethodList methods = inspector.allMethods().filterByName(QString());
    QCOMPARE(methods.count(), 0);
}

void MetaMethodListTestSuite::testFilterByName_EmptyName()
{
    MetaObjectInspector inspector(META_OBJECT);
    MetaMethodList methods = inspector.allMethods().filterByName(QString(""));
    QCOMPARE(methods.count(), 0);
}

void MetaMethodListTestSuite::testFilterByName_NoneFound()
{
    MetaObjectInspector inspector(META_OBJECT);
    MetaMethodList methods = inspector.allMethods().filterByName("doesntexist");
    QCOMPARE(methods.count(), 0);
}

void MetaMethodListTestSuite::testFilterByArgumentCount()
{
    MetaObjectInspector inspector(META_OBJECT);
    MetaMethodList methods = inspector.allMethods().filterByArgumentCount(2);
    QCOMPARE(methods.count(), 3);
    QCOMPARE(methods[0].methodSignature(), QByteArray("signalMethodWithTwoParams(bool,double)"));
    QCOMPARE(methods[1].methodSignature(), QByteArray("slotMethodWithTwoParams(QString,QString)"));
    QCOMPARE(methods[2].methodSignature(), QByteArray("functionMethod(int,bool)"));
}

void MetaMethodListTestSuite::testFilterByArgumentCount_NegativeCount()
{
    MetaObjectInspector inspector(META_OBJECT);
    MetaMethodList methods = inspector.allMethods().filterByArgumentCount(-1);
    QCOMPARE(methods.count(), 0);
}

void MetaMethodListTestSuite::testFilterByArgumentCount_NoneFound()
{
    MetaObjectInspector inspector(META_OBJECT);
    MetaMethodList methods = inspector.allMethods().filterByArgumentCount(42);
    QCOMPARE(methods.count(), 0);
}
