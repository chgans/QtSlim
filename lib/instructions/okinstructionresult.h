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
