#include "metamethodinvoker.h"

#include <QGenericArgument>
#include <QGenericReturnArgument>

#include <QLoggingCategory>
Q_DECLARE_LOGGING_CATEGORY(invoker)
Q_LOGGING_CATEGORY(invoker, "qtslim.introspection.invoker")

#define ASSERT_UNREACHABLE_LOCATION() Q_ASSERT(false)

// TODO:
//  - Move parameter conversion into it's own helper class
//  - Decide when/where to do the parameter type checks (setParam(), validate() or invoke())

MetaMethodInvoker::MetaMethodInvoker(const QMetaMethod &metaMethod):
    m_method(metaMethod), m_inspector(metaMethod),
    m_connectionType(Qt::DirectConnection), m_object(nullptr)
{
}

void MetaMethodInvoker::setObject(QObject *object)
{
    m_object = object;
}

void MetaMethodInvoker::setParameters(const QVariantList &parameters)
{
    int count = parameters.count();
    if (count != m_inspector.parameterCount()) {
        setError(QString("Incompatible number of arguments"));
        return ;//false;
    }

    m_parametersStorage.resize(count);
    m_parameters.resize(count);

    for (int index=0; index<count; ++index) {
        storeArgument(index, parameters[index]);
    }
}

bool MetaMethodInvoker::validate()
{
    if (m_object == nullptr && m_method.methodType() != QMetaMethod::Constructor) {
        setError(QString("Object is null"));
        return false;
    }

    if (m_parameters.count() != m_inspector.parameterCount()) {
        setError(QString("Incompatible number of arguments"));
        return false;
    }

    return true;
}

bool MetaMethodInvoker::invoke()
{
    clearError();

    if (m_method.methodType() == QMetaMethod::Constructor) {
        invokeConstructor();
    }
    else if (m_inspector.hasReturnValue()) {
        invokeWithReturn();
    }
    else {
        invokeWithoutReturn();
    }

    return !hasError();
}

bool MetaMethodInvoker::hasResult() const
{
    return !m_returnValueStorage.isNull();
}

QVariant MetaMethodInvoker::result() const
{
    return m_returnValueStorage;
}

bool MetaMethodInvoker::hasError() const
{
    return !m_errorMessage.isNull();
}

QString MetaMethodInvoker::errorMessage() const
{
    return m_errorMessage;
}

void MetaMethodInvoker::invokeConstructor()
{
    const QMetaObject *metaObject = m_method.enclosingMetaObject();

    qCDebug(invoker) << "Invoking constructor for" << metaObject->className();

    QObject *result;
    switch (m_parameters.count()) {
    case 0:
        result = metaObject->newInstance();
        break;
    case 1:
        result = metaObject->newInstance(m_parameters[0]);
        break;
    case 2:
        result = metaObject->newInstance(m_parameters[0], m_parameters[1]);
        break;
    default:
        ASSERT_UNREACHABLE_LOCATION();
        break;
    }

    m_returnValueStorage = QVariant::fromValue<QObject*>(result);

    qCDebug(invoker) << "Return value is" << m_returnValueStorage;

    if (result == nullptr)
        setError("Unknown error (QMetaObject::newInstance())");
}

void MetaMethodInvoker::invokeWithoutReturn()
{
    bool success = false;

    qCDebug(invoker) << "Invoking method" << m_method.methodSignature()
                     << "with" << m_parametersStorage
                     << "on" << m_object ;

    switch (m_parameters.count()) {
    case 0:
        success = m_method.invoke(m_object, m_connectionType);
        break;
    case 1:
        success = m_method.invoke(m_object, m_connectionType,
                                  m_parameters[0]);
        break;
    case 2:
        success = m_method.invoke(m_object, m_connectionType,
                                  m_parameters[0], m_parameters[1]);
        break;
    default:
        ASSERT_UNREACHABLE_LOCATION();
        break;
    }

    if (!success)
        setError("Unknown error (QMetaMethod::invoke())");
}

void MetaMethodInvoker::invokeWithReturn()
{
    bool success;

    qCDebug(invoker) << "Invoking method" << m_method.methodSignature()
                     << "with" << m_parametersStorage
                     << "on" << m_object ;

    prepareReturnArgument();

    switch (m_parameters.count()) {
    case 0:
        success = m_method.invoke(m_object, m_connectionType, m_returnValue);
        break;
    case 1:
        success = m_method.invoke(m_object, m_connectionType, m_returnValue,
                                  m_parameters[0]);
        break;
    case 2:
        success = m_method.invoke(m_object, m_connectionType, m_returnValue,
                                  m_parameters[0], m_parameters[1]);
        break;
    default:
        ASSERT_UNREACHABLE_LOCATION();
        break;
    }

    qCDebug(invoker) << "Return value:" << m_returnValueStorage;

    if (!success)
        setError("Unknown error (QMetaMethod::invoke())");
}

void MetaMethodInvoker::prepareReturnArgument()
{
    const QByteArray typeName = m_inspector.returnValueTypeName();
    QVariant::Type typeId = QVariant::Type(m_inspector.returnValueTypeId());
    m_returnValueStorage = QVariant(typeId);
    m_returnValue = QGenericReturnArgument(typeName.constData(), m_returnValueStorage.data());

    qCDebug(invoker) << "Return value storage:"
                     << "typeName=" << typeName
                     << "typeId=" << typeId;
}

void MetaMethodInvoker::storeArgument(int index, const QVariant &value)
{
    const char *paramName = m_inspector.parameterNames().value(index);
    const char *paramTypeName = value.typeName();
    int paramTypeId = int(value.type());
    const char *toTypeName = m_inspector.parameterTypeNames().value(index);
    int toTypeId = m_inspector.parameterTypeIds().value(index);

    m_parametersStorage[index] = value;
    QVariant &stored = m_parametersStorage[index];
    stored.convert(toTypeId);
    m_parameters[index] = QGenericArgument(toTypeName, stored.constData());

    qCDebug(invoker) << "Argument storage:"
                     << "index=" << index
                     << "name=" << paramName
                     << "typeName=" << paramTypeName
                     << "typeId=" << paramTypeId
                     << "from=" << value
                     << "to=" << stored;
}

void MetaMethodInvoker::setError(const QString &message)
{
    m_errorMessage = message;
    qCWarning(invoker) << m_errorMessage;
}

void MetaMethodInvoker::clearError()
{
    m_errorMessage.clear();
}
