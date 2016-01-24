#include <QString>
#include <QtTest>
#include <QCoreApplication>

#include "instructions/resultencoder.h"
#include "instructions/errorinstructionresult.h"
#include "instructions/okinstructionresult.h"
#include "instructions/voidinstructionresult.h"

class ResultEncoderTest : public QObject
{
    Q_OBJECT
public:
    explicit ResultEncoderTest(QObject *parent = 0);

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testEncodeResult();
    void testEncodeOkResult();
    void testEncodeErrorResult();
    void testEncodeVoidResult();
};

ResultEncoderTest::ResultEncoderTest(QObject *parent) : QObject(parent)
{

}

void ResultEncoderTest::initTestCase()
{

}

void ResultEncoderTest::cleanupTestCase()
{

}

void ResultEncoderTest::testEncodeResult()
{
    QEXPECT_FAIL("", "TODO", Continue);
    QVERIFY(false);
}

void ResultEncoderTest::testEncodeOkResult()
{
    QEXPECT_FAIL("", "TODO", Continue);
    QVERIFY(false);
}

void ResultEncoderTest::testEncodeErrorResult()
{
    QEXPECT_FAIL("", "TODO", Continue);
    QVERIFY(false);
}

void ResultEncoderTest::testEncodeVoidResult()
{
    QEXPECT_FAIL("", "TODO", Continue);
    QVERIFY(false);
}

QTEST_MAIN(ResultEncoderTest)

#include "tst_resultencoder.moc"
