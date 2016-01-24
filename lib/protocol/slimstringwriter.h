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
