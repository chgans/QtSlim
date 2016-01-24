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
