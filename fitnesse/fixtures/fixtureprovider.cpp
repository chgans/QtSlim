#include "fixtureprovider.h"
#include "division.h"
#include "echofixture.h"

using namespace fitnesse::fixtures;

FixtureProvider::FixtureProvider()
{
}

QList<const QMetaObject *> FixtureProvider::fixtureMetaObjects() const
{
    return QList<const QMetaObject *>()
            << &Division::staticMetaObject
            << &EchoFixture::staticMetaObject;
}
