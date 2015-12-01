#ifndef PROTOCOLDESERIALISATION_H
#define PROTOCOLDESERIALISATION_H

#include <QObject>

class ProtocolDeserialisationTestSuite : public QObject
{
    Q_OBJECT

public:
    ProtocolDeserialisationTestSuite();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testCanDeserialiseString_data();
    void testCanDeserialiseString();
    void testCanDeserialiseInteger_data();
    void testCanDeserialiseInteger();
    void testCanDeserialiseFloat_data();
    void testCanDeserialiseFloat();
    void testCanDeserialiseBoolean_data();
    void testCanDeserialiseBoolean();
    void testCanDeserialiseStringList_data();
    void testCanDeserialiseStringList();
};

#endif // PROTOCOLDESERIALISATION_H
