#include <QtTest>
#include <QCoreApplication>

#include "protocolserialisation.h"
#include "protocoldeserialisation.h"
#include "instructiontestsuite.h"
#include "instructionresulttestsuite.h"
#include "instructionfactorytestsuite.h"
#include "resultencodertestsuite.h"
#include "metamethodlisttestsuite.h"
#include "metamethodinspectortestsuite.h"
#include "metamethodinvokertestsuite.h"
#include "metaobjectinspectortestsuite.h"
#include "metaobjectmakertestsuite.h"

int main(int argc, char** argv) {
    QCoreApplication app(argc, argv);
    Q_UNUSED(app);

    return QTest::qExec(new ProtocolSerialisationTestSuite(&app), argc, argv) |
            QTest::qExec(new ProtocolDeserialisationTestSuite(&app), argc, argv) |
            QTest::qExec(new InstructionTestSuite(&app), argc, argv) |
            QTest::qExec(new InstructionResultTestSuite(&app), argc, argv) |
            QTest::qExec(new InstructionFactoryTestSuite(&app), argc, argv) |
            QTest::qExec(new ResultEncoderTestSuite(&app), argc, argv) |
            QTest::qExec(new MetaObjectInspectorTestSuite(&app), argc, argv) |
            QTest::qExec(new MetaMethodListTestSuite(&app), argc, argv) |
            QTest::qExec(new MetaMethodInspectorTestSuite(&app), argc, argv) |
            QTest::qExec(new MetaMethodInvokerTestSuite(&app), argc, argv) |
            QTest::qExec(new MetaObjectMakerTestSuite(&app), argc, argv);
}
