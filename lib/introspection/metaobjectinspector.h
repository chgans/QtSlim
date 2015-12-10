#ifndef METAOBJECTINSPECTOR_H
#define METAOBJECTINSPECTOR_H

#include "metamethodlist.h"
#include <QMetaObject>

// TBD: Hide Qt internale stuff like _q_reregisterTimers(void*)?
class MetaObjectInspector
{
public:
    MetaObjectInspector(const QMetaObject &metaObject);

    MetaMethodList constructors() const;
    MetaMethodList allMethods() const;
    MetaMethodList functionMethods() const;
    MetaMethodList signalMethods() const;
    MetaMethodList slotMethods() const;

private:
    const QMetaObject &m_metaObject;
};


#endif // METAOBJECTINSPECTOR_H
