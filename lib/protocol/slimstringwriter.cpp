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
