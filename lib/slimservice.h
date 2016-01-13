#ifndef SLIMSERVICE_H
#define SLIMSERVICE_H

#include <QObject>

class QIODevice;
class SlimStringReader;
class SlimStringWriter;
class MetaObjectExecutor;
class SlimString;
class FixtureLoader;

class SlimService : public QObject
{
    Q_OBJECT

public:
    SlimService(QIODevice *inputDevice, QIODevice *outputDevice, QObject *parent = nullptr);
    ~SlimService();

public slots:
    void start();
    void stop();

private slots:
    void onStringReceived(const QString &string);

private:
    QIODevice *m_inputDevice = nullptr;
    QIODevice *m_outputDevice = nullptr;
    SlimStringReader *m_reader;
    SlimStringWriter *m_writer;
    MetaObjectExecutor *m_executor;
    FixtureLoader *m_fixtureLoader;
};

#endif // SLIMSERVICE_H
