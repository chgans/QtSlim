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

#ifndef CALLINSTRUCTION_H
#define CALLINSTRUCTION_H

#include "instruction.h"

#include <QStringList>

class CallInstruction : public Instruction
{
public:
    CallInstruction(const QString &instructionId, const QString &instanceName,
                    const QString &methodName, const QVariantList &arguments);

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
    QString m_instanceName;
    QString m_methodName;
    QVariantList m_arguments;

    // Instruction interface
public:
    InstructionResult *execute(InstructionExecutor *executor) const;
    QString toString() const;
};

#endif // CALLINSTRUCTION_H
