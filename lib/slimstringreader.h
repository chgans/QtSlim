#ifndef SLIMSTRINGREADER_H
#define SLIMSTRINGREADER_H

#include <QObject>
#include "slimstring.h"

class QIODevice;

class SlimStringReader : public QObject
{
    Q_OBJECT
public:
    explicit SlimStringReader(QIODevice *inputDevice, QObject *parent = 0);

signals:
    void stringReceived(const SlimString &string);
    void stringListReceived(const QStringList &list);

private slots:
    void onReadyRead();

private:
    static bool tryParse(const QString &input, QString &output, QString &remain);
    static bool tryParseList(const QString &input, QStringList &output);

    QIODevice *m_device;
    QString m_buffer;
};

#endif // SLIMSTRINGREADER_H
