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

#include "makeinstruction.h"
#include "instructionexecutor.h"
#include "okinstructionresult.h"
#include "errorinstructionresult.h"

const QString MakeInstruction::NAME = QStringLiteral("Make");

MakeInstruction::MakeInstruction(const QString &instructionId, const QString &instanceName,
                                 const QString &className, const QVariantList &arguments):
    Instruction(instructionId),
    m_instanceName(instanceName),
    m_className(className),
    m_arguments(arguments)
{

}

InstructionResult *MakeInstruction::execute(InstructionExecutor *executor) const
{
    if (!executor->make(m_instanceName, m_className, m_arguments))
        return new ErrorInstructionResult(instructionId(), executor->errorString());
    return new OkInstructionResult(instructionId());
}

QString MakeInstruction::toString() const
{
    return QString("%1: %2 = new %3(...)")
            .arg(instructionId())
            .arg(instanceName())
            .arg(className());
}
