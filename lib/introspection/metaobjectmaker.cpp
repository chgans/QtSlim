#include "metaobjectmaker.h"
#include "metamethodinvoker.h"


MetaObjectMaker::MetaObjectMaker(const QMetaObject &metaObject):
    m_metaObject(metaObject), m_metaObjectInspector(metaObject),
    m_object(nullptr)
{

}

void MetaObjectMaker::setParameters(const QVariantList &parameters)
{
    m_arguments = parameters;
}

bool MetaObjectMaker::validate()
{
    return true;
}

bool MetaObjectMaker::make()
{
    m_object = nullptr;
    MetaMethodList ctors = m_metaObjectInspector.constructors().filterByArgumentCount(m_arguments.count());
    foreach (const QMetaMethod &method, ctors) {
        MetaMethodInvoker invoker(method);
        invoker.setParameters(m_arguments);
        if (!invoker.validate()) {
            continue;
        }
        if (!invoker.invoke()) {
            continue;
        }
        m_object = invoker.result().value<QObject*>();
        return true;
    }
    setErrorMessage("Coudn't find compatible constructors");
    return false;
}

QString MetaObjectMaker::errorMessage() const
{
    return m_errorMessage;
}

QObject *MetaObjectMaker::object() const
{
    return m_object;
}

void MetaObjectMaker::setErrorMessage(const QString &message)
{
    m_errorMessage = message;
}
