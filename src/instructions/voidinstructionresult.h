#ifndef VOIDINSTRUCTIONRESULT_H
#define VOIDINSTRUCTIONRESULT_H

#include "instructionresult.h"

class VoidInstructionResult : public InstructionResult
{
public:
    VoidInstructionResult(const QString &id);

    bool hasError() const
    {
        return false;
    }

    bool hasValue() const
    {
        return false;
    }
};

#endif // VOIDINSTRUCTIONRESULT_H
