#include "callinstruction.h"
#include "instructionexecutor.h"
#include "successinstructionresult.h"

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
    QString result = executor->call(m_instanceName, m_methodName, m_arguments);
    return new SuccessInstructionResult(instructionId()/*, result*/); // FIXME
}
