#include "metamethodlist.h"

MetaMethodList::MetaMethodList():
    QList<QMetaMethod>()
{

}

MetaMethodList MetaMethodList::filterByName(const QString methodName) const
{
    MetaMethodList result;
    foreach (const QMetaMethod &metaMethod, *this) {
        if (metaMethod.name() == methodName)
            result.append(metaMethod);
    }
    return result;
}

MetaMethodList MetaMethodList::filterByArgumentCount(int count) const
{
    MetaMethodList result;
    foreach (const QMetaMethod &metaMethod, *this) {
        if (metaMethod.parameterCount() == count)
            result.append(metaMethod);
    }
    return result;
}
