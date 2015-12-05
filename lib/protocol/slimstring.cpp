#include "slimstring.h"

 // FIXME: Fully decouple instruction from protocol using QVariant
#include "../instructions/instructionresult.h"

#include <QRegularExpression>
#include <QRegularExpressionMatch>

#include <QDebug>

SlimString::SlimString(const QString &data):
    m_data(data)
{
    parse();
}

SlimString::SlimString(const SlimString &other):
    m_data(other.m_data)
{
    parse();
}

bool SlimString::isValid() const
{
    return m_isValid;
}

QString SlimString::value() const
{
    return m_value;
}

bool SlimString::isList() const
{
    return m_isList;
}

QList<SlimString> SlimString::toList() const
{
    return m_list;
}

void SlimString::parse()
{
    static QRegularExpression stringRegExp("^(\\d{6}):(.*)$");
    static QRegularExpression listRegExp("^\\[(\\d{6}):(.*:)*\\]$");

    m_isValid = false;
    m_isList = false;
    m_value.clear();

    QRegularExpressionMatch stringMatch;
    stringMatch = stringRegExp.match(m_data);
    if (!stringMatch.hasMatch())
        return;

    int length = stringMatch.captured(1).toInt();
    m_value = stringMatch.captured(2);
    if (m_value.length() != length)
        return;

    m_isValid = true;

    QRegularExpressionMatch listMatch;
    listMatch = listRegExp.match(m_value);
    if (!listMatch.hasMatch())
        return;

    int listLength = listMatch.captured(1).toInt();
    QString listData = listMatch.captured(2);
    QList<SlimString> list;
    for (int i = 0; i < listLength; i++) {
        stringMatch = stringRegExp.match(listData);
        if (!stringMatch.hasMatch())
            return;
        int length = stringMatch.captured(1).toInt();
        QString data = listData.left(6 + 1 + length);
        list << SlimString(data);
        listData = listData.mid(6 + 1 + length + 1);
    }
    m_list = list;
    m_isList = true;
}

bool SlimString::tryParse(const QString &input, QString &output, QString &remain)
{
    static QRegularExpression stringRegExp("^(\\d{6}):(.*)$");

    QRegularExpressionMatch stringMatch;
    stringMatch = stringRegExp.match(input);
    if (!stringMatch.hasMatch())
        return false;

    int length = stringMatch.captured(1).toInt();
    QString content = stringMatch.captured(2);
    if (content.length() < length)
        return false;

    output = content.left(length);
    remain = content.mid(length + 1);
    return true;
}

void SlimString::dumpToQDebug() const
{
    int initialDepth = 0;
    dumpSlimString(initialDepth, *this);
}

void SlimString::dumpSlimString(int depth, const SlimString &str)
{
    Q_ASSERT(depth < 100);
    if (!str.isValid()) {
        qDebug() << formatString(depth, "<<<INVALID>>>");
        return;
    }
    if (!str.isList()) {
        qDebug() << formatString(depth, str.value());
        return;
    }
    else {
        qDebug() << formatString(depth, "[");
        foreach (const SlimString &item, str.toList()) {
            dumpSlimString(depth+1, item);
        }
        qDebug() << formatString(depth, "]");
    }
}

QString SlimString::formatString(int depth, const QString &str)
{
    QString prefix;
    for (int i=0; i<depth; i++)
        prefix.append("  ");
    return QString("%1%2").arg(prefix).arg(str);
}


QString encodeLength(int value)
{
    static const int digits = 6;
    static const int base = 10;
    static const QChar fill('0');
    return QString("%1").arg(value, digits, base, fill);
}

QString encodeString(const QString &value)
{
    return QString("%1:%2")
            .arg(encodeLength(value.length()))
            .arg(value);
}

QString encodeList(const QStringList &valueList)
{
    QStringList encodedStrings;
    foreach (const QString &value, valueList) {
        encodedStrings << encodeString(value).append(QChar(':'));
    }
    return QString("[%1:%2]")
               .arg(encodeLength(valueList.length()))
               .arg(encodedStrings.join(QString()));
}

QString encodeResult(const InstructionResult *result)
{
    QStringList resultFields;
    resultFields << result->id()
                 << result->value().toString();
    return encodeList(resultFields);
}

QString encodeResultList(const QList<InstructionResult *> resultList)
{
    QStringList encodedResultList;
    foreach (const InstructionResult *result, resultList) {
        encodedResultList << encodeResult(result);
    }
    return encodeList(encodedResultList);
}

QVariantList extractArgs(const SlimStringList &words, int fromIndex)
{
    QVariantList args;
    if (words.count() <= fromIndex)
        return QVariantList();
    for (int i=fromIndex; i<words.count(); i++) {
        SlimString word = words[i];
        if (!word.isValid()) {
            // FIXME
            continue;
        }
        else if (word.isList()) {
            args.append(extractArgs(word.toList()));
        }
        else
            args.append(word.value());
    }
    return args;
}

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
