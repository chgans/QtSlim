#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <QString>
#include <QStringList>
#include <QVariant>
#include <QVariantList>

QString serialise(const QVariant &value);
QString serialiseList(const QVariantList &values);
QVariant deserialise(const QString &data);
QVariantList deserialiseList(const QString &data);

#endif // PROTOCOL_H
