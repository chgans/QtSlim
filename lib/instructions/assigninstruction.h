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

#ifndef ASSIGNINSTRUCTION_H
#define ASSIGNINSTRUCTION_H

#include "instruction.h"

class AssignInstruction : public Instruction
{
public:
    AssignInstruction(const QString &instructionId, const QString &symbolName,
                      const QString &value);

    QString symbolName() const
    {
        return m_symbolName;
    }

    QString symbolValue() const
    {
        return m_value;
    }

    static const QString NAME;

private:
    QString m_symbolName;
    QString m_value;

    // Instruction interface
public:
    InstructionResult *execute(InstructionExecutor *executor) const;
    QString toString() const;
};

#endif // ASSIGNINSTRUCTION_H
