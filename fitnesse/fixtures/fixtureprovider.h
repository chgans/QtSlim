/****************************************************************************
**
** Copyright (C) 2016 Christian Gagneraud <chgans@gna.org>
** All rights reserved.
**
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 3 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL3 included in the packaging of this file.
** Please review the following information to ensure the GNU Lesser General
** Public License version 3 requirements will be met:
** https://www.gnu.org/licenses/lgpl-3.0.html.
**
****************************************************************************/

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
