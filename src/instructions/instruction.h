#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <QString>

#include "instructionresult.h"

class InstructionResult;
class InstructionExecutor;

class Instruction
{
public:
    Instruction(const QString &instructionId);
    virtual ~Instruction();

    QString instructionId() const;

    virtual InstructionResult *execute(InstructionExecutor *executor) const = 0;

private:
    QString m_id;
};

#endif // INSTRUCTION_H
