#ifndef ASSIGNINSTRUCTION_H
#define ASSIGNINSTRUCTION_H

#include "instruction.h"

class AssignInstruction : public Instruction
{
public:
    AssignInstruction(const QString &instructionId, const QString &symbolName,
                      const QString &value);

    static const QString NAME;

private:
    QString m_symbolName;
    QString m_value;

    // Instruction interface
public:
    InstructionResult *execute(InstructionExecutor *executor) const;
};

#endif // ASSIGNINSTRUCTION_H
