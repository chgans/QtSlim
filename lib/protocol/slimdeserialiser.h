#ifndef SLIMDESERIALISER_H
#define SLIMDESERIALISER_H

#include <QVariant>

class SlimDeserialiser
{
public:
    static QVariant deserialise(const QString &data);

private:
    SlimDeserialiser();
    static QString deserialiseString(const QString &data);
    static QVariant deserialiseList(const QString &data);
    static QString removeNextListItem(QString &data);
};

#endif // SLIMDESERIALISER_H
