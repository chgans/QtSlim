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

private:
    QMap<QString, const QMetaObject* > m_metaObjectDictionary;
    void addMetaObject(const QMetaObject* metaObject);

    QMap<QString, QObject* > m_objectDictionary;

    // InstructionExecutor interface
public:
    void assign(const QString &name, const QString &value);
    QString callAndAssign(const QString &symbolName,
                          const QString &instanceName,
                          const QString &methodName,
                          const QVariantList &arguments);
    QString call(const QString &instanceName,
                 const QString &methodName,
                 const QVariantList &arguments);
    void import(const QString &path);
    void make(const QString &instanceName,
              const QString &className,
              const QVariantList &arguments);
};

#endif // METAOBJECTEXECUTOR_H
