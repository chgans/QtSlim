#ifndef SUCCESSINSTRUCTIONRESULT_H
#define SUCCESSINSTRUCTIONRESULT_H

#include "instructionresult.h"

class SuccessInstructionResult : public InstructionResult
{
public:
    SuccessInstructionResult(const QString &id);

    bool hasError() const
    {
        return false;
    }

    bool hasValue() const
    {
        return true;
    }

    QString value() const;
};

#endif // SUCCESSINSTRUCTIONRESULT_H
