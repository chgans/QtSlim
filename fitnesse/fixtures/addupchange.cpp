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

#include "addupchange.h"

fitnesse::fixtures::AddUpChange::AddUpChange():
    m_totalCents(0)
{
    m_coinValues["1c"] = 1;
    m_coinValues["5c"] = 5;
    m_coinValues["10c"] = 10;
    m_coinValues["25c"] = 25;
    m_coinValues["50c"] = 50;
    m_coinValues["$1"] = 100;
}

void fitnesse::fixtures::AddUpChange::reset()
{
    m_totalCents = 0;
}

void fitnesse::fixtures::AddUpChange::set(const QString coin, int amount)
{
    if (!m_coinValues.contains(coin))
        return;
    m_totalCents += amount*m_coinValues.value(coin);
}

QString fitnesse::fixtures::AddUpChange::get(const QString &requestedValue)
{
    if (requestedValue == QString("$ total"))
        return QString("%L1").arg(m_totalCents/100.0, 0, 'f', 2);
    else
        return QString("%1").arg(m_totalCents);
}

