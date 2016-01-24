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

#ifndef CALLANDASSIGNINSTRUCTION_H
#define CALLANDASSIGNINSTRUCTION_H

#include "instruction.h"

#include <QStringList>

class CallAndAssignInstruction : public Instruction
{
public:
    CallAndAssignInstruction(const QString &instructionId, const QString &symbolName,
                             const QString &instanceName, const QString &methodName,
                             const QVariantList &arguments);


    QString symbolName() const
    {
        return m_symbolName;
    }

    QString instanceName() const
    {
        return m_instanceName;
    }

    QString methodName() const
    {
        return m_methodName;
    }

    QVariantList arguments() const
    {
        return m_arguments;
    }

    static const QString NAME;

private:
    QString m_symbolName;
    QString m_instanceName;
    QString m_methodName;
    QVariantList m_arguments;

    // Instruction interface
public:
    InstructionResult *execute(InstructionExecutor *executor) const;
    QString toString() const;
};

#endif // CALLANDASSIGNINSTRUCTION_H
