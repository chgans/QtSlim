#ifndef IFIXTUREPROVIDER_H
#define IFIXTUREPROVIDER_H

#include <QtPlugin>
#include <QList>
class QMetaObject;

class IFixtureProvider
{
public:
    IFixtureProvider() {}
    virtual ~IFixtureProvider() {}

    virtual QList<const QMetaObject *> fixtureMetaObjects() const = 0;
};

#define QtSlimFixtureProvider_iid "engineering.chgans.QtSlim.FixtureProvider"

Q_DECLARE_INTERFACE(IFixtureProvider, QtSlimFixtureProvider_iid)

#endif // IFIXTUREPROVIDER_H
