#include "slimservice.h"

#include "protocol/slimstringreader.h"
#include "protocol/slimdeserialiser.h"
#include "protocol/slimstringwriter.h"
#include "protocol/slimserialiser.h"

#include "instructions/instructionexecutor.h"
#include "instructions/instructionfactory.h"
#include "instructions/resultencoder.h"

#include <QDebug>

class LedaInstructionExecutor: public InstructionExecutor
{
public:
    LedaInstructionExecutor() {}

    // InstructionExecutor interface
public:
    void assign(const QString &name, const QString &value);
    QString callAndAssign(const QString &symbolName, const QString &instanceName, const QString &methodName, const QVariantList &arguments);
    QString call(const QString &instanceName, const QString &methodName, const QVariantList &arguments);
    void import(const QString &path);
    void make(const QString &instanceName, const QString &className, const QVariantList &arguments);
};

void LedaInstructionExecutor::assign(const QString &name, const QString &value)
{
    qDebug() << __FUNCTION__ << name << value;
}

QString LedaInstructionExecutor::callAndAssign(const QString &symbolName, const QString &instanceName, const QString &methodName, const QVariantList &arguments)
{
    qDebug() << __FUNCTION__ << symbolName << instanceName << methodName << arguments;
    return QString();
}

QString LedaInstructionExecutor::call(const QString &instanceName, const QString &methodName, const QVariantList &arguments)
{
    qDebug() << __FUNCTION__ << instanceName << methodName << arguments;
    return QString();
}

void LedaInstructionExecutor::import(const QString &path)
{
    qDebug() << __FUNCTION__ << path;
}

void LedaInstructionExecutor::make(const QString &instanceName, const QString &className, const QVariantList &arguments)
{
    qDebug() << __FUNCTION__ << instanceName << className << arguments;
}

SlimService::SlimService(QIODevice *inputDevice, QIODevice *outputDevice, QObject *parent):
    QObject(parent),
    m_inputDevice(inputDevice),
    m_outputDevice(outputDevice),
    m_reader(new SlimStringReader(inputDevice, this)),
    m_writer(new SlimStringWriter(outputDevice, this)),
    m_executor(new LedaInstructionExecutor())
{
}

SlimService::~SlimService()
{
}

void SlimService::start()
{
    connect(m_reader, &SlimStringReader::stringReceived,
            this, &SlimService::onStringReceived);
    m_writer->sendString("Slim -- V0.4\n");
}

void SlimService::stop()
{
    //m_writer->sendString("Bye");
}

void SlimService::onStringReceived(const QString &string)
{
    QVariantList statements = SlimDeserialiser::deserialise(string).toList();
    QVariantList results;
    foreach (const QVariant &statement, statements) {
        Instruction *instruction = InstructionFactory::createInstruction(statement.toList());
        InstructionResult *result = instruction->execute(m_executor);
        results.append(ResultEncoder::encodeResult(*result));
    }

    QString answer = SlimSerialiser::serialise(QVariant(results));
    m_writer->sendString(answer);
}


