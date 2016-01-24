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

#include "teardown.h"

fitnesse::fixtures::TearDown::TearDown()
{
}


void fitnesse::fixtures::TearDown::table(QVariant table)
{
    Q_UNUSED(table);
}

void fitnesse::fixtures::TearDown::beginTable()
{
}

void fitnesse::fixtures::TearDown::endTable()
{
}

void fitnesse::fixtures::TearDown::execute()
{
}

void fitnesse::fixtures::TearDown::reset()
{
}
