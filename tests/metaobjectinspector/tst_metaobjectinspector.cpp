#include <QString>
#include <QtTest>
#include <QCoreApplication>

#include  "introspection/metaobjectinspector.h"
#include "../fixtures/basicqobectfixture.h"

class MetaObjectInspectorTest : public QObject
{
    Q_OBJECT
public:
    explicit MetaObjectInspectorTest(QObject *parent = 0);

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testConstructors();
    void testAllMethods();
    void testFunctionMethods();
    void testSignalMethods();
    void testSlotMethods();

private:
    static const QMetaObject META_OBJECT;
};

const QMetaObject MetaObjectInspectorTest::META_OBJECT = BasicQObectFixture::staticMetaObject;

MetaObjectInspectorTest::MetaObjectInspectorTest(QObject *parent) : QObject(parent)
{

}

void MetaObjectInspectorTest::initTestCase()
{

}

void MetaObjectInspectorTest::cleanupTestCase()
{

}

// TBD: Do not test ordering, do a signatures(methods).sorted() and then compare against a QStringList()
void MetaObjectInspectorTest::testConstructors()
{
    MetaObjectInspector inspector(META_OBJECT);
    MetaMethodList methods = inspector.constructors();
    QCOMPARE(methods.count(), 4);
    QCOMPARE(methods[1].methodSignature(), QByteArray("BasicQObectFixture()"));
    QCOMPARE(methods[0].methodSignature(), QByteArray("BasicQObectFixture(QObject*)"));
    QCOMPARE(methods[2].methodSignature(), QByteArray("BasicQObectFixture(int)"));
    QCOMPARE(methods[3].methodSignature(), QByteArray("BasicQObectFixture(int,bool)"));
}

void MetaObjectInspectorTest::testAllMethods()
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

void MetaObjectInspectorTest::testFunctionMethods()
{
    MetaObjectInspector inspector(META_OBJECT);
    MetaMethodList methods = inspector.functionMethods();
    QCOMPARE(methods.count(), 3);
    QCOMPARE(methods[0].methodSignature(), QByteArray("functionMethod()"));
    QCOMPARE(methods[1].methodSignature(), QByteArray("functionMethod(int)"));
    QCOMPARE(methods[2].methodSignature(), QByteArray("functionMethod(int,bool)"));
}

void MetaObjectInspectorTest::testSignalMethods()
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

void MetaObjectInspectorTest::testSlotMethods()
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

QTEST_MAIN(MetaObjectInspectorTest)

#include "tst_metaobjectinspector.moc"
