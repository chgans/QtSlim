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

#ifndef LEDASLIMSERVERAPPLICATION_H
#define LEDASLIMSERVERAPPLICATION_H

#include <QCoreApplication>
#include <QHostAddress>

class QTcpServer;
class QTcpSocket;

class SlimApplication : public QCoreApplication
{
    Q_OBJECT
public:
    SlimApplication(int argc, char **argv);

protected:
    void aboutToQuit(QPrivateSignal);

private slots:
    void onServerAcceptError(QAbstractSocket::SocketError socketError);
    void processNewConnection();
    void onSocketError(QAbstractSocket::SocketError error);

private:
    QTcpServer *m_server;
    QTcpSocket *m_clientSocket;
};

#endif // LEDASLIMSERVERAPPLICATION_H
