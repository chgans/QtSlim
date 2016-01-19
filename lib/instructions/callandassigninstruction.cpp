#include "callandassigninstruction.h"
#include "instructionexecutor.h"

#include "okinstructionresult.h"
#include "errorinstructionresult.h"
#include "voidinstructionresult.h"

const QString CallAndAssignInstruction::NAME = QStringLiteral("CallAndAssign");

CallAndAssignInstruction::CallAndAssignInstruction(const QString &instructionId, const QString &symbolName,
                                                   const QString &instanceName, const QString &methodName,
                                                   const QVariantList &arguments):
    Instruction(instructionId),
    m_symbolName(symbolName),
    m_instanceName(instanceName),
    m_methodName(methodName),
    m_arguments(arguments)
{

}

InstructionResult *CallAndAssignInstruction::execute(InstructionExecutor *executor) const
{
    if (!executor->callAndAssign(m_symbolName, m_instanceName, m_methodName, m_arguments)) {
        return new ErrorInstructionResult(instructionId(), executor->errorString());
    }

    QVariant result = executor->result();
    if (!result.isValid()) {
        return new VoidInstructionResult(instructionId());
    }

    return new InstructionResult(instructionId(), result);
}

QString CallAndAssignInstruction::toString() const
{
    return QString("%1: %2 = %3.%4(...)")
            .arg(instructionId())
            .arg(symbolName())
            .arg(instanceName())
            .arg(methodName());
}
