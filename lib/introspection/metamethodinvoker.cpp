#include "metamethodinvoker.h"

#include <QGenericArgument>
#include <QGenericReturnArgument>

#include <QDebug>

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
    if (parameters.count() != m_inspector.parameterCount()) {
        setError(QString("Incompatible number of arguments"));
        return ;//false;
    }

    m_parametersStorage.clear();
    m_parameters.clear();

    QList<int> typeIds = m_inspector.parameterTypeIds();
    QList<QByteArray> typeNames = m_inspector.parameterTypeNames();

    for (int index=0; index<m_inspector.parameterCount(); ++index) {
        QVariant value = parameters[index];
        int typeId = typeIds[index];
        value.convert(typeId);
        m_parametersStorage.append(value);
        const QVariant &stored = m_parametersStorage[index];
        QByteArray typeName = typeNames[index];
        m_parameters.append(QGenericArgument(typeName.constData(), stored.constData()));
    }
}

bool MetaMethodInvoker::validate()
{
    if (m_object == nullptr) {
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

    if (m_inspector.hasReturnValue()) {
        invokeWithReturn();
    }
    else {
        invokeWithoutReturn();
    }

    return !hasError();
}

bool MetaMethodInvoker::hasError() const
{
    return !m_errorMessage.isNull();
}

QString MetaMethodInvoker::errorMessage() const
{
    return m_errorMessage;
}

void MetaMethodInvoker::invokeWithoutReturn()
{
    bool success;

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

    if (!success)
        setError("Unknown error (QMetaMethod::invoke())");
}

void MetaMethodInvoker::setError(const QString &message)
{
    m_errorMessage = message;
}

void MetaMethodInvoker::clearError()
{
    m_errorMessage.clear();
}
