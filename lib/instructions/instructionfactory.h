#ifndef INSTRUCTIONFACTORY_H
#define INSTRUCTIONFACTORY_H

#include "instruction.h"

class AssignInstruction;
class CallAndAssignInstruction;
class CallInstruction;
class ImportInstruction;
class InvalidInstruction;
class MakeInstruction;

class InstructionFactory
{
public:
    static Instruction *createInstruction(const QVariantList &tokens);

private:
    InstructionFactory();
    static Instruction *createAssignInstruction(const QString &id, const QVariantList &tokens);
    static Instruction *createCallAndAssignInstruction(const QString &id, const QVariantList &tokens);
    static Instruction *createCallInstruction(const QString &id, const QVariantList &tokens);
    static Instruction *createImportInstruction(const QString &id, const QVariantList &tokens);
    static Instruction *createInvalidInstruction(const QString &id, const QString &name, const QVariantList &tokens);
    static Instruction *createMakeInstruction(const QString &id, const QVariantList &tokens);
};

#endif // INSTRUCTIONFACTORY_H
