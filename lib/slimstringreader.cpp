#include "slimstringreader.h"
#include <QIODevice>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QTimer>

#include <QDebug>

SlimStringReader::SlimStringReader(QIODevice *inputDevice, QObject *parent):
    QObject(parent),
    m_device(inputDevice)
{
    connect(m_device, &QIODevice::readyRead,
            this, &SlimStringReader::onReadyRead);
    QTimer *initTimer = new QTimer(this);
    connect(initTimer, &QTimer::timeout,
            this, &SlimStringReader::onReadyRead);
    initTimer->setSingleShot(true);
    initTimer->start(0);
}


bool SlimStringReader::tryParse(const QString &input, QString &output, QString &remain)
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

bool SlimStringReader::tryParseList(const QString &input, QStringList &output)
{
    return false;
}

void SlimStringReader::onReadyRead()
{
    QByteArray data = m_device->readAll();
    m_buffer.append(data);
    SlimString token(m_buffer);
    if (!token.isValid()) {
        qWarning() << "Received invalid slim data" << data;
        return;
    }
    qDebug() << "< " << m_buffer;
    emit stringReceived(token);
    m_buffer.clear();

#if 0
    m_buffer.append(received);
    QString string;
    QString remain;
    bool gotString = tryParse(m_buffer, string, remain);
    if (!gotString) {
        m_buffer.clear();
        return;
    }
    m_buffer = remain;

    QStringList list;
    bool gotList = tryParseList(string, list);
    if (!gotList)
        emit stringReceived(string);
    else
        emit stringListReceived(list);
#endif
}
