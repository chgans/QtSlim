#ifndef IMPORTINSTRUCTION_H
#define IMPORTINSTRUCTION_H

#include "instruction.h"

class ImportInstruction : public Instruction
{
public:
    ImportInstruction(const QString &instructionId, const QString &path);

    static const QString NAME;

private:
    QString m_path;

    // Instruction interface
public:
    InstructionResult *execute(InstructionExecutor *executor) const;
};

#endif // IMPORTINSTRUCTION_H
