#ifndef INVALIDINSTRUCTION_H
#define INVALIDINSTRUCTION_H

#include "instruction.h"

class InvalidInstruction : public Instruction
{
public:
    InvalidInstruction(const QString &instructionId, const QString &operationName);

private:
    QString m_operationName;

    // Instruction interface
public:
    InstructionResult *execute(InstructionExecutor *executor) const;
    QString toString() const;
};

#endif // INVALIDINSTRUCTION_H
