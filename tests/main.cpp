#include <QtTest>
#include <QCoreApplication>

#include "protocolserialisation.h"
#include "protocoldeserialisation.h"

int main(int argc, char** argv) {
    QCoreApplication app(argc, argv);
    Q_UNUSED(app);

    ProtocolSerialisationTestSuite testSuite1;
    ProtocolDeserialisationTestSuite testSuite2;

    return QTest::qExec(&testSuite1, argc, argv) |
           QTest::qExec(&testSuite2, argc, argv);
}
