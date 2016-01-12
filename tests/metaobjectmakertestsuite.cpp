#include "metaobjectmakertestsuite.h"
#include "introspection/metaobjectmaker.h"
#include "fixtures/basicqobectfixture.h"

#include <QtTest>

MetaObjectMakerTestSuite::MetaObjectMakerTestSuite(QObject *parent) : QObject(parent)
{

}

void MetaObjectMakerTestSuite::initTestCase()
{

}

void MetaObjectMakerTestSuite::cleanupTestCase()
{

}

void MetaObjectMakerTestSuite::testMake()
{
    MetaObjectMaker maker(BasicQObectFixture::staticMetaObject);
    maker.setParameters(QVariantList());
    QCOMPARE(maker.validate(), true);
    QCOMPARE(maker.make(), true);
    QCOMPARE(maker.errorMessage(), QString());
    QVERIFY(maker.object() != nullptr);
    qDebug() << maker.object();
    qDebug() << maker.object()->metaObject()->className();
    QVERIFY(qobject_cast<BasicQObectFixture *>(maker.object()) != nullptr);
}

