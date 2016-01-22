#include "metaobjectexecutor.h"

#include "introspection/metaobjectmaker.h"
#include "introspection/metamethodinvoker.h"

#include "slimexecutioncontext.h"

#include <QLoggingCategory>
Q_DECLARE_LOGGING_CATEGORY(executor)
Q_LOGGING_CATEGORY(executor, "qtslim.execution.executor")

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

bool MetaObjectExecutor::invokeMethod(QObject *object, const QString &methodName, const QVariantList &arguments)
{
    qCDebug(executor) << "Trying method" << methodName
                      << "on" << object;

    MetaObjectInspector inspector(*object->metaObject());
    MetaMethodList methods = inspector.allMethods()
            .filterByName(methodName)
            .filterByArgumentCount(arguments.count());

    foreach (const QMetaMethod &method, methods) {
        MetaMethodInvoker invoker(method);
        invoker.setObject(object);
        QVariantList finalArguments = m_context->expandVariables(arguments);
        invoker.setParameters(finalArguments);
        if (!invoker.invoke()) {
            qCDebug(executor) << "Invocation failed:" << invoker.errorMessage();
            continue;
        }
        qCDebug(executor) << "Invocation succeed";
        setResult(invoker.result());
        return true;
    }
    qCDebug(executor) << "All invocation failed";
    return false;
}

bool MetaObjectExecutor::assign(const QString &name, const QVariant &value)
{
    qCDebug(executor) << "Assigning" << value
                      << "to" << name;

    QVariant finalValue = m_context->expandVariables(value);
    m_context->setVariable(name, finalValue);

    return true;
}

bool MetaObjectExecutor::callAndAssign(const QString &symbolName, const QString &instanceName,
                                       const QString &methodName, const QVariantList &arguments)
{
    if (!call(instanceName, methodName, arguments))
        return false;

    // FIXME: check valid result?
    return assign(symbolName, result());
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

    if (invokeMethod(object, methodName, arguments) == true)
        return true;

    // [0.1] Library Instances: If a method specified by a Call or CallAndAssign is not found
    // on either the specified instance, or on the System Under Test then the stack of library
    // objects is searched, starting at the top (latest). If the method is found, it is called.
    foreach (QObject *object, m_context->libraries()) {
        if (invokeMethod(object, methodName, arguments) == true)
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

    // [0.3] Symbol Copy: If <class> consists entirely of a single symbol name prefixed with $,
    // then the item from the dictionary of symbol values with the symbol name is added to the
    // dictionary of created objects with the name <instance>. The <arg> strings are ignored and
    // no constructor is called.
    // FIXME: moves this to context?
//    if (m_context->isSymbolReferenceToObject(classNAme)) {
//        qCDebug(executor) << "Making object" << instanceName << "from symbol" << symbolName;
//        QObject *object = m_context->getSymbolAsObject(className);
//        m_context->addObject(instanceName, object);
//        return true;
//    }
    if (className.startsWith('$')) {
        QString symbolName = className.mid(1);
        if (m_context->variable(symbolName).isValid()) {
            QVariant symbolValue = m_context->variable(symbolName);
            qCDebug(executor) << "Making object" << instanceName << "from symbol" << symbolName << symbolValue;
            QObject *object = symbolValue.value<QObject *>();
            if (object == nullptr) {
                setError("Object not found");
            }
            else {
                m_context->setInstance(instanceName, object);
                return true;
            }
        }
    }

    qCDebug(executor) << "Making" << instanceName << "of class" << className;
    QString resolvedClassName = m_context->expandVariables(className);
    qCDebug(executor) << className << "resolved to" << resolvedClassName;

    if (m_context->instance(instanceName) != nullptr) {
#if 0 // FIXME: check if this is a valid case, it seems to happen with "scriptTableActor"
        setError("Object already exists");
        return false;
#else
        //delete m_context->instance(instanceName); // fixme: properly remove it
        qCWarning(executor) << ("Object already exists");
#endif
    }

    const QMetaObject *metaObject = resolveMetaObject(resolvedClassName);
    if (metaObject == nullptr) {
        setError("Unknown class name");
        return false;
    }

    MetaObjectMaker maker(*metaObject);
    QVariantList finalArguments = m_context->expandVariables(arguments);
    maker.setParameters(finalArguments);
    if (!maker.make()) {
        setError(maker.errorMessage());
        return false;
    }

    m_context->setInstance(instanceName, maker.object());
    return true;
}

