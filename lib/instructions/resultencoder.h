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

#ifndef RESULTENCODER_H
#define RESULTENCODER_H

#include <QVariant>

class InstructionResult;
class ErrorInstructionResult;
class OkInstructionResult;
class VoidInstructionResult;

class ResultEncoder
{
public:
    static QVariant encodeResult(const InstructionResult &result);

private:
    ResultEncoder();
    static QVariant encodeErrorResult(const ErrorInstructionResult& result);
    static QVariant encodeOkResult(const OkInstructionResult& result);
    static QVariant encodeVoidResult(const VoidInstructionResult& result);
    static QVariant encodeValueResult(const InstructionResult& result);
};

#endif // RESULTENCODER_H
