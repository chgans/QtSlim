#include <QDebug>

#include "instructionfactory.h"
#include "assigninstruction.h"
#include "callandassigninstruction.h"
#include "callinstruction.h"
#include "importinstruction.h"
#include "invalidinstruction.h"
#include "makeinstruction.h"

template<typename T> bool sameNames(const QString &name)
{
    return name.compare(T::NAME, Qt::CaseInsensitive) == 0;
}

InstructionFactory::InstructionFactory()
{

}

Instruction *InstructionFactory::createInstruction(const QVariantList &tokens)
{

    // FIXME: fatal error here as we expect at least an id and a name
    // We cannot return an invalid instruction if we don't have an id,
    // no instruction name is OK thought.
    if (tokens.size() < 2)
        return createInvalidInstruction("UNKNOWN_ID", "UNKNOWN_NAME", QVariantList());

    QString id = tokens.at(0).toString();
    if (id.isNull()) {
        return createInvalidInstruction("BAD_ID", "UNKNOWN_NAME", QVariantList());
    }
    QString name = tokens.at(1).toString();
    if (name.isNull()) {
        return createInvalidInstruction(id, "BAD_NAME", QVariantList());
    }

    QVariantList arguments = tokens.mid(2);

    if (sameNames<AssignInstruction>(name))
        return createAssignInstruction(id, arguments);
    else if (sameNames<CallAndAssignInstruction>(name))
        return createCallAndAssignInstruction(id, arguments);
    else if (sameNames<CallInstruction>(name))
        return createCallInstruction(id, arguments);
    else if (sameNames<MakeInstruction>(name))
        return createMakeInstruction(id, arguments);
    else if (sameNames<ImportInstruction>(name))
        return createImportInstruction(id, arguments);
    else
        return createInvalidInstruction(id, name, arguments);
}

Instruction *InstructionFactory::createAssignInstruction(const QString &id, const QVariantList &tokens)
{
    if (tokens.count() != 2)
        return new InvalidInstruction(id, AssignInstruction::NAME);
    QString name = tokens[0].toString();
    QString value = tokens[1].toString();
    return new AssignInstruction(id, name, value);
}

Instruction *InstructionFactory::createCallAndAssignInstruction(const QString &id, const QVariantList &tokens)
{
    if (tokens.count() < 3)
        return new InvalidInstruction(id, CallAndAssignInstruction::NAME);
    QString symbolName = tokens[0].toString();
    QString instanceName = tokens[1].toString();
    QString methodName = tokens[2].toString();
    QVariantList args = tokens.mid(3);
    return new CallAndAssignInstruction(id, symbolName, instanceName, methodName, args);
}

Instruction *InstructionFactory::createCallInstruction(const QString &id, const QVariantList &tokens)
{
    if (tokens.count() < 2)
        return new InvalidInstruction(id, CallInstruction::NAME);
    QString instanceName = tokens[0].toString();
    QString methodName = tokens[1].toString();
    QVariantList args = tokens.mid(2);
    return new CallInstruction(id, instanceName, methodName, args);
}

Instruction *InstructionFactory::createImportInstruction(const QString &id, const QVariantList &tokens)
{
    if (tokens.count() != 1)
        return new InvalidInstruction(id, ImportInstruction::NAME);
    QString path = tokens[0].toString();
    return new ImportInstruction(id, path);
}

Instruction *InstructionFactory::createInvalidInstruction(const QString &id, const QString &name, const QVariantList &tokens)
{
    Q_UNUSED(tokens);
    return new InvalidInstruction(id, name);
}

Instruction *InstructionFactory::createMakeInstruction(const QString &id, const QVariantList &tokens)
{
    if (tokens.count() < 2)
        return new InvalidInstruction(id, MakeInstruction::NAME);
    QString instanceName = tokens[0].toString();
    QString className = tokens[1].toString();
    QVariantList args = tokens.mid(2);
    return new MakeInstruction(id, instanceName, className, args);
}

