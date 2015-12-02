#include "instructionexecutor.h"

InstructionExecutor::InstructionExecutor()
{

}

QString InstructionExecutor::lastErrorString() const
{
    return m_errorString;
}

void InstructionExecutor::setErrorString(const QString &error)
{
    m_errorString = error;
}

void InstructionExecutor::clearErrorString()
{
    m_errorString.clear();
}

