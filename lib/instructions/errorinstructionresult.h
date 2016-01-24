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

#ifndef ERRORINSTRUCTIONRESULT_H
#define ERRORINSTRUCTIONRESULT_H

#include "instructionresult.h"

class ErrorInstructionResult : public InstructionResult
{
public:
    ErrorInstructionResult(const QString &id, const QString &message);

    bool hasError() const
    {
        return true;
    }

    bool hasResult() const
    {
        return false;
    }
};

#endif // ERRORINSTRUCTIONRESULT_H
