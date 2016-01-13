#ifndef FIXTUREPROVIDER_H
#define FIXTUREPROVIDER_H

#include <QObject>
#include "ifixtureprovider.h"

class FixtureProvider: public QObject, public IFixtureProvider
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QtSlimFixtureProvider_iid FILE "qtslim-fitnesse-fixtures.json")
    Q_INTERFACES(IFixtureProvider)

public:
    FixtureProvider();

    // IFixtureProvider interface
public:
    QList<const QMetaObject *> fixtureMetaObjects() const;
};

#endif // FIXTUREPROVIDER_H
