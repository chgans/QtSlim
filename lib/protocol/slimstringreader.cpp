/****************************************************************************
**
** Copyright (C) 2016 Christian Gagneraud <chgans@gna.org>
** All rights reserved.
**
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 3 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL3 included in the packaging of this file.
** Please review the following information to ensure the GNU Lesser General
** Public License version 3 requirements will be met:
** https://www.gnu.org/licenses/lgpl-3.0.html.
**
****************************************************************************/

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

    output = input.left(6 + 1 + length);
    remain = content.mid(length + 1);
    return true;
}

void SlimStringReader::onReadyRead()
{
    m_buffer.append(m_device->readAll());
    QString string;
    QString remain;
    bool gotString = tryParse(m_buffer, string, remain);
    if (gotString) {
        emit stringReceived(string);
        m_buffer = remain;
    }
}
