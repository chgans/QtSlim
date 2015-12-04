#include "slimstringwriter.h"
#include "slimstring.h"

#include <QIODevice>
#include <QDebug>

SlimStringWriter::SlimStringWriter(QIODevice *outputDevice, QObject *parent):
    QObject(parent),
    m_device(outputDevice)
{
    connect(m_device, &QIODevice::bytesWritten,
            this, &SlimStringWriter::onBytesWritten);
}

void SlimStringWriter::sendString(const QString &string)
{
    QString packet = QString("%1:%2").arg(string.length(), 6, 10, QChar('0')).arg(string);
    qDebug() << "> " << packet;
    m_buffer.append(packet.toUtf8());
    m_device->write(m_buffer);
}



void SlimStringWriter::sendSlimString(const SlimString &string)
{
}

void SlimStringWriter::sendRawString(const QString &string)
{
    m_buffer.append(QString("%1\n").arg(string).toUtf8());
    m_device->write(m_buffer);
}

void SlimStringWriter::sendList(const QStringList &list)
{
    QStringList encodedStrings;
    foreach (const QString &str, list) {
        encodedStrings << QString("%1:%2:").arg(str.length(), 6, 10, QChar('0'));
    }
    sendString(QString("%1:[%2]")
               .arg(encodedStrings.length(), 6, 10, QChar('0'))
               .arg(encodedStrings.join(QString())));
}

void SlimStringWriter::onBytesWritten(qint64 bytes)
{
    m_buffer.remove(0, bytes);
    if (!m_buffer.isEmpty())
        m_device->write(m_buffer);
}

