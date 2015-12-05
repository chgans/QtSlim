#include "slimservice.h"

#include "protocol/slimstring.h"
#include "protocol/slimstringreader.h"
#include "protocol/slimstringwriter.h"

#include "instructions/instructionexecutor.h"
#include "instructions/instructionfactory.h"

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
    m_writer->sendRawString("Slim -- V0.4");
}

void SlimService::stop()
{
    //m_writer->sendString("Bye");
}

// TODO: We receive an instruction list, we reply with a response list
void SlimService::onStringReceived(const SlimString &string)
{
    if (!string.isList()) {
        qWarning() << "Received a non-list slim string" << string.value();
        return;
    }

    SlimStringList instructionList = string.toList();
    QList<InstructionResult *> results;
    foreach (const SlimString &instructionString, instructionList) {
        QVariantList instructionTokens = extractArgs(instructionString.toList());
        Instruction *instruction = InstructionFactory::createInstruction(instructionTokens);
        InstructionResult *result = instruction->execute(m_executor);
        results.append(result);
    }

    QString answer = encodeResultList(results);
    m_writer->sendString(answer);
}


