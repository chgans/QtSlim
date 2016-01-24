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

#include "callandassigninstruction.h"
#include "instructionexecutor.h"

#include "okinstructionresult.h"
#include "errorinstructionresult.h"
#include "voidinstructionresult.h"

const QString CallAndAssignInstruction::NAME = QStringLiteral("CallAndAssign");

CallAndAssignInstruction::CallAndAssignInstruction(const QString &instructionId, const QString &symbolName,
                                                   const QString &instanceName, const QString &methodName,
                                                   const QVariantList &arguments):
    Instruction(instructionId),
    m_symbolName(symbolName),
    m_instanceName(instanceName),
    m_methodName(methodName),
    m_arguments(arguments)
{

}

InstructionResult *CallAndAssignInstruction::execute(InstructionExecutor *executor) const
{
    if (!executor->callAndAssign(m_symbolName, m_instanceName, m_methodName, m_arguments)) {
        return new ErrorInstructionResult(instructionId(), executor->errorString());
    }

    QVariant result = executor->result();
    if (!result.isValid()) {
        return new VoidInstructionResult(instructionId());
    }

    return new InstructionResult(instructionId(), result);
}

QString CallAndAssignInstruction::toString() const
{
    return QString("%1: %2 = %3.%4(...)")
            .arg(instructionId())
            .arg(symbolName())
            .arg(instanceName())
            .arg(methodName());
}
