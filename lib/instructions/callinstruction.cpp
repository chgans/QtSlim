#include "callinstruction.h"
#include "instructionexecutor.h"
#include "okinstructionresult.h"
#include "errorinstructionresult.h"

const QString CallInstruction::NAME = QStringLiteral("Call");

CallInstruction::CallInstruction(const QString &instructionId, const QString &instanceName,
                                 const QString &methodName, const QVariantList &arguments):
    Instruction(instructionId),
    m_instanceName(instanceName),
    m_methodName(methodName),
    m_arguments(arguments)
{

}

InstructionResult *CallInstruction::execute(InstructionExecutor *executor) const
{
    if (!executor->call(m_instanceName, m_methodName, m_arguments)) {
        return new ErrorInstructionResult(instructionId(), executor->errorString());
    }
    // FIXME: call returning void vs non-void
    return new InstructionResult(instructionId(), executor->result());
}
