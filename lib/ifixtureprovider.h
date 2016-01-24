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
