#include "metaobjectinspector.h"

MetaObjectInspector::MetaObjectInspector(const QMetaObject &metaObject):
    m_metaObject(metaObject)
{
}

MetaMethodList MetaObjectInspector::constructors() const
{
    MetaMethodList result;
    for (int index=0; index<m_metaObject.constructorCount(); index++) {
        result << m_metaObject.constructor(index);
    }
    return result;
}

MetaMethodList MetaObjectInspector::allMethods() const
{
    MetaMethodList result;
    for (int index=0; index<m_metaObject.methodCount(); index++) {
        result << m_metaObject.method(index);
    }
    return result;
}

MetaMethodList MetaObjectInspector::functionMethods() const
{
    MetaMethodList result;
    for (int index=0; index<m_metaObject.methodCount(); index++) {
        QMetaMethod metaMethod = m_metaObject.method(index);
        if (metaMethod.methodType() == QMetaMethod::Method)
            result << m_metaObject.method(index);
    }
    return result;
}

MetaMethodList MetaObjectInspector::signalMethods() const
{
    MetaMethodList result;
    for (int index=0; index<m_metaObject.methodCount(); index++) {
        QMetaMethod metaMethod = m_metaObject.method(index);
        if (metaMethod.methodType() == QMetaMethod::Signal)
            result << m_metaObject.method(index);
    }
    return result;
}

MetaMethodList MetaObjectInspector::slotMethods() const
{
    MetaMethodList result;
    for (int index=0; index<m_metaObject.methodCount(); index++) {
        QMetaMethod metaMethod = m_metaObject.method(index);
        if (metaMethod.methodType() == QMetaMethod::Slot)
            result << m_metaObject.method(index);
    }
    return result;
}
