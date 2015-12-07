#include "resultencoder.h"

#include "instruction.h"
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
    return QVariant();
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
    tokens << result.id();
    return QVariant(tokens);
}
