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

#include "setup.h"

fitnesse::fixtures::SetUp::SetUp(const QString &configuration)
{
    Q_UNUSED(configuration)
}


void fitnesse::fixtures::SetUp::table(QVariant table)
{
    Q_UNUSED(table)
}

void fitnesse::fixtures::SetUp::beginTable()
{
}

void fitnesse::fixtures::SetUp::endTable()
{
}

void fitnesse::fixtures::SetUp::execute()
{
}

void fitnesse::fixtures::SetUp::reset()
{
}
