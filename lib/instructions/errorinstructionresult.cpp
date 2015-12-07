#include "errorinstructionresult.h"

ErrorInstructionResult::ErrorInstructionResult(const QString &id, const QString &message):
    InstructionResult(id, QString("__EXCEPTION__:message:<<%1>>").arg(message))
{

}

