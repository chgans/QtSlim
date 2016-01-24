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

#include "invalidinstruction.h"
#include "errorinstructionresult.h"

InvalidInstruction::InvalidInstruction(const QString &instructionId, const QString &operationName):
    Instruction(instructionId),
    m_operationName(operationName)
{

}

InstructionResult *InvalidInstruction::execute(InstructionExecutor *executor) const
{
    Q_UNUSED(executor);
    return new ErrorInstructionResult(instructionId(), QString("%1: Invalid instruction").arg(m_operationName));
}

QString InvalidInstruction::toString() const
{
    return QString("%1: !INVALID_INSTRUCTION!")
            .arg(instructionId());
}
