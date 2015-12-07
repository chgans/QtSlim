#include "instructionexecutor.h"

InstructionExecutor::InstructionExecutor()
{

}

QVariant InstructionExecutor::result() const
{
    return m_result;
}

QString InstructionExecutor::errorString() const
{
    return m_errorString;
}

void InstructionExecutor::setError(const QString &error)
{
    m_errorString = error;
}

void InstructionExecutor::clearErrorString()
{
    m_errorString.clear();
}

void InstructionExecutor::setResult(const QVariant &result)
{
    m_result = result;
}

void InstructionExecutor::clearResult()
{
    m_result.clear();
}

