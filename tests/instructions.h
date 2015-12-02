#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <QObject>

class instructions : public QObject
{
    Q_OBJECT
public:
    explicit instructions(QObject *parent = 0);

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testAssignInstruction();
    void testCallAndAssignInstruction();
    void testCallInstruction();
    void testImportInstruction();
    void testMakeInstruction();

};

#endif // INSTRUCTIONS_H
