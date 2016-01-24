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

#include "callinstruction.h"
#include "instructionexecutor.h"
#include "okinstructionresult.h"
#include "errorinstructionresult.h"
#include "voidinstructionresult.h"

const QString CallInstruction::NAME = QStringLiteral("Call");

CallInstruction::CallInstruction(const QString &instructionId, const QString &instanceName,
                                 const QString &methodName, const QVariantList &arguments):
    Instruction(instructionId),
    m_instanceName(instanceName),
    m_methodName(methodName),
    m_arguments(arguments)
{

}

InstructionResult *CallInstruction::execute(InstructionExecutor *executor) const
{
    if (!executor->call(m_instanceName, m_methodName, m_arguments)) {
        return new ErrorInstructionResult(instructionId(), executor->errorString());
    }

    if (!executor->result().isValid()) {
        return new VoidInstructionResult(instructionId());
    }

    return new InstructionResult(instructionId(), executor->result());
}

QString CallInstruction::toString() const
{
    return QString("%1: %2.%3(...)")
            .arg(instructionId())
            .arg(instanceName())
            .arg(methodName());
}
