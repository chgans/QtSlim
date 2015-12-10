#ifndef INSTRUCTIONRESULTTESTSUITE_H
#define INSTRUCTIONRESULTTESTSUITE_H

#include <QObject>

class InstructionResultTestSuite : public QObject
{
    Q_OBJECT
public:
    explicit InstructionResultTestSuite(QObject *parent = 0);

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testInstructionResultWithValue();
    void testInstructionResultWithoutValue();
    void testOkInstructionResult();
    void testErrorInstructionResult();
    void testVoidInstructionResult();
};

#endif // INSTRUCTIONRESULTTESTSUITE_H
