#ifndef INSTRUCTIONRESULT_H
#define INSTRUCTIONRESULT_H

#include <QString>
#include <QVariant>

class InstructionResult
{
public:
    InstructionResult(const QString &id, const QVariant &value = QVariant());

    QString id() const;
    QVariant value() const;

    virtual bool hasValue() const = 0;
    virtual bool hasError() const = 0;

private:
    QString m_id;
    QVariant m_value;
};

#endif // INSTRUCTIONRESULT_H
