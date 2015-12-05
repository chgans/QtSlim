#include "assigninstruction.h"
#include "instructionexecutor.h"
#include "successinstructionresult.h"

const QString AssignInstruction::NAME = QStringLiteral("Assign");

AssignInstruction::AssignInstruction(const QString &instructionId, const QString &symbolName,
                                     const QString &value):
    Instruction(instructionId),
    m_symbolName(symbolName),
    m_value(value)
{

}

InstructionResult *AssignInstruction::execute(InstructionExecutor *executor) const
{
    executor->assign(m_symbolName, m_value);
    return new SuccessInstructionResult(instructionId());
}