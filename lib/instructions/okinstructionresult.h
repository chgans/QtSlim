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

#ifndef OKINSTRUCTIONRESULT_H
#define OKINSTRUCTIONRESULT_H

#include "instructionresult.h"

class OkInstructionResult : public InstructionResult
{
public:
    OkInstructionResult(const QString &id);

    bool hasError() const
    {
        return false;
    }

    bool hasResult() const
    {
        return true;
    }
};

#endif // OKINSTRUCTIONRESULT_H
