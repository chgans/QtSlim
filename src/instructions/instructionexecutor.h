#ifndef INSTRUCTIONEXECUTOR_H
#define INSTRUCTIONEXECUTOR_H

#include <QString>
#include <QVariantList>

// TODO: make it return InstructionResult
class InstructionExecutor
{
public:
    InstructionExecutor();

    virtual void assign(const QString &name, const QString &value) = 0;
    virtual QString callAndAssign(const QString &symbolName, const QString &instanceName,
                                  const QString &methodName, const QVariantList &arguments) = 0;
    virtual QString call(const QString &instanceName, const QString &methodName,
                         const QVariantList &arguments) = 0;
    virtual void import(const QString &path) = 0;

    // TODO: return bool + set last error
    virtual void make(const QString &instanceName, const QString &className,
                      const QVariantList &arguments) = 0;

    QString lastErrorString() const;

protected:
    void setErrorString(const QString &error);
    void clearErrorString();

private:
    QString m_errorString;
};

#endif // INSTRUCTIONEXECUTOR_H
