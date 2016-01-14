#include "slimservice.h"

#include "protocol/slimstringreader.h"
#include "protocol/slimdeserialiser.h"
#include "protocol/slimstringwriter.h"
#include "protocol/slimserialiser.h"

#include "instructions/instructionexecutor.h"
#include "instructions/instructionfactory.h"
#include "instructions/resultencoder.h"

#include "execution/metaobjectexecutor.h"

#include "fixtureloader.h"
#include "slimexecutioncontext.h"

#include <QDebug>

SlimService::SlimService(QIODevice *inputDevice, QIODevice *outputDevice, QObject *parent):
    QObject(parent),
    m_inputDevice(inputDevice),
    m_outputDevice(outputDevice),
    m_reader(new SlimStringReader(inputDevice, this)),
    m_writer(new SlimStringWriter(outputDevice, this)),
    m_executor(new MetaObjectExecutor),
    m_fixtureLoader(new FixtureLoader),
    m_executionContext(new SlimExecutionContext)
{
    m_executor->setExecutionContext(m_executionContext);
}

SlimService::~SlimService()
{
    delete m_executionContext;
    delete m_fixtureLoader;
    delete m_executor;
}

void SlimService::start()
{
    m_fixtureLoader->load();
    m_executor->addMetaObjects(m_fixtureLoader->fixtureMetaObjects());

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
    //qDebug() << "Request:" << string;
    QVariantList statements = SlimDeserialiser::deserialise(string).toList();
    QVariantList results;
    foreach (const QVariant &statement, statements) {
        //qDebug() << "Executing statement:" << statement;
        Instruction *instruction = InstructionFactory::createInstruction(statement.toList());
        InstructionResult *result = instruction->execute(m_executor);
        //qDebug() << "Execution result:" << result->result();
        results.append(ResultEncoder::encodeResult(*result));
        //qDebug() << "Execution result:" << ResultEncoder::encodeResult(*result);
    }

    QString answer = SlimSerialiser::serialise(QVariant(results));
    //qDebug() << "Answer:" << answer;
    m_writer->sendString(answer);
}


