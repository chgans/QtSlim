#include "importinstruction.h"
#include "instructionexecutor.h"
#include "voidinstructionresult.h"
#include "errorinstructionresult.h"

const QString ImportInstruction::NAME = QStringLiteral("Import");

ImportInstruction::ImportInstruction(const QString &instructionId, const QString &path):
    Instruction(instructionId),
    m_path(path)
{

}

InstructionResult *ImportInstruction::execute(InstructionExecutor *executor) const
{
    if (!executor->import(m_path))
        return new ErrorInstructionResult(instructionId(), executor->errorString());
    return new VoidInstructionResult(instructionId());
}
