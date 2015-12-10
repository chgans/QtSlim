#ifndef METAMETHODINVOKER_H
#define METAMETHODINVOKER_H

#include <QMetaMethod>
#include "metamethodinspector.h"

// TODO: rename to MethodInvoker?
class MetaMethodInvoker
{
public:
    MetaMethodInvoker(const QMetaMethod &metaMethod);

    void setObject(QObject *object);
    void setParameters(const QVariantList &parameters);

    bool validate();
    bool invoke();

    bool hasResult() const;
    QVariant result() const;

    bool hasError() const;
    QString errorMessage() const;

private:
    const QMetaMethod &m_method;
    MetaMethodInspector m_inspector;

    Qt::ConnectionType m_connectionType;
    QObject *m_object;

    QVariant m_returnValueStorage;
    QVariantList m_parametersStorage;
    QGenericReturnArgument m_returnValue;
    QList<QGenericArgument> m_parameters;
    void invokeWithoutReturn();
    void invokeWithReturn();

    QString m_errorMessage;
    void setError(const QString &message);
    void clearError();
};


#endif // METAMETHODINVOKER_H
