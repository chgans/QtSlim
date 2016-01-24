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

#ifndef METAOBJECTMAKER_H
#define METAOBJECTMAKER_H

#include <QMetaObject>
#include <QString>
#include <QVariant>
#include <QVariantList>

#include "metaobjectinspector.h"

// TODO: rename to ObjectMaker?
class MetaObjectMaker
{
public:
    MetaObjectMaker(const QMetaObject &metaObject);

    void setParameters(const QVariantList &parameters);

    bool validate();
    bool make();
    QString errorMessage() const;
    QObject *object() const;

private:
    QMetaObject m_metaObject;
    MetaObjectInspector m_metaObjectInspector;
    QVariantList m_arguments;
    QString m_errorMessage;
    QObject *m_object;

    void setErrorMessage(const QString &message);
};

#endif // METAOBJECTMAKER_H
