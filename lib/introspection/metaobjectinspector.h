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

#ifndef METAOBJECTINSPECTOR_H
#define METAOBJECTINSPECTOR_H

#include "metamethodlist.h"
#include <QMetaObject>

// TBD: Hide Qt internale stuff like _q_reregisterTimers(void*)?
class MetaObjectInspector
{
public:
    MetaObjectInspector(const QMetaObject &metaObject);

    MetaMethodList constructors() const;
    MetaMethodList allMethods() const;
    MetaMethodList functionMethods() const;
    MetaMethodList signalMethods() const;
    MetaMethodList slotMethods() const;

private:
    const QMetaObject &m_metaObject;
};


#endif // METAOBJECTINSPECTOR_H
