#include "slimstring.h"

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
