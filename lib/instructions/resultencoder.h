#ifndef RESULTENCODER_H
#define RESULTENCODER_H

#include <QVariant>

// TODO: only 2 different result classes
// class SuccessResult;
// class ErrorResult;

class InstructionResult;
class ErrorInstructionResult;
class SuccessInstructionResult;
class VoidInstructionResult;

class ResultEncoder
{
public:
    static QVariant encodeResult(const InstructionResult &result);

private:
    ResultEncoder();
    static QVariant encodeErrorResult(const ErrorInstructionResult& result);
    static QVariant encodeSucessResult(const SuccessInstructionResult& result);
    static QVariant encodeVoidResult(const VoidInstructionResult& result);
};

#endif // RESULTENCODER_H
