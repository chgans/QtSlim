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

#ifndef METAMETHODLIST_H
#define METAMETHODLIST_H

#include <QList>
#include <QMetaMethod>
#include <QString>

class MetaMethodList: public QList<QMetaMethod>
{
public:
    MetaMethodList();
    MetaMethodList filterByName(const QString methodName) const;
    MetaMethodList filterByArgumentCount(int count) const;
};

#endif // METAMETHODLIST_H
