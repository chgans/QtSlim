#ifndef INSTRUCTIONFACTORY_H
#define INSTRUCTIONFACTORY_H

#include "instruction.h"
#include "../slimstring.h"

class AssignInstruction;
class CallAndAssignInstruction;
class CallInstruction;
class ImportInstruction;
class InvalidInstruction;
class MakeInstruction;

class InstructionFactory
{
public:
    static Instruction *createInstruction(const SlimStringList &words);

private:
    InstructionFactory();
    static Instruction *createAssignInstruction(const QString &id, const SlimStringList &words);
    static Instruction *createCallAndAssignInstruction(const QString &id, const SlimStringList &words);
    static Instruction *createCallInstruction(const QString &id, const SlimStringList &words);
    static Instruction *createImportInstruction(const QString &id, const SlimStringList &words);
    static Instruction *createInvalidInstruction(const QString &id, const QString &name, const SlimStringList &words);
    static Instruction *createMakeInstruction(const QString &id, const SlimStringList &words);
};

#endif // INSTRUCTIONFACTORY_H
