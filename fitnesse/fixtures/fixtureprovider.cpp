#include "fixtureprovider.h"
#include "division.h"

FixtureProvider::FixtureProvider()
{
}

QList<const QMetaObject *> FixtureProvider::fixtureMetaObjects() const
{
    return QList<const QMetaObject *>() << &Division::staticMetaObject;
}
