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

QVariant InstructionResult::value() const
{
    return m_value;
}

