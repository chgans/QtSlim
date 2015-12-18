#include "metamethodinspectortestsuite.h"
#include "fixtures/basicqobectfixture.h"

#include  "introspection/metaobjectinspector.h"
#include  "introspection/metamethodinspector.h"

#include <QtTest>

const QMetaObject MetaMethodInspectorTestSuite::META_OBJECT = BasicQObectFixture::staticMetaObject;

MetaMethodInspectorTestSuite::MetaMethodInspectorTestSuite(QObject *parent):
    QObject(parent)
{

}

void MetaMethodInspectorTestSuite::initTestCase()
{

}

void MetaMethodInspectorTestSuite::cleanupTestCase()
{

}

void MetaMethodInspectorTestSuite::testMethodWitParameters()
{
    QVERIFY(META_OBJECT.methodCount() > 13);
    QMetaMethod method = META_OBJECT.method(13);
    QVERIFY(method.methodSignature() == QString("functionMethod(int,bool)"));

    MetaMethodInspector inspector(method);
    QCOMPARE(inspector.parameterCount(), 2);
    QCOMPARE(inspector.parameterTypeIds(), QList<int>() << QMetaType::Int << QMetaType::Bool);
    QCOMPARE(inspector.parameterTypeNames(), QList<QByteArray>() << "int" << "bool");
}

void MetaMethodInspectorTestSuite::testMethodWithoutParameters()
{
    QVERIFY(META_OBJECT.methodCount() > 11);
    QMetaMethod method = META_OBJECT.method(11);
    QVERIFY(method.methodSignature() == QString("functionMethod()"));

    MetaMethodInspector inspector(method);
    QCOMPARE(inspector.parameterCount(), 0);
    QCOMPARE(inspector.parameterTypeIds(), QList<int>());
    QCOMPARE(inspector.parameterTypeNames(), QList<QByteArray>());
}

void MetaMethodInspectorTestSuite::testMethodWitReturnValue()
{
    QVERIFY(META_OBJECT.methodCount() > 11);
    QMetaMethod method = META_OBJECT.method(11);
    QVERIFY(method.methodSignature() == QString("functionMethod()"));

    MetaMethodInspector inspector(method);
    QCOMPARE(inspector.hasReturnValue(), true);
    QCOMPARE(inspector.returnValueTypeId(), int(QMetaType::Bool));
    QCOMPARE(inspector.returnValueTypeName(), QByteArray("bool"));
}

void MetaMethodInspectorTestSuite::testMethodWithoutReturnValue()
{
    QVERIFY(META_OBJECT.methodCount() > 8);
    QMetaMethod method = META_OBJECT.method(8);
    QVERIFY(method.methodSignature() == QString("slotMethodWithNoParam()"));

    MetaMethodInspector inspector(method);
    QCOMPARE(inspector.hasReturnValue(), false);
    QCOMPARE(inspector.returnValueTypeId(), int(QMetaType::Void));
    QCOMPARE(inspector.returnValueTypeName(), QByteArray("void"));
}

