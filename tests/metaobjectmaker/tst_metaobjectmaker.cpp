#include <QString>
#include <QtTest>
#include <QCoreApplication>

#include "introspection/metaobjectmaker.h"
#include "../fixtures/basicqobectfixture.h"

class MetaObjectMakerTest : public QObject
{
    Q_OBJECT
public:
    explicit MetaObjectMakerTest(QObject *parent = 0);

private slots:
    void initTestCase();
    void cleanupTestCase();

    void testMake();
};

MetaObjectMakerTest::MetaObjectMakerTest(QObject *parent) : QObject(parent)
{

}

void MetaObjectMakerTest::initTestCase()
{

}

void MetaObjectMakerTest::cleanupTestCase()
{

}

void MetaObjectMakerTest::testMake()
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

QTEST_MAIN(MetaObjectMakerTest)

#include "tst_metaobjectmaker.moc"
