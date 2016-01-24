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

#include "fixtureprovider.h"

// eg
#include "division.h"

// fitnesse.fixtures
#include "echofixture.h"
#include "pagedriver.h"
#include "setup.h"
#include "teardown.h"
#include "addupchange.h"

// fitnesse.slim.test
#include "testslim.h"
#include "testquery.h"

using namespace fitnesse::fixtures;

FixtureProvider::FixtureProvider()
{
    qRegisterMetaType<fitnesse::fixtures::TableColumn>("TableColumn");
    qRegisterMetaType<fitnesse::fixtures::TableRow>("TableRow");
    qRegisterMetaType<fitnesse::fixtures::Table>("Table");
    qRegisterMetaType<fitnesse::fixtures::TestSlim*>("TestSlim*");
    qRegisterMetaType<const fitnesse::fixtures::TestSlim*>("const TestSlim*");
}

QList<const QMetaObject *> FixtureProvider::fixtureMetaObjects() const
{
    return QList<const QMetaObject *>()
            << &Division::staticMetaObject
            << &PageDriver::staticMetaObject
            << &EchoFixture::staticMetaObject
            << &AddUpChange::staticMetaObject
            << &SetUp::staticMetaObject
            << &TearDown::staticMetaObject
            << &TestSlim::staticMetaObject
            << &TestQuery::staticMetaObject;
}
