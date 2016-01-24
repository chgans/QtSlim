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

#ifndef TESTQUERY_H
#define TESTQUERY_H

#include <QObject>
#include "fixture/idecisiontable.h"
#include <QList>

namespace fitnesse
{
namespace fixtures
{

typedef QList<QString> TableColumn;
typedef QList<TableColumn> TableRow;
typedef QList<TableRow> Table;

class TestQuery : public QObject, public IDecisionTable
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit TestQuery(int arg);

public slots:
    Table query() const;

private:
    int m_arg;

    // IDecisionTable interface
public slots:
    void table(QVariant table);
    void beginTable();
    void endTable();
    void execute();
    void reset();
};

}
}

Q_DECLARE_METATYPE(fitnesse::fixtures::TableColumn)
Q_DECLARE_METATYPE(fitnesse::fixtures::TableRow)
Q_DECLARE_METATYPE(fitnesse::fixtures::Table)

#endif // TESTQUERY_H
