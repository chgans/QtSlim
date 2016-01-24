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

#include "metamethodinspector.h"

MetaMethodInspector::MetaMethodInspector(const QMetaMethod &metaMethod):
    m_metaMethod(metaMethod)
{

}

int MetaMethodInspector::parameterCount() const
{
    return m_metaMethod.parameterCount();
}

QList<int> MetaMethodInspector::parameterTypeIds() const
{
    QList<int> result;
    for (int index=0; index<m_metaMethod.parameterCount(); index++) {
        result.append(m_metaMethod.parameterType(index));
    }
    return result;
}

QList<QByteArray> MetaMethodInspector::parameterTypeNames() const
{
    QList<QByteArray> result;
    foreach (const QByteArray &name, m_metaMethod.parameterTypes()) {
        result.append(name);
    }
    return result;
}

QList<QByteArray> MetaMethodInspector::parameterNames() const
{
    QList<QByteArray> result;
    foreach (const QByteArray &name, m_metaMethod.parameterNames()) {
        result.append(name);
    }
    return result;
}

bool MetaMethodInspector::hasReturnValue() const
{
    return returnValueTypeId() != QMetaType::Void;
}

int MetaMethodInspector::returnValueTypeId() const
{
    if (m_metaMethod.returnType() == QMetaType::UnknownType)
        return QMetaType::type(m_metaMethod.typeName());
    else
        return m_metaMethod.returnType();
}

QByteArray MetaMethodInspector::returnValueTypeName() const
{
    return QByteArray(m_metaMethod.typeName());
}
