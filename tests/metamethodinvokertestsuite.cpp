#include "metamethodinvokertestsuite.h"

#include "introspection/metaobjectinspector.h"
#include "introspection/metamethodinvoker.h"

#include "fixtures/division.h"

#include <QtTest>
#include <QDebug>

MetaMethodInvokerTestSuite::MetaMethodInvokerTestSuite(QObject *parent) : QObject(parent)
{

}

void MetaMethodInvokerTestSuite::initTestCase()
{

}

void MetaMethodInvokerTestSuite::cleanupTestCase()
{

}

void MetaMethodInvokerTestSuite::testInvoke()
{
    Division *division = new Division();

    invoke(division, "setNumerator", QVariantList() << "10.0");
    QCOMPARE(division->numerator(), 10.0);
    QVERIFY(!m_invokeResult.isValid());

    invoke(division, "setDenominator", QVariantList() << "2.5");
    QCOMPARE(division->denominator(), 2.5);
    QVERIFY(!m_invokeResult.isValid());

    invoke(division, "quotient", QVariantList());
    QVERIFY(m_invokeResult.isValid());
    QCOMPARE(m_invokeResult, QVariant(4.0));
    QCOMPARE(division->quotient(), 4.0);

    delete division;
}

void MetaMethodInvokerTestSuite::invoke(QObject *object, const QString &methodName, const QVariantList &parameters)
{
    MetaObjectInspector inspector(*object->metaObject());
    MetaMethodList methods = inspector.allMethods().filterByName(methodName).filterByArgumentCount(parameters.count());
    QCOMPARE(methods.count(), 1);
    QMetaMethod method = methods[0];

    MetaMethodInvoker invoker(method);
    invoker.setObject(object);
    invoker.setParameters(parameters);
    QCOMPARE(invoker.validate(), true);
    QCOMPARE(invoker.invoke(), true);
    QCOMPARE(invoker.hasError(), false);
    m_invokeResult = invoker.result();
}

