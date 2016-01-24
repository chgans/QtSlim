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

#include "importinstruction.h"
#include "instructionexecutor.h"
#include "okinstructionresult.h"
#include "errorinstructionresult.h"

const QString ImportInstruction::NAME = QStringLiteral("Import");

ImportInstruction::ImportInstruction(const QString &instructionId, const QString &path):
    Instruction(instructionId),
    m_path(path)
{

}

InstructionResult *ImportInstruction::execute(InstructionExecutor *executor) const
{
    if (!executor->import(m_path))
        return new ErrorInstructionResult(instructionId(), executor->errorString());
    return new OkInstructionResult(instructionId());
}

QString ImportInstruction::toString() const
{
    return QString("%1: import %2")
            .arg(instructionId())
            .arg(path());
}
