#include "metaobjectinspectortestsuite.h"
#include "fixtures/basicqobectfixture.h"

#include  "introspection/metaobjectinspector.h"

#include <QtTest>

const QMetaObject MetaObjectInspectorTestSuite::META_OBJECT = BasicQObectFixture::staticMetaObject;

MetaObjectInspectorTestSuite::MetaObjectInspectorTestSuite(QObject *parent) : QObject(parent)
{

}

void MetaObjectInspectorTestSuite::initTestCase()
{

}

void MetaObjectInspectorTestSuite::cleanupTestCase()
{

}

// TBD: Do not test ordering, do a signatures(methods).sorted() and then compare against a QStringList()
void MetaObjectInspectorTestSuite::testConstructors()
{
    MetaObjectInspector inspector(META_OBJECT);
    MetaMethodList methods = inspector.constructors();
    QCOMPARE(methods.count(), 4);
    QCOMPARE(methods[1].methodSignature(), QByteArray("BasicQObectFixture()"));
    QCOMPARE(methods[0].methodSignature(), QByteArray("BasicQObectFixture(QObject*)"));
    QCOMPARE(methods[2].methodSignature(), QByteArray("BasicQObectFixture(int)"));
    QCOMPARE(methods[3].methodSignature(), QByteArray("BasicQObectFixture(int,bool)"));
}

void MetaObjectInspectorTestSuite::testAllMethods()
{
    MetaObjectInspector inspector(META_OBJECT);
    MetaMethodList methods = inspector.allMethods();
    QCOMPARE(methods.count(), 14);
    QCOMPARE(methods[0].methodSignature(), QByteArray("destroyed(QObject*)"));
    QCOMPARE(methods[1].methodSignature(), QByteArray("destroyed()"));
    QCOMPARE(methods[2].methodSignature(), QByteArray("objectNameChanged(QString)"));
    QCOMPARE(methods[3].methodSignature(), QByteArray("deleteLater()"));
    QCOMPARE(methods[4].methodSignature(), QByteArray("_q_reregisterTimers(void*)"));
    QCOMPARE(methods[5].methodSignature(), QByteArray("signalMethodWithNoParam()"));
    QCOMPARE(methods[6].methodSignature(), QByteArray("signalMethodWithOneParam(int)"));
    QCOMPARE(methods[7].methodSignature(), QByteArray("signalMethodWithTwoParams(bool,double)"));
    QCOMPARE(methods[8].methodSignature(), QByteArray("slotMethodWithNoParam()"));
    QCOMPARE(methods[9].methodSignature(), QByteArray("slotMethodWithOneParam(QString)"));
    QCOMPARE(methods[10].methodSignature(), QByteArray("slotMethodWithTwoParams(QString,QString)"));
    QCOMPARE(methods[11].methodSignature(), QByteArray("functionMethod()"));
    QCOMPARE(methods[12].methodSignature(), QByteArray("functionMethod(int)"));
    QCOMPARE(methods[13].methodSignature(), QByteArray("functionMethod(int,bool)"));
}

void MetaObjectInspectorTestSuite::testFunctionMethods()
{
    MetaObjectInspector inspector(META_OBJECT);
    MetaMethodList methods = inspector.functionMethods();
    QCOMPARE(methods.count(), 3);
    QCOMPARE(methods[0].methodSignature(), QByteArray("functionMethod()"));
    QCOMPARE(methods[1].methodSignature(), QByteArray("functionMethod(int)"));
    QCOMPARE(methods[2].methodSignature(), QByteArray("functionMethod(int,bool)"));
}

void MetaObjectInspectorTestSuite::testSignalMethods()
{
    MetaObjectInspector inspector(META_OBJECT);
    MetaMethodList methods = inspector.signalMethods();
    QCOMPARE(methods.count(), 6);
    QCOMPARE(methods[0].methodSignature(), QByteArray("destroyed(QObject*)"));
    QCOMPARE(methods[1].methodSignature(), QByteArray("destroyed()"));
    QCOMPARE(methods[2].methodSignature(), QByteArray("objectNameChanged(QString)"));
    QCOMPARE(methods[3].methodSignature(), QByteArray("signalMethodWithNoParam()"));
    QCOMPARE(methods[4].methodSignature(), QByteArray("signalMethodWithOneParam(int)"));
    QCOMPARE(methods[5].methodSignature(), QByteArray("signalMethodWithTwoParams(bool,double)"));

}

void MetaObjectInspectorTestSuite::testSlotMethods()
{
    MetaObjectInspector inspector(META_OBJECT);
    MetaMethodList methods = inspector.slotMethods();
    QCOMPARE(methods.count(), 5);
    QCOMPARE(methods[0].methodSignature(), QByteArray("deleteLater()"));
    QCOMPARE(methods[1].methodSignature(), QByteArray("_q_reregisterTimers(void*)"));
    QCOMPARE(methods[2].methodSignature(), QByteArray("slotMethodWithNoParam()"));
    QCOMPARE(methods[3].methodSignature(), QByteArray("slotMethodWithOneParam(QString)"));
    QCOMPARE(methods[4].methodSignature(), QByteArray("slotMethodWithTwoParams(QString,QString)"));
}

