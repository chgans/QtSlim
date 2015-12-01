#include "protocol.h"

#include <QRegularExpression>
#include <QRegularExpressionMatch>

QString serialiseLength(int length)
{
    static const int digits = 6;
    static const int base = 10;
    static const QChar fillChar('0');
    return QString("%1").arg(length, digits, base, fillChar);
}

// FIXME: Use specialised converters, See fit/slim and java
QString serialise(const QVariant &value)
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

QString serialiseList(const QVariantList &values)
{
    QStringList serialisedValues;
    foreach (const QVariant &value, values) {
        serialisedValues << serialise(value).append(QChar(':'));
    }
    return QString("[%1:%2]")
            .arg(serialiseLength(serialisedValues.count()))
            .arg(serialisedValues.join(""));
}

QVariant deserialise(const QString &data)
{
    static QRegularExpression regExp("^(\\d{6}):(.*)$");

    QRegularExpressionMatch match;
    match = regExp.match(data);
    if (!match.hasMatch())
        return QVariant();

    int length = match.captured(1).toInt();
    QString representation = match.captured(2);
    if (representation.length() != length)
        return QVariant();

    return QVariant::fromValue<QString>(representation);
}

QVariantList deserialiseList(const QString &data)
{
    static QRegularExpression regExp("^\\[(\\d{6}):(.*:)*\\]$");

    QRegularExpressionMatch match;
    match = regExp.match(data);
    if (!match.hasMatch())
        return QVariantList();

    int length = match.captured(1).toInt();
    QString value = match.captured(2);

    return QVariantList();
}
