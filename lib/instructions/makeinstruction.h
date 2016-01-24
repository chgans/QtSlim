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

#ifndef MAKEINSTRUCTION_H
#define MAKEINSTRUCTION_H

#include "instruction.h"

#include <QStringList>

class MakeInstruction : public Instruction
{
public:
    MakeInstruction(const QString &instructionId, const QString &instanceName,
                    const QString &className, const QVariantList &arguments);

    QString instanceName() const
    {
        return m_instanceName;
    }

    QString className() const
    {
        return m_className;
    }

    QVariantList arguments() const
    {
        return m_arguments;
    }

    static const QString NAME;

private:
    QString m_instanceName;
    QString m_className;
    QVariantList m_arguments;

    // Instruction interface
public:
    InstructionResult *execute(InstructionExecutor *executor) const;
    QString toString() const;
};

#endif // MAKEINSTRUCTION_H
