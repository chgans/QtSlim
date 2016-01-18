#include "metaobjectexecutor.h"

#include "introspection/metaobjectmaker.h"
#include "introspection/metamethodinvoker.h"

#include "slimexecutioncontext.h"

#include <QLoggingCategory>
Q_DECLARE_LOGGING_CATEGORY(executor)
Q_LOGGING_CATEGORY(executor, "qtslim.execution.executor", QtDebugMsg)

MetaObjectExecutor::MetaObjectExecutor():
    InstructionExecutor()
{
}

MetaObjectExecutor::~MetaObjectExecutor()
{

}

void MetaObjectExecutor::addMetaObject(const QMetaObject *metaObject)
{
    m_metaObjectDictionary[metaObject->className()] = metaObject;
    qCDebug(executor) << "Added" << metaObject->className() << "to the meta object dictionary";
}

void MetaObjectExecutor::addMetaObjects(QList<const QMetaObject *> metaObjects)
{
    foreach (auto metaObject, metaObjects) {
        addMetaObject(metaObject);
    }
}

void MetaObjectExecutor::setExecutionContext(SlimExecutionContext *context)
{
    m_context = context;
}

const QMetaObject *MetaObjectExecutor::resolveMetaObject(const QString &className)
{
    if (m_metaObjectDictionary.contains(className))
        return m_metaObjectDictionary.value(className);
    foreach (const QString nameSpace, m_context->pathList()) {
        QString name = nameSpace + "::" + className;
        if (m_metaObjectDictionary.contains(name))
            return m_metaObjectDictionary.value(name);
    }
    return nullptr;
}

bool MetaObjectExecutor::assign(const QString &name, const QString &value)
{
    qCDebug(executor) << "Assiging" << value
                      << "to" << name;

    QString finalString = m_context->expandVariables(value);
    m_context->setVariable(name, QVariant(finalString));

    return true;
}

bool MetaObjectExecutor::callAndAssign(const QString &symbolName, const QString &instanceName,
                                       const QString &methodName, const QVariantList &arguments)
{
    if (!call(instanceName, methodName, arguments))
        return false;

    // FIXME: check valid result?
    return assign(symbolName, result().toString());
}

bool MetaObjectExecutor::call(const QString &instanceName, const QString &methodName,
                              const QVariantList &arguments)
{
    clearResult();

    qCDebug(executor) << "Calling" << methodName
                      << "on" << instanceName
                      << "with" << arguments;

    QObject *object = m_context->instance(instanceName);

    if (object == nullptr) {
        setError("Object not found");
        return false;
    }

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
    clearErrorString();
    clearResult();
    QString nameSpace = path;
    nameSpace.replace(".", "::");
    qCDebug(executor) << "Adding namespace" << nameSpace;
    m_context->addPath(nameSpace);
    return true;
}

bool MetaObjectExecutor::make(const QString &instanceName, const QString &className,
                              const QVariantList &arguments)
{
    clearResult();

    qCDebug(executor) << "Making" << instanceName << "of class" << className;
    QString resolvedClassName = m_context->expandVariables(className);
    qCDebug(executor) << className << "resolved to" << resolvedClassName;

    if (m_context->instance(instanceName) != nullptr) {
        setError("Object already exists");
        return false;
    }

    const QMetaObject *metaObject = resolveMetaObject(resolvedClassName);
    if (metaObject == nullptr) {
        setError("Unknown class name");
        return false;
    }

    MetaObjectMaker maker(*metaObject);
    maker.setParameters(arguments);
    if (!maker.make()) {
        setError(maker.errorMessage());
        return false;
    }

    m_context->setInstance(instanceName, maker.object());
    return true;
}

