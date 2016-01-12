#include "metaobjectexecutor.h"

#include "introspection/metaobjectmaker.h"
#include "introspection/metamethodinvoker.h"

#include <QLoggingCategory>
Q_DECLARE_LOGGING_CATEGORY(executor)
Q_LOGGING_CATEGORY(executor, "qtslim.execution.executor", QtWarningMsg)

MetaObjectExecutor::MetaObjectExecutor():
    InstructionExecutor()
{
}

void MetaObjectExecutor::addMetaObject(const QMetaObject *metaObject)
{
    m_metaObjectDictionary[metaObject->className()] = metaObject;
    qCDebug(executor) << "Added" << metaObject->className() << "to the meta object dictionary";
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
    clearResult();

    qCDebug(executor) << "Calling" << methodName
                      << "on" << instanceName
                      << "with" << arguments;

    if (!m_objectDictionary.contains(instanceName)) {
        setError("Object not found");
        return false;
    }

    QObject *object = m_objectDictionary.value(instanceName);
    MetaObjectInspector inspector(*object->metaObject());
    qCDebug(executor) << "Object class is" <<  object->metaObject()->className();
    MetaMethodList methods = inspector.allMethods()
            .filterByName(methodName)
            .filterByArgumentCount(arguments.count());
    qCDebug(executor) << "Found" << methods.count() << "candidate(s)";

    foreach (const QMetaMethod &method, methods) {
        MetaMethodInvoker invoker(method);
        invoker.setObject(object);
        invoker.setParameters(arguments);
        if (!invoker.invoke())
            continue;
        setResult(invoker.result());
        return true;
    }
    setError("No compatible method found");
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
    clearResult();

    qCDebug(executor) << "Making" << instanceName << "of class" << className;

    if (m_objectDictionary.contains(instanceName)) {
        setError("Object already exists");
        return false;
    }

    if (!m_metaObjectDictionary.contains(className)) {
        setError("Unknown class name");
        return false;
    }

    MetaObjectMaker maker(*m_metaObjectDictionary.value(className));
    maker.setParameters(arguments);
    if (!maker.make()) {
        setError(maker.errorMessage());
        return false;
    }

    m_objectDictionary.insert(instanceName, maker.object());
    return true;
}

