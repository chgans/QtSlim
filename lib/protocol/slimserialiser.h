#ifndef SLIMSERIALISER_H
#define SLIMSERIALISER_H

#include <QVariant>

class SlimSerialiser
{
public:
    static QString serialise(const QVariant &value);

private:
    SlimSerialiser();
    static QString serialiseLength(int length);
    static QString serialiseString(const QVariant &value);
    static QString serialiseList(const QVariantList &values);
};

#endif // SLIMSERIALISER_H
