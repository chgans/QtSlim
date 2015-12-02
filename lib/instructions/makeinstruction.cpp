#include "makeinstruction.h"
#include "instructionexecutor.h"
#include "successinstructionresult.h"

const QString MakeInstruction::NAME = QStringLiteral("Make");

MakeInstruction::MakeInstruction(const QString &instructionId, const QString &instanceName,
                                 const QString &className, const QVariantList &arguments):
    Instruction(instructionId),
    m_instanceName(instanceName),
    m_className(className),
    m_arguments(arguments)
{

}

InstructionResult *MakeInstruction::execute(InstructionExecutor *executor) const
{
    // TODO: Makes InstructionExecutor return ErrorInstructionResult if can't find constructor
    executor->make(m_instanceName, m_className, m_arguments);
    return new SuccessInstructionResult(instructionId());
}
