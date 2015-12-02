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

Instruction *InstructionFactory::createInstruction(const SlimStringList &words)
{

    // FIXME: fatal error here as we expect at least an id and a name
    // We cannot return an invalid instruction if we don't have an id,
    // no instruction name is OK thought.
    if (words.size() < 2)
        return createInvalidInstruction("UNKNOWN_ID", "UNKNOWN_NAME", SlimStringList());

    SlimString idStr = words.at(0);
    if (!idStr.isValid() || idStr.isList()) {
        return createInvalidInstruction("BAD_ID", "UNKNOWN_NAME", SlimStringList());
    }
    QString id = idStr.value();

    SlimString nameStr = words.at(1);
    if (!nameStr.isValid() || nameStr.isList()) {
        return createInvalidInstruction(id, "BAD_NAME", SlimStringList());
    }
    QString name = nameStr.value();

    SlimStringList arguments = words.mid(2);

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

QVariantList extractArgs(const SlimStringList &words, int fromIndex = 0)
{
    QVariantList args;
    if (words.count() <= fromIndex)
        return QVariantList();
    for (int i=fromIndex; i<words.count(); i++) {
        SlimString word = words[i];
        if (!word.isValid()) {
            // FIXME
            continue;
        }
        else if (word.isList()) {
            args.append(extractArgs(word.toList()));
        }
        else
            args.append(word.value());
    }
    return args;
}

Instruction *InstructionFactory::createAssignInstruction(const QString &id, const SlimStringList &words)
{
    if (words.count() < 2)
        return new InvalidInstruction(id, AssignInstruction::NAME);
    QString name = words[0].value();
    QString value = words[1].value();
    return new AssignInstruction(id, name, value);
}

Instruction *InstructionFactory::createCallAndAssignInstruction(const QString &id, const SlimStringList &words)
{
    if (words.count() < 3)
        return new InvalidInstruction(id, CallAndAssignInstruction::NAME);
    QString symbolName = words[0].value();
    QString instanceName = words[1].value();
    QString methodName = words[2].value();
    QVariantList args = extractArgs(words, 3);
    return new CallAndAssignInstruction(id, symbolName, instanceName, methodName, args);
}

Instruction *InstructionFactory::createCallInstruction(const QString &id, const SlimStringList &words)
{
    if (words.count() < 2)
        return new InvalidInstruction(id, CallInstruction::NAME);
    QString instanceName = words[0].value();
    QString methodName = words[1].value();
    // BEGIN FIXME: add function that support QList<QString> and QList<QList<QString>>
    // or SlimString::(is|to)(String|StringList|StringTable)
    QVariantList args = extractArgs(words, 2);
    return new CallInstruction(id, instanceName, methodName, args);
}

Instruction *InstructionFactory::createImportInstruction(const QString &id, const SlimStringList &words)
{
    if (words.count() < 1)
        return new InvalidInstruction(id, ImportInstruction::NAME);
    QString path = words[0].value();
    return new ImportInstruction(id, path);
}

Instruction *InstructionFactory::createInvalidInstruction(const QString &id, const QString &name, const SlimStringList &words)
{
    Q_UNUSED(words);
    return new InvalidInstruction(id, name);
}

Instruction *InstructionFactory::createMakeInstruction(const QString &id, const SlimStringList &words)
{
    if (words.count() < 2)
        return new InvalidInstruction(id, MakeInstruction::NAME);
    QString instanceName = words[0].value();
    QString className = words[1].value();
    QVariantList args = extractArgs(words, 2);
    return new MakeInstruction(id, instanceName, className, args);
}

