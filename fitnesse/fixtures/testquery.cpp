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

#include "testquery.h"

fitnesse::fixtures::TestQuery::TestQuery(int arg):
    m_arg(arg)
{

}

fitnesse::fixtures::Table fitnesse::fixtures::TestQuery::query() const
{
    Table table;
    for (int i=0; i < m_arg; i++) {
        QList<QString> col1;
        col1 << "n" << QString("%1").arg(i);
        QList<QString> col2;
        col2 << "2n" << QString("%1").arg(2*i);
        QList<QList<QString> > row;
        row << col1 << col2;
        table << row;
    }
    return table;
}

void fitnesse::fixtures::TestQuery::table(QVariant table)
{
    Q_UNUSED(table)
}

void fitnesse::fixtures::TestQuery::beginTable()
{
}

void fitnesse::fixtures::TestQuery::endTable()
{
}

void fitnesse::fixtures::TestQuery::execute()
{
}

void fitnesse::fixtures::TestQuery::reset()
{
}
