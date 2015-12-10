#ifndef METAMETHODINSPECTOR_H
#define METAMETHODINSPECTOR_H

#include <QMetaMethod>
#include <QList>
#include <QByteArray>

class MetaMethodInspector
{
public:
    MetaMethodInspector(const QMetaMethod &metaMethod);

    int parameterCount() const;
    QList<int> parameterTypeIds() const;
    QList<QByteArray> parameterTypeNames() const;
    QList<QByteArray> parameterNames() const;

    bool hasReturnValue() const;
    int returnValueTypeId() const;
    QString returnValueTypeName() const;

private:
    const QMetaMethod &m_metaMethod;
};

#endif // METAMETHODINSPECTOR_H
