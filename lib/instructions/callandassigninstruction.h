#ifndef CALLANDASSIGNINSTRUCTION_H
#define CALLANDASSIGNINSTRUCTION_H

#include "instruction.h"

#include <QStringList>

class CallAndAssignInstruction : public Instruction
{
public:
    CallAndAssignInstruction(const QString &instructionId, const QString &symbolName,
                             const QString &instanceName, const QString &methodName,
                             const QVariantList &arguments);


    QString symbolName() const
    {
        return m_symbolName;
    }

    QString instanceName() const
    {
        return m_instanceName;
    }

    QString methodName() const
    {
        return m_methodName;
    }

    QVariantList arguments() const
    {
        return m_arguments;
    }

    static const QString NAME;

private:
    QString m_symbolName;
    QString m_instanceName;
    QString m_methodName;
    QVariantList m_arguments;

    // Instruction interface
public:
    InstructionResult *execute(InstructionExecutor *executor) const;
    QString toString() const;
};

#endif // CALLANDASSIGNINSTRUCTION_H
