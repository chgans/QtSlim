#ifndef INSTRUCTIONFACTORYTESTSUITE_H
#define INSTRUCTIONFACTORYTESTSUITE_H

#include <QObject>

class InstructionFactoryTestSuite : public QObject
{
    Q_OBJECT
public:
    explicit InstructionFactoryTestSuite(QObject *parent = 0);

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testCreateAssignInstruction();
    void testCreateCallInstruction();
    void testCreateCallAndAssignInstruction();
    void testCreateImportInstruction();
    void testCreateMakeInstruction();

};

#endif // INSTRUCTIONFACTORYTESTSUITE_H
