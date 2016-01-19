#include "makeinstruction.h"
#include "instructionexecutor.h"
#include "okinstructionresult.h"
#include "errorinstructionresult.h"

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
    if (!executor->make(m_instanceName, m_className, m_arguments))
        return new ErrorInstructionResult(instructionId(), executor->errorString());
    return new OkInstructionResult(instructionId());
}

QString MakeInstruction::toString() const
{
    return QString("%1: %2 = new %3(...)")
            .arg(instructionId())
            .arg(instanceName())
            .arg(className());
}
