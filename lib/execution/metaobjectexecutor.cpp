#include "metaobjectexecutor.h"

#include "division.h"

#include <QMetaMethod>

#include <QDebug>

MetaObjectExecutor::MetaObjectExecutor():
    InstructionExecutor()
{
    addMetaObject(&Division::staticMetaObject);
}

void MetaObjectExecutor::addMetaObject(const QMetaObject *metaObject)
{
    m_metaObjectDictionary[metaObject->className()] = metaObject;
}

void MetaObjectExecutor::assign(const QString &name, const QString &value)
{
    Q_UNUSED(name);
    Q_UNUSED(value);
}

QString MetaObjectExecutor::callAndAssign(const QString &symbolName,
                                          const QString &instanceName,
                                          const QString &methodName,
                                          const QVariantList &arguments)
{
    Q_UNUSED(symbolName);
    Q_UNUSED(instanceName);
    Q_UNUSED(methodName);
    Q_UNUSED(arguments);
    return QString();
}

QString MetaObjectExecutor::call(const QString &instanceName,
                                 const QString &methodName,
                                 const QVariantList &arguments)
{
    if (!m_objectDictionary.contains(instanceName)) {
        qWarning() << instanceName << ":No object intance known by that name";
        return QString();
    }

    QObject *object = m_objectDictionary.value(instanceName);
    const QMetaObject metaObject = object->staticMetaObject;

    const char *member = methodName.toUtf8().data();
    int methodIndex = metaObject.indexOfMethod(member);
    if (methodIndex == -1) {
        qWarning() << methodName << ":Method not found on instance" << instanceName;
        return QString();
    }

    QMetaMethod metaMethod = metaObject.method(methodIndex);

    QGenericReturnArgument returnedArg;
    int returnedArgType = metaMethod.returnType();
    qreal realReturnedArg;
    if ( returnedArgType == QMetaType::QReal)
        returnedArg = Q_RETURN_ARG(qreal, realReturnedArg);
    else {
        qWarning() << methodName << ": Unhandled returned argument type";
        return QString();
    }

    Q_UNUSED(arguments);

    bool success = metaMethod.invoke(object, returnedArg);
    if (!success) {
        qWarning() << methodName << ":Calling of this method name failed";
        return QString();
    }

    if ( returnedArgType == QMetaType::QReal)
        return QString("%1").arg(realReturnedArg);
    return QString();
}

void MetaObjectExecutor::import(const QString &path)
{
    Q_UNUSED(path);
}

void MetaObjectExecutor::make(const QString &instanceName,
                              const QString &className,
                              const QVariantList &arguments)
{
    if (!m_metaObjectDictionary.contains(className)) {
        qWarning() << className << ": No meta object found";
        return;
    }

    if (m_objectDictionary.contains(instanceName)) {
        qWarning() << instanceName << ": An object with same instance name already exists";
        return;
    }

    Q_UNUSED(arguments)
    const QMetaObject *metaObject = m_metaObjectDictionary.value(className);
    QObject *object = metaObject->newInstance();
    if (object == nullptr) {
        qWarning() << instanceName << className << ": Construction failed";
        return;
    }

    m_objectDictionary[instanceName] = object;
}

