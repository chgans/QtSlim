#include <QtTest>
#include <QCoreApplication>

#include  "introspection/metaobjectinspector.h"
#include  "introspection/metamethodinspector.h"
#include "../fixtures/basicqobectfixture.h"

// TBD: test parameterNames()
class MetaMethodInspectorTest: public QObject
{
    Q_OBJECT
public:
    MetaMethodInspectorTest(QObject *parent = 0);

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testMethodWitParameters();
    void testMethodWithoutParameters();
    void testMethodWitReturnValue();
    void testMethodWithoutReturnValue();

private:
    static const QMetaObject META_OBJECT;
};

const QMetaObject MetaMethodInspectorTest::META_OBJECT = BasicQObectFixture::staticMetaObject;

MetaMethodInspectorTest::MetaMethodInspectorTest(QObject *parent):
    QObject(parent)
{

}

void MetaMethodInspectorTest::initTestCase()
{

}

void MetaMethodInspectorTest::cleanupTestCase()
{

}

void MetaMethodInspectorTest::testMethodWitParameters()
{
    QVERIFY(META_OBJECT.methodCount() > 13);
    QMetaMethod method = META_OBJECT.method(13);
    QVERIFY(method.methodSignature() == QString("functionMethod(int,bool)"));

    MetaMethodInspector inspector(method);
    QCOMPARE(inspector.parameterCount(), 2);
    QCOMPARE(inspector.parameterTypeIds(), QList<int>() << QMetaType::Int << QMetaType::Bool);
    QCOMPARE(inspector.parameterTypeNames(), QList<QByteArray>() << "int" << "bool");
}

void MetaMethodInspectorTest::testMethodWithoutParameters()
{
    QVERIFY(META_OBJECT.methodCount() > 11);
    QMetaMethod method = META_OBJECT.method(11);
    QVERIFY(method.methodSignature() == QString("functionMethod()"));

    MetaMethodInspector inspector(method);
    QCOMPARE(inspector.parameterCount(), 0);
    QCOMPARE(inspector.parameterTypeIds(), QList<int>());
    QCOMPARE(inspector.parameterTypeNames(), QList<QByteArray>());
}

void MetaMethodInspectorTest::testMethodWitReturnValue()
{
    QVERIFY(META_OBJECT.methodCount() > 11);
    QMetaMethod method = META_OBJECT.method(11);
    QVERIFY(method.methodSignature() == QString("functionMethod()"));

    MetaMethodInspector inspector(method);
    QCOMPARE(inspector.hasReturnValue(), true);
    QCOMPARE(inspector.returnValueTypeId(), int(QMetaType::Bool));
    QCOMPARE(inspector.returnValueTypeName(), QByteArray("bool"));
}

void MetaMethodInspectorTest::testMethodWithoutReturnValue()
{
    QVERIFY(META_OBJECT.methodCount() > 8);
    QMetaMethod method = META_OBJECT.method(8);
    QVERIFY(method.methodSignature() == QString("slotMethodWithNoParam()"));

    MetaMethodInspector inspector(method);
    QCOMPARE(inspector.hasReturnValue(), false);
    QCOMPARE(inspector.returnValueTypeId(), int(QMetaType::Void));
    QCOMPARE(inspector.returnValueTypeName(), QByteArray("void"));
}

QTEST_MAIN(MetaMethodInspectorTest)

#include "tst_metamethodinspector.moc"
