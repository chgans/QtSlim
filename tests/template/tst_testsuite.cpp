#include <QString>
#include <QtTest>
#include <QCoreApplication>

class %Testsuite%Test : public QObject
{
      Q_OBJECT

public:
  %Testsuite%Test();

private Q_SLOTS:
  void initTestCase();
  void cleanupTestCase();
  void testCase1();
};

%Testsuite%Test::%Testsuite%Test()
{
}

void %Testsuite%Test::initTestCase()
{
}

void %Testsuite%Test::cleanupTestCase()
{
}

void %Testsuite%Test::testCase1()
{
  QVERIFY2(true, "Failure");
}

QTEST_MAIN(%Testsuite%Test)

#include "tst_%testsuite%.moc"
