#include "errorinstructionresult.h"

ErrorInstructionResult::ErrorInstructionResult(const QString &id, const QString &message):
    InstructionResult(id, QString("message:<<%1>>").arg(message))
{

}

