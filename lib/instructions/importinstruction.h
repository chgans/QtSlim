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

#ifndef IMPORTINSTRUCTION_H
#define IMPORTINSTRUCTION_H

#include "instruction.h"

class ImportInstruction : public Instruction
{
public:
    ImportInstruction(const QString &instructionId, const QString &path);

    QString path() const
    {
        return m_path;
    }

    static const QString NAME;

private:
    QString m_path;

    // Instruction interface
public:
    InstructionResult *execute(InstructionExecutor *executor) const;
    QString toString() const;
};

#endif // IMPORTINSTRUCTION_H
