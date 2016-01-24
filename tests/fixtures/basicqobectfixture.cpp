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

#include "basicqobectfixture.h"

BasicQObectFixture::BasicQObectFixture(QObject *parent):
    QObject(parent)
{

}

BasicQObectFixture::BasicQObectFixture(int param1):
    QObject()
{
    Q_UNUSED(param1);
}

BasicQObectFixture::BasicQObectFixture(int param1, bool param2):
    QObject()
{
    Q_UNUSED(param1);
    Q_UNUSED(param2);
}

bool BasicQObectFixture::functionMethod()
{
    return false;
}

bool BasicQObectFixture::functionMethod(int param1)
{
    Q_UNUSED(param1);
    return false;
}

bool BasicQObectFixture::functionMethod(int param1, bool param2)
{
    Q_UNUSED(param1);
    Q_UNUSED(param2);
    return false;
}

void BasicQObectFixture::slotMethodWithNoParam()
{

}

void BasicQObectFixture::slotMethodWithOneParam(const QString &param1)
{
    Q_UNUSED(param1);
}

void BasicQObectFixture::slotMethodWithTwoParams(const QString &param1, const QString &param2)
{
    Q_UNUSED(param1);
    Q_UNUSED(param2);
}

