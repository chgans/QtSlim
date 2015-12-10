#include "metamethodinspector.h"

MetaMethodInspector::MetaMethodInspector(const QMetaMethod &metaMethod):
    m_metaMethod(metaMethod)
{

}

int MetaMethodInspector::parameterCount() const
{
    return m_metaMethod.parameterCount();
}

QList<int> MetaMethodInspector::parameterTypeIds() const
{
    QList<int> result;
    for (int index=0; index<m_metaMethod.parameterCount(); index++) {
        result.append(m_metaMethod.parameterType(index));
    }
    return result;
}

QList<QByteArray> MetaMethodInspector::parameterTypeNames() const
{
    QList<QByteArray> result;
    foreach (const QByteArray &name, m_metaMethod.parameterTypes()) {
        result.append(name);
    }
    return result;
}

QList<QByteArray> MetaMethodInspector::parameterNames() const
{
    QList<QByteArray> result;
    foreach (const QByteArray &name, m_metaMethod.parameterNames()) {
        result.append(name);
    }
    return result;
}

bool MetaMethodInspector::hasReturnValue() const
{
    return returnValueTypeId() != QMetaType::Void;
}

int MetaMethodInspector::returnValueTypeId() const
{
    return m_metaMethod.returnType();
}

QString MetaMethodInspector::returnValueTypeName() const
{
    return QString(m_metaMethod.typeName());
}
