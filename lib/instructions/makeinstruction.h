#ifndef MAKEINSTRUCTION_H
#define MAKEINSTRUCTION_H

#include "instruction.h"

#include <QStringList>

class MakeInstruction : public Instruction
{
public:
    MakeInstruction(const QString &instructionId, const QString &instanceName,
                    const QString &className, const QVariantList &arguments);

    QString instanceName() const
    {
        return m_instanceName;
    }

    QString className() const
    {
        return m_className;
    }

    QVariantList arguments() const
    {
        return m_arguments;
    }

    static const QString NAME;

private:
    QString m_instanceName;
    QString m_className;
    QVariantList m_arguments;

    // Instruction interface
public:
    InstructionResult *execute(InstructionExecutor *executor) const;
    QString toString() const;
};

#endif // MAKEINSTRUCTION_H
