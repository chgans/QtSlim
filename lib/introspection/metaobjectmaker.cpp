#include "metaobjectmaker.h"


MetaObjectMaker::MetaObjectMaker(const QMetaObject &metaObject):
    m_metaObject(metaObject), m_metaObjectInspector(metaObject)
{

}

void MetaObjectMaker::setParameters(const QVariantList &parameters)
{
    Q_UNUSED(parameters);
}

bool MetaObjectMaker::validate()
{
    return false;
}

bool MetaObjectMaker::make()
{
    return false;
}

QString MetaObjectMaker::errorMessage() const
{
    return QString("Not implemented");
}

QObject *MetaObjectMaker::object() const
{
    return nullptr;
}

void MetaObjectMaker::setErrorMessage(const QString &message)
{
    Q_UNUSED(message);
}
