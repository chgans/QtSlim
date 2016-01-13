#include "slimapplication.h"
#include "slimservice.h"

#include <QTcpServer>
#include <QTcpSocket>

#include <QLoggingCategory>
Q_DECLARE_LOGGING_CATEGORY(app)
Q_LOGGING_CATEGORY(app, "qtslim.application", QtDebugMsg)

// FIXME: enforce arguments => %p %m (port number, class path)
SlimApplication::SlimApplication(int argc, char **argv):
    QCoreApplication(argc, argv),
    m_server(new QTcpServer(this))
{
    m_server->setMaxPendingConnections(100);
    int port = 8888;
    if (arguments().count() == 2)
        port = arguments().at(1).toInt();
    qCDebug(app) << "Listening on port" << port;
    m_server->listen(QHostAddress::Any, port);
    connect(m_server, &QTcpServer::acceptError,
            this, &SlimApplication::onServerAcceptError);
    connect(m_server, &QTcpServer::newConnection,
            this, &SlimApplication::processNewConnection);
}

void SlimApplication::onServerAcceptError(QAbstractSocket::SocketError error)
{
    Q_UNUSED(error);
    qWarning() << "Server error" << m_server->errorString();
    quit();
}

void SlimApplication::processNewConnection()
{
    m_clientSocket = m_server->nextPendingConnection();
    connect(m_clientSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(onSocketError(QAbstractSocket::SocketError)));
    // Create TCpSlimService?
    SlimService *service = new SlimService(m_clientSocket, m_clientSocket, this);
    connect(m_clientSocket, &QTcpSocket::disconnected,
            service, &SlimService::stop);
    service->start();
}

void SlimApplication::onSocketError(QAbstractSocket::SocketError error)
{
    Q_UNUSED(error);
    qWarning() << "Client error" << m_clientSocket->errorString();
    //quit();
}
