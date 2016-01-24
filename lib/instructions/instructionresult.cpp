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

#include "instructionresult.h"

InstructionResult::InstructionResult(const QString &id, const QVariant &value):
    m_id(id),
    m_value(value)
{
}

QString InstructionResult::id() const
{
    return m_id;
}

QVariant InstructionResult::result() const
{
    return m_value;
}

bool InstructionResult::hasResult() const
{
    return m_value.isValid();
}

bool InstructionResult::hasError() const
{
    return false;
}

