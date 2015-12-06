#include "slimdeserialiser.h"

#include <QRegularExpression>
#include <QRegularExpressionMatch>

static QRegularExpression stringRegExp("^(\\d{6}):(.*)$");
static QRegularExpression listRegExp("^\\[(\\d{6}):(.*)\\]$");
static QRegularExpression listItemRegExp("^(\\d{6}):(.*)");

QVariant SlimDeserialiser::deserialise(const QString &data)
{
    QString stringContent = deserialiseString(data);
    if (stringContent.isNull())
        return QVariant();

    QVariant list = deserialiseList(stringContent);
    if (!list.isNull())
        return list;

    return QVariant(stringContent);
}

SlimDeserialiser::SlimDeserialiser()
{

}

QString SlimDeserialiser::deserialiseString(const QString &data)
{
    QRegularExpressionMatch stringMatch;
    stringMatch = stringRegExp.match(data);
    if (!stringMatch.hasMatch())
        return QString();

    int length = stringMatch.captured(1).toInt();

    QString content;
    content = stringMatch.captured(2);
    if (content.length() != length)
        return QString();

    return content;
}

QVariant SlimDeserialiser::deserialiseList(const QString &data)
{
    QRegularExpressionMatch listMatch;
    listMatch = listRegExp.match(data);
    if (!listMatch.hasMatch())
        return QVariant();

    int listLength = listMatch.captured(1).toInt();

    QString listContent = listMatch.captured(2);
    QList<QVariant> itemContentList;
    for (int index = 0; index < listLength; index++) {
        QString itemContent = removeNextListItem(listContent);
        if (itemContent.isNull())
            return QVariant();
        itemContentList << deserialise(itemContent);
    }
    return QVariant(itemContentList);
}

QString SlimDeserialiser::removeNextListItem(QString &data)
{
    QRegularExpressionMatch itemMatch;
    itemMatch = listItemRegExp.match(data);
    if (!itemMatch.hasMatch())
        return QString();

    int length = itemMatch.captured(1).toInt();

    QString content;
    content = itemMatch.captured(2);
    if (content.length() < (length + 1))
        return QString();

    int colonIndex = length;
    if (content[colonIndex] != QChar(':'))
        return QString();

    QString nextItem = data.left(6 + 1 + length);
    data.remove(0, 6 + 1 + length + 1);

    return nextItem;
}
