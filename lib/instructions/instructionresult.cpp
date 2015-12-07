#include "instructionresult.h"

InstructionResult::InstructionResult(const QString &id, const QVariant &value):
    m_id(id),
    m_value(value)
{
}

QString InstructionResult::id() const
{
    return m_id;
}

QVariant InstructionResult::result() const
{
    return m_value;
}

bool InstructionResult::hasResult() const
{
    return m_value.isValid();
}

bool InstructionResult::hasError() const
{
    return false;
}

