#ifndef INSTRUCTIONEXECUTOR_H
#define INSTRUCTIONEXECUTOR_H

#include <QString>
#include <QVariant>
#include <QVariantList>

class InstructionExecutor
{
public:
    InstructionExecutor();

    virtual bool assign(const QString &name, const QString &value) = 0;
    virtual bool callAndAssign(const QString &symbolName, const QString &instanceName,
                                  const QString &methodName, const QVariantList &arguments) = 0;
    virtual bool call(const QString &instanceName, const QString &methodName,
                         const QVariantList &arguments) = 0;
    virtual bool import(const QString &path) = 0;

    virtual bool make(const QString &instanceName, const QString &className,
                      const QVariantList &arguments) = 0;

    QVariant result() const;
    QString errorString() const;

protected:
    void setError(const QString &error);
    void clearErrorString();
    void setResult(const QVariant &result);
    void clearResult();

private:
    QVariant m_result;
    QString m_errorString;
};

#endif // INSTRUCTIONEXECUTOR_H
