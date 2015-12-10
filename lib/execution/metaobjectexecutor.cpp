#include "metaobjectexecutor.h"

MetaObjectExecutor::MetaObjectExecutor():
    InstructionExecutor()
{
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
    Q_UNUSED(instanceName);
    Q_UNUSED(className);
    Q_UNUSED(arguments);

    clearErrorString();
    clearResult();

    setError("Not implemented");
    return false;
}

