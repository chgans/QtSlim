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
