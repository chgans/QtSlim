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

#ifndef METAOBJECTEXECUTOR_H
#define METAOBJECTEXECUTOR_H

#include "instructions/instructionexecutor.h"

#include <QString>
#include <QMetaObject>
#include <QMap>
#include <QList>

class SlimExecutionContext;

class MetaObjectExecutor: public InstructionExecutor
{
public:
    MetaObjectExecutor();
    virtual ~MetaObjectExecutor();

    void addMetaObject(const QMetaObject* metaObject);
    void addMetaObjects(QList<const QMetaObject*> metaObjects);
    void setExecutionContext(SlimExecutionContext *context);

private:
    QMap<QString, const QMetaObject* > m_metaObjectDictionary;
    SlimExecutionContext *m_context;
    const QMetaObject* resolveMetaObject(const QString &className);
    bool invokeMethod(QObject *object, const QString &methodName, const QVariantList &arguments);

    // InstructionExecutor interface
public:
    bool assign(const QString &name, const QVariant &value);
    bool callAndAssign(const QString &symbolName, const QString &instanceName,
                       const QString &methodName, const QVariantList &arguments);
    bool call(const QString &instanceName, const QString &methodName,
              const QVariantList &arguments);
    bool import(const QString &path);
    bool make(const QString &instanceName, const QString &className,
              const QVariantList &arguments);
};

#endif // METAOBJECTEXECUTOR_H
