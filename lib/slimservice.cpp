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
#include "slimlibraryhelper.h"


#include <QLoggingCategory>
Q_DECLARE_LOGGING_CATEGORY(service)
Q_LOGGING_CATEGORY(service, "qtslim.server.service")

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
    SlimLibraryHelper *helper = new SlimLibraryHelper(this);
    helper->setExecutionContext(m_executionContext);
    m_executionContext->setInstance("librarySlimHelperLibrary", helper);
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
    qCDebug(service) << "Starting service ...";
    m_fixtureLoader->load();
    m_executor->addMetaObjects(m_fixtureLoader->fixtureMetaObjects());

    connect(m_reader, &SlimStringReader::stringReceived,
            this, &SlimService::onStringReceived);
    m_writer->sendString("Slim -- V0.4\n");
}

void SlimService::stop()
{
    m_writer->sendString("");
    qCDebug(service) << "Service stopped";
}

void SlimService::onStringReceived(const QString &string)
{
    qCDebug(service) << "Processing statement ...";
    if (string == "000003:bye") { // FIXME
        qCDebug(service) << "Bye!";
        return;
    }
    m_executionContext->reset();
    QVariantList statements = SlimDeserialiser::deserialise(string).toList();
    QVariantList results;
    foreach (const QVariant &statement, statements) {
        Instruction *instruction = InstructionFactory::createInstruction(statement.toList());
        qCDebug(service) << "Executing instruction:" << instruction->toString();
        InstructionResult *result = instruction->execute(m_executor);
        results.append(ResultEncoder::encodeResult(*result));
        qCDebug(service) << "Execution result:" << ResultEncoder::encodeResult(*result);
    }

    QString answer = SlimSerialiser::serialise(QVariant(results));
    qCDebug(service) << "Processing result:" << answer;
    m_writer->sendString(answer);
    qCDebug(service) << "Statement processing finished";
}


