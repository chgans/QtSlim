#include "fixtureprovider.h"

// eg
#include "division.h"

// fitnesse.fixtures
#include "echofixture.h"
#include "pagedriver.h"
#include "setup.h"

// fitnesse.slim.test
#include "testslim.h"
#include "testquery.h"

using namespace fitnesse::fixtures;

FixtureProvider::FixtureProvider()
{
    qRegisterMetaType<fitnesse::fixtures::TableColumn>("TableColumn");
    qRegisterMetaType<fitnesse::fixtures::TableRow>("TableRow");
    qRegisterMetaType<fitnesse::fixtures::Table>("Table");
}

QList<const QMetaObject *> FixtureProvider::fixtureMetaObjects() const
{
    return QList<const QMetaObject *>()
            << &Division::staticMetaObject
            << &PageDriver::staticMetaObject
            << &EchoFixture::staticMetaObject
            << &SetUp::staticMetaObject
            << &TestSlim::staticMetaObject
            << &TestQuery::staticMetaObject;
}
