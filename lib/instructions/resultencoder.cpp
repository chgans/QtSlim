#include "resultencoder.h"

#include "instruction.h"
#include "errorinstructionresult.h"
#include "successinstructionresult.h"
#include "voidinstructionresult.h"

ResultEncoder::ResultEncoder()
{

}

QVariant ResultEncoder::encodeResult(const InstructionResult &result)
{
    const ErrorInstructionResult *errorResult = dynamic_cast<const ErrorInstructionResult *>(&result);
    if (errorResult != nullptr)
        return encodeErrorResult(*errorResult);
    const SuccessInstructionResult *successResult = dynamic_cast<const SuccessInstructionResult *>(&result);
    if (successResult != nullptr)
        return encodeSucessResult(*successResult);
    const VoidInstructionResult *voidResult = dynamic_cast<const VoidInstructionResult *>(&result);
    if (voidResult != nullptr)
        return encodeVoidResult(*voidResult);
    return QVariant();
}

QVariant ResultEncoder::encodeErrorResult(const ErrorInstructionResult &result)
{
    QVariantList tokens;
    tokens << result.id() << result.value();
    return QVariant(tokens);
}

QVariant ResultEncoder::encodeSucessResult(const SuccessInstructionResult &result)
{
    QVariantList tokens;
    tokens << result.id() << result.value();
    return QVariant(tokens);
}

QVariant ResultEncoder::encodeVoidResult(const VoidInstructionResult &result)
{
    QVariantList tokens;
    tokens << result.id();
    return QVariant(tokens);
}

