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
};

#endif // RESULTENCODER_H
