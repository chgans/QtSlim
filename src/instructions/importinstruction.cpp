#include "importinstruction.h"
#include "instructionexecutor.h"
#include "successinstructionresult.h"

const QString ImportInstruction::NAME = QStringLiteral("Import");

ImportInstruction::ImportInstruction(const QString &instructionId, const QString &path):
    Instruction(instructionId),
    m_path(path)
{

}

InstructionResult *ImportInstruction::execute(InstructionExecutor *executor) const
{
    executor->import(m_path);
    return new SuccessInstructionResult(instructionId());
}
