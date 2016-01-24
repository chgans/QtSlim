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

#include "metamethodlist.h"

MetaMethodList::MetaMethodList():
    QList<QMetaMethod>()
{

}

MetaMethodList MetaMethodList::filterByName(const QString methodName) const
{
    MetaMethodList result;
    foreach (const QMetaMethod &metaMethod, *this) {
        if (metaMethod.name() == methodName)
            result.append(metaMethod);
    }
    return result;
}

MetaMethodList MetaMethodList::filterByArgumentCount(int count) const
{
    MetaMethodList result;
    foreach (const QMetaMethod &metaMethod, *this) {
        if (metaMethod.parameterCount() == count)
            result.append(metaMethod);
    }
    return result;
}
