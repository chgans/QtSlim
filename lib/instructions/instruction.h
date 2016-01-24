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

#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <QString>

#include "instructionresult.h"

class InstructionResult;
class InstructionExecutor;

class Instruction
{
public:
    Instruction(const QString &instructionId);
    virtual ~Instruction();

    QString instructionId() const;

    virtual InstructionResult *execute(InstructionExecutor *executor) const = 0;

    virtual QString toString() const = 0;

private:
    QString m_id;
};

#endif // INSTRUCTION_H
