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

#include "metaobjectinspector.h"

MetaObjectInspector::MetaObjectInspector(const QMetaObject &metaObject):
    m_metaObject(metaObject)
{
}

MetaMethodList MetaObjectInspector::constructors() const
{
    MetaMethodList result;
    for (int index=0; index<m_metaObject.constructorCount(); index++) {
        result << m_metaObject.constructor(index);
    }
    return result;
}

MetaMethodList MetaObjectInspector::allMethods() const
{
    MetaMethodList result;
    for (int index=0; index<m_metaObject.methodCount(); index++) {
        result << m_metaObject.method(index);
    }
    return result;
}

MetaMethodList MetaObjectInspector::functionMethods() const
{
    MetaMethodList result;
    for (int index=0; index<m_metaObject.methodCount(); index++) {
        QMetaMethod metaMethod = m_metaObject.method(index);
        if (metaMethod.methodType() == QMetaMethod::Method)
            result << m_metaObject.method(index);
    }
    return result;
}

MetaMethodList MetaObjectInspector::signalMethods() const
{
    MetaMethodList result;
    for (int index=0; index<m_metaObject.methodCount(); index++) {
        QMetaMethod metaMethod = m_metaObject.method(index);
        if (metaMethod.methodType() == QMetaMethod::Signal)
            result << m_metaObject.method(index);
    }
    return result;
}

MetaMethodList MetaObjectInspector::slotMethods() const
{
    MetaMethodList result;
    for (int index=0; index<m_metaObject.methodCount(); index++) {
        QMetaMethod metaMethod = m_metaObject.method(index);
        if (metaMethod.methodType() == QMetaMethod::Slot)
            result << m_metaObject.method(index);
    }
    return result;
}
