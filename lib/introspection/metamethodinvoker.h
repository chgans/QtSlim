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

#ifndef METAMETHODINVOKER_H
#define METAMETHODINVOKER_H

#include <QMetaMethod>
#include <QVector>
#include "metamethodinspector.h"

// TODO: rename to MethodInvoker?
class MetaMethodInvoker
{
public:
    MetaMethodInvoker(const QMetaMethod &metaMethod);

    void setObject(QObject *object);
    void setParameters(const QVariantList &parameters);

    bool validate();
    bool invoke();

    bool hasResult() const;
    QVariant result() const;

    bool hasError() const;
    QString errorMessage() const;

private:
    const QMetaMethod &m_method;
    MetaMethodInspector m_inspector;

    Qt::ConnectionType m_connectionType;
    QObject *m_object;

    QVariant m_returnValueStorage;
    QVector<QVariant> m_parametersStorage;
    QGenericReturnArgument m_returnValue;
    QVector<QGenericArgument> m_parameters;
    void invokeConstructor();
    void invokeWithoutReturn();
    void invokeWithReturn();

    void storeArgument(int index, const QVariant &value);
    void prepareReturnArgument();

    QString m_errorMessage;
    void setError(const QString &message);
    void clearError();
};


#endif // METAMETHODINVOKER_H
