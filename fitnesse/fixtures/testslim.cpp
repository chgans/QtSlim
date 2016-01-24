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

#include "testslim.h"

#include <QDebug>

namespace fitnesse
{
namespace fixtures
{


TestSlim::TestSlim():
    QObject(),
    m_ctorArg(0)
{

}

TestSlim::TestSlim(int arg):
    QObject(),
    m_ctorArg(arg)
{

}

TestSlim::TestSlim(int arg, TestSlim *other):
    m_stringArg(other->m_stringArg), m_ctorArg(arg)
{

}

bool TestSlim::echoBoolean(bool value)
{
    return value;
}

int TestSlim::echoInt(int value)
{
    return value;
}

void TestSlim::setString(const QString &value)
{
    m_stringArg = value;
}

QString TestSlim::getStringArg() const
{
    return m_stringArg;
}

int TestSlim::returnConstructorArg() const
{
    return m_ctorArg;
}

TestSlim *TestSlim::createTestSlimWithString(const QString &arg) const
{
    TestSlim *result = new TestSlim();
    result->setString(arg);
    return result;
}

bool TestSlim::isSame(TestSlim *other) const
{
    return this == other;
}

QString TestSlim::getStringFromOther(TestSlim *other) const
{
    return other->m_stringArg;
}

void TestSlim::table(QVariant table)
{
    Q_UNUSED(table);
}

void TestSlim::beginTable()
{
}

void TestSlim::endTable()
{
}

void TestSlim::execute()
{
}

void TestSlim::reset()
{
}

}
}
