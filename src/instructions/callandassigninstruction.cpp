#include "callandassigninstruction.h"
#include "instructionexecutor.h"
#include "successinstructionresult.h"

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
    QString result = executor->callAndAssign(m_symbolName, m_instanceName, m_methodName, m_arguments);
    return new SuccessInstructionResult(instructionId()/*FIXME: , result*/);
}
