#ifndef INSTRUCTIONRESULT_H
#define INSTRUCTIONRESULT_H

#include <QString>
#include <QVariant>


// TBD:
// - Do we need two InstructionResult classes? One for Application error and one
//   for SLim error (exception?)
// - Should we keep InstructionResult abstract and add a ValueInstructionResult (re Void InstructionResult)

class InstructionResult
{
public:
    InstructionResult(const QString &id, const QVariant &result = QVariant());

    QString id() const;
    QVariant result() const;

    virtual bool hasResult() const;
    virtual bool hasError() const;

private:
    QString m_id;
    QVariant m_value;
};

#endif // INSTRUCTIONRESULT_H
