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

#ifndef INSTRUCTIONEXECUTOR_H
#define INSTRUCTIONEXECUTOR_H

#include <QString>
#include <QVariant>
#include <QVariantList>

class InstructionExecutor
{
public:
    InstructionExecutor();

    virtual bool assign(const QString &name, const QVariant &value) = 0;
    virtual bool callAndAssign(const QString &symbolName, const QString &instanceName,
                                  const QString &methodName, const QVariantList &arguments) = 0;
    virtual bool call(const QString &instanceName, const QString &methodName,
                         const QVariantList &arguments) = 0;
    virtual bool import(const QString &path) = 0;

    virtual bool make(const QString &instanceName, const QString &className,
                      const QVariantList &arguments) = 0;

    QVariant result() const;
    QString errorString() const;

protected:
    void setError(const QString &error);
    void clearErrorString();
    void setResult(const QVariant &result);
    void clearResult();

private:
    QVariant m_result;
    QString m_errorString;
};

#endif // INSTRUCTIONEXECUTOR_H
