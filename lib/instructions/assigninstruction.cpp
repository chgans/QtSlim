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

#include "assigninstruction.h"
#include "instructionexecutor.h"
#include "okinstructionresult.h"
#include "errorinstructionresult.h"

const QString AssignInstruction::NAME = QStringLiteral("Assign");

AssignInstruction::AssignInstruction(const QString &instructionId, const QString &symbolName,
                                     const QString &value):
    Instruction(instructionId),
    m_symbolName(symbolName),
    m_value(value)
{

}

InstructionResult *AssignInstruction::execute(InstructionExecutor *executor) const
{
    if (!executor->assign(m_symbolName, m_value)) {
        return new ErrorInstructionResult(instructionId(), executor->errorString());
    }
    return new OkInstructionResult(instructionId());
}

QString AssignInstruction::toString() const
{
    return QString("%1: %2 = %3")
            .arg(instructionId())
            .arg(symbolName())
            .arg(symbolValue());
}
