#include <QtTest>
#include <QCoreApplication>

#include "protocolserialisation.h"
#include "protocoldeserialisation.h"
#include "instructions.h"
#include "instructionfactorytestsuite.h"

int main(int argc, char** argv) {
    QCoreApplication app(argc, argv);
    Q_UNUSED(app);

    return QTest::qExec(new ProtocolSerialisationTestSuite, argc, argv) |
            QTest::qExec(new ProtocolDeserialisationTestSuite, argc, argv) |
            QTest::qExec(new InstructionTestSuite, argc, argv) |
            QTest::qExec(new InstructionFactoryTestSuite, argc, argv);
}
