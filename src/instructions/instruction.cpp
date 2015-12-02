#include "instruction.h"

Instruction::Instruction(const QString &id):
    m_id(id)
{

}

Instruction::~Instruction()
{

}

QString Instruction::instructionId() const
{
    return m_id;
}

