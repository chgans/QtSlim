#include "instruction.h"

Instruction::Instruction(const QString &id):
    m_id(id)
{

}

QString Instruction::instructionId() const
{
    return m_id;
}

