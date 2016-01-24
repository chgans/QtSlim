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

#ifndef METAMETHODINSPECTOR_H
#define METAMETHODINSPECTOR_H

#include <QMetaMethod>
#include <QList>
#include <QByteArray>

class MetaMethodInspector
{
public:
    MetaMethodInspector(const QMetaMethod &metaMethod);

    int parameterCount() const;
    QList<int> parameterTypeIds() const;
    QList<QByteArray> parameterTypeNames() const;
    QList<QByteArray> parameterNames() const;

    bool hasReturnValue() const;
    int returnValueTypeId() const;
    QByteArray returnValueTypeName() const;

private:
    const QMetaMethod &m_metaMethod;
};

#endif // METAMETHODINSPECTOR_H
