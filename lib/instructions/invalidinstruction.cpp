#include "invalidinstruction.h"
#include "errorinstructionresult.h"

InvalidInstruction::InvalidInstruction(const QString &instructionId, const QString &operationName):
    Instruction(instructionId),
    m_operationName(operationName)
{

}

InstructionResult *InvalidInstruction::execute(InstructionExecutor *executor) const
{
    Q_UNUSED(executor);
    return new ErrorInstructionResult(instructionId(), QString("%1: Invalid instruction").arg(m_operationName));
}

QString InvalidInstruction::toString() const
{
    return QString("%1: !INVALID_INSTRUCTION!")
            .arg(instructionId());
}
