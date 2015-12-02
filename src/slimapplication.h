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
