#ifndef METAOBJECTEXECUTOR_H
#define METAOBJECTEXECUTOR_H

#include "instructions/instructionexecutor.h"

#include <QString>
#include <QMetaObject>
#include <QMap>

class MetaObjectExecutor: public InstructionExecutor
{
public:
    MetaObjectExecutor();
    void addMetaObject(const QMetaObject* metaObject);

private:
    QMap<QString, const QMetaObject* > m_metaObjectDictionary;

    QMap<QString, QObject* > m_objectDictionary;
    QMap<QString, QString> m_symbolMap;

    // InstructionExecutor interface
public:
    bool assign(const QString &name, const QString &value);
    bool callAndAssign(const QString &symbolName, const QString &instanceName,
                       const QString &methodName, const QVariantList &arguments);
    bool call(const QString &instanceName, const QString &methodName,
              const QVariantList &arguments);
    bool import(const QString &path);
    bool make(const QString &instanceName, const QString &className,
              const QVariantList &arguments);
};

#endif // METAOBJECTEXECUTOR_H
