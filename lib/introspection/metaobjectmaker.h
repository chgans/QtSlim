#ifndef METAOBJECTMAKER_H
#define METAOBJECTMAKER_H

#include <QMetaObject>
#include <QString>
#include <QVariant>
#include <QVariantList>

#include "metaobjectinspector.h"

// TODO: rename to ObjectMaker?
class MetaObjectMaker
{
public:
    MetaObjectMaker(const QMetaObject &metaObject);

    void setParameters(const QVariantList &parameters);

    bool validate();
    bool make();
    QString errorMessage() const;
    QObject *object() const;

private:
    QMetaObject m_metaObject;
    MetaObjectInspector m_metaObjectInspector;
    QVariantList m_arguments;
    QList<QMetaMethod> m_methods;
    QString m_errorMessage;
    QObject *m_object;

    void setErrorMessage(const QString &message);
};

#endif // METAOBJECTMAKER_H
