#include "metaobjectexecutor.h"
#include "division.h"

#include <QMetaMethod>
#include <QDebug>

// These can be useful:
// - https://gist.github.com/andref/2838534
// - http://stackoverflow.com/questions/7721923/calling-qmetaobjectinvokemethod-with-variable-amount-of-parameters
// - http://delta.affinix.com/2006/08/14/invokemethodwithvariants/
// - https://github.com/mikeprevas/QSlim


MetaObjectExecutor::MetaObjectExecutor():
    InstructionExecutor()
{
    addMetaObject(&Division::staticMetaObject);
}

void MetaObjectExecutor::addMetaObject(const QMetaObject *metaObject)
{
    m_metaObjectDictionary[metaObject->className()] = metaObject;
}

bool MetaObjectExecutor::assign(const QString &name, const QString &value)
{
    Q_UNUSED(name);
    Q_UNUSED(value);

    clearErrorString();
    clearResult();

    setError("Not implemented");
    return false;
}

bool MetaObjectExecutor::callAndAssign(const QString &symbolName, const QString &instanceName,
                                       const QString &methodName, const QVariantList &arguments)
{
    Q_UNUSED(symbolName);
    Q_UNUSED(instanceName);
    Q_UNUSED(methodName);
    Q_UNUSED(arguments);

    clearErrorString();
    clearResult();

    setError("Not implemented");
    return false;
}

bool MetaObjectExecutor::call(const QString &instanceName, const QString &methodName,
                              const QVariantList &arguments)
{
    Q_UNUSED(instanceName);
    Q_UNUSED(methodName);
    Q_UNUSED(arguments);

    clearErrorString();
    clearResult();

    setError("Not implemented");
    return false;
}

bool MetaObjectExecutor::import(const QString &path)
{
    Q_UNUSED(path);

    clearErrorString();
    clearResult();

    setError("Not implemented");
    return false;
}

bool MetaObjectExecutor::make(const QString &instanceName, const QString &className,
                              const QVariantList &arguments)
{
    clearErrorString();
    clearResult();

    if (!m_metaObjectDictionary.contains(className)) {
        setError(QString("%1: Class not found").arg(className));
        return false;
    }

    if (m_objectDictionary.contains(instanceName)) {
        setError(QString("%1: Object already exists").arg(instanceName));
        return false;
    }

    Q_UNUSED(arguments)
    const QMetaObject *metaObject = m_metaObjectDictionary.value(className);
    QObject *object = metaObject->newInstance();
    if (object == nullptr) {
        setError(QString("%1: Construction failed").arg(className));
        return false;
    }

    m_objectDictionary[instanceName] = object;
    return true;
}

