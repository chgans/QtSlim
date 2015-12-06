#include "slimstringwriter.h"

#include <QIODevice>
#include <QDebug>

SlimStringWriter::SlimStringWriter(QIODevice *outputDevice, QObject *parent):
    QObject(parent),
    m_device(outputDevice)
{
    connect(m_device, &QIODevice::bytesWritten,
            this, &SlimStringWriter::onBytesWritten);
}

void SlimStringWriter::sendString(const QString &slimString)
{
    m_buffer.append(slimString);
    m_device->write(m_buffer);
}

void SlimStringWriter::onBytesWritten(qint64 bytes)
{
    m_buffer.remove(0, bytes);
    if (!m_buffer.isEmpty())
        m_device->write(m_buffer);
}
