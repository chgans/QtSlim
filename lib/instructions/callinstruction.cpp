#include "callinstruction.h"
#include "instructionexecutor.h"
#include "okinstructionresult.h"
#include "errorinstructionresult.h"
#include "voidinstructionresult.h"

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

    if (!executor->result().isValid()) {
        return new VoidInstructionResult(instructionId());
    }

    return new InstructionResult(instructionId(), executor->result());
}

QString CallInstruction::toString() const
{
    return QString("%1: %2.%3(...)")
            .arg(instructionId())
            .arg(instanceName())
            .arg(methodName());
}
