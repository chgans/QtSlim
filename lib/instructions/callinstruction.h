#ifndef CALLINSTRUCTION_H
#define CALLINSTRUCTION_H

#include "instruction.h"

#include <QStringList>

class CallInstruction : public Instruction
{
public:
    CallInstruction(const QString &instructionId, const QString &instanceName,
                    const QString &methodName, const QVariantList &arguments);

    QString instanceName() const
    {
        return m_instanceName;
    }

    QString methodName() const
    {
        return m_methodName;
    }

    QStringList arguments() const
    {
        return QStringList(); //m_arguments;
    }

    static const QString NAME;

private:
    QString m_instanceName;
    QString m_methodName;
    QVariantList m_arguments;

    // Instruction interface
public:
    InstructionResult *execute(InstructionExecutor *executor) const;
};

#endif // CALLINSTRUCTION_H
