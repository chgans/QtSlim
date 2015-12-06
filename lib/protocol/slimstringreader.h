#ifndef SLIMSTRINGREADER_H
#define SLIMSTRINGREADER_H

#include <QObject>

class QIODevice;

class SlimStringReader : public QObject
{
    Q_OBJECT
public:
    explicit SlimStringReader(QIODevice *inputDevice, QObject *parent = 0);

signals:
    void stringReceived(const QString &string);

private slots:
    void onReadyRead();

private:
    static bool tryParse(const QString &input, QString &output, QString &remain);

    QIODevice *m_device;
    QString m_buffer;
};

#endif // SLIMSTRINGREADER_H
