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

#ifndef IDECISIONTABLE_H
#define IDECISIONTABLE_H

#include <QVariant>

class IDecisionTable
{
public:
    IDecisionTable() {}
    virtual ~IDecisionTable() {}

    virtual void table(QVariant table) = 0;
    virtual void beginTable() = 0;
    virtual void endTable() = 0;
    virtual void execute() = 0;
    virtual void reset() = 0;
};

#endif // IDECISIONTABLE_H
