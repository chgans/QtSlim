#ifndef SLIMSTRING_H
#define SLIMSTRING_H

#include <QString>
#include <QStringList>

class SlimString
{
public:
    SlimString(const QString &data);
    SlimString(const SlimString &other);

    bool isValid() const;
    QString value() const;

    bool isList() const;
    QList<SlimString> toList() const;

    void dumpToQDebug() const;

private:
    void parse();
    QString m_data;
    QString m_value;
    QList<SlimString> m_list;
    bool m_isValid = false;
    bool m_isList = false;

    static bool tryParse(const QString &input, QString &output, QString &remain);
    static QString formatString(int depth, const QString &str);
    static void dumpSlimString(int depth, const SlimString &str);

};

typedef QList<SlimString> SlimStringList;

#endif // SLIMSTRING_H
