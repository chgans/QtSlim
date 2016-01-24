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

#include "pagedriver.h"


fitnesse::fixtures::PageDriver::PageDriver(QObject *parent) : QObject(parent)
{

}

void fitnesse::fixtures::PageDriver::table(QVariant table)
{
    Q_UNUSED(table);
}

void fitnesse::fixtures::PageDriver::beginTable()
{
}

void fitnesse::fixtures::PageDriver::endTable()
{
}

void fitnesse::fixtures::PageDriver::execute()
{
}

void fitnesse::fixtures::PageDriver::reset()
{
}
