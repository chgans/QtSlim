#ifndef PROTOCOLSERIALISATION_H
#define PROTOCOLSERIALISATION_H

#include <QObject>

class ProtocolSerialisationTestSuite : public QObject
{
    Q_OBJECT

public:
    ProtocolSerialisationTestSuite(QObject *parent = 0);

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testCanSerialiseString_data();
    void testCanSerialiseString();
    void testCanSerialiseInteger_data();
    void testCanSerialiseInteger();
    void testCanSerialiseFloat_data();
    void testCanSerialiseFloat();
    void testCanSerialiseBoolean_data();
    void testCanSerialiseBoolean();
    void testCanSerialiseStringList_data();
    void testCanSerialiseStringList();
};

#endif // PROTOCOLSERIALISATION_H
