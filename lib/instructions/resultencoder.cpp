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

#include "resultencoder.h"

#include "instruction.h"
#include "instructionresult.h"
#include "errorinstructionresult.h"
#include "okinstructionresult.h"
#include "voidinstructionresult.h"

ResultEncoder::ResultEncoder()
{

}

QVariant ResultEncoder::encodeResult(const InstructionResult &result)
{
    const ErrorInstructionResult *errorResult = dynamic_cast<const ErrorInstructionResult *>(&result);
    if (errorResult != nullptr)
        return encodeErrorResult(*errorResult);

    const OkInstructionResult *okResult = dynamic_cast<const OkInstructionResult *>(&result);
    if (okResult != nullptr)
        return encodeOkResult(*okResult);

    const VoidInstructionResult *voidResult = dynamic_cast<const VoidInstructionResult *>(&result);
    if (voidResult != nullptr)
        return encodeVoidResult(*voidResult);

    return encodeValueResult(result);
}

// TODO: Error message format should be part of the protocol (the __EXCEPTION__ and message<<...>> bits
// Unfortunately, for now it is hard-coded in ErrorInstructionResult and/or here
QVariant ResultEncoder::encodeErrorResult(const ErrorInstructionResult &result)
{
    QVariantList tokens;
    tokens << result.id() << result.result();
    return QVariant(tokens);
}

QVariant ResultEncoder::encodeOkResult(const OkInstructionResult &result)
{
    QVariantList tokens;
    tokens << result.id() << result.result();
    return QVariant(tokens);
}

QVariant ResultEncoder::encodeVoidResult(const VoidInstructionResult &result)
{
    QVariantList tokens;
    tokens << result.id() << result.result();
    return QVariant(tokens);
}

QVariant ResultEncoder::encodeValueResult(const InstructionResult &result)
{
    QVariantList tokens;
    tokens << result.id() << result.result();
    return QVariant(tokens);
}
