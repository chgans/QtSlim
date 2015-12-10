#ifndef METAMETHODLIST_H
#define METAMETHODLIST_H

#include <QList>
#include <QMetaMethod>
#include <QString>

class MetaMethodList: public QList<QMetaMethod>
{
public:
    MetaMethodList();
    MetaMethodList filterByName(const QString methodName) const;
    MetaMethodList filterByArgumentCount(int count) const;
};

#endif // METAMETHODLIST_H
