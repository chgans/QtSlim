#ifndef SLIMSTRINGWRITER_H
#define SLIMSTRINGWRITER_H

#include <QObject>

class QIODevice;
class SlimString;

class SlimStringWriter : public QObject
{
    Q_OBJECT
public:
    explicit SlimStringWriter(QIODevice *outputDevice, QObject *parent = 0);

signals:
    void stringWritten();

public slots:
    void sendString(const QString &slimString);

private slots:
    void onBytesWritten(qint64 bytes);

private:
    QIODevice *m_device;
    QByteArray m_buffer;
};

#endif // SLIMSTRINGWRITER_H
