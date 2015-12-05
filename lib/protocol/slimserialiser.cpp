#include "slimserialiser.h"

QString SlimSerialiser::serialise(const QVariant &value)
{
    return serialiseString(value);
}

SlimSerialiser::SlimSerialiser()
{

}

QString SlimSerialiser::serialiseLength(int length)
{
    static const int digits = 6;
    static const int base = 10;
    static const QChar fillChar('0');
    return QString("%1").arg(length, digits, base, fillChar);
}

QString SlimSerialiser::serialiseString(const QVariant &value)
{
    QString representation;
    if (value.type() == QVariant::List)
        representation = serialiseList(value.toList());
    else if (value.type() == QVariant::Double) {
        static const int precision = 7;
        static const char format = 'g';
        static const int fieldWidth = 0;
        representation = QString("%1").arg(value.toDouble(),
                                           fieldWidth,
                                           format,
                                           precision);
    }
    else
        representation = value.toString();
    return QString("%1:%2")
            .arg(serialiseLength(representation.count()))
            .arg(representation);
}

QString SlimSerialiser::serialiseList(const QVariantList &values)
{
    QStringList serialisedValues;
    foreach (const QVariant &value, values) {
        serialisedValues << serialise(value).append(QChar(':'));
    }
    return QString("[%1:%2]")
            .arg(serialiseLength(serialisedValues.count()))
            .arg(serialisedValues.join(""));
}

