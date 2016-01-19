#ifndef SLIMEXECUTIONCONTEXT_H
#define SLIMEXECUTIONCONTEXT_H

#include <QMap>
#include <QString>
#include <QObject>
#include <QVariant>

class SlimExecutionContext
{
public:
    SlimExecutionContext();

    void setVariable(const QString &name, const QVariant &value);
    QVariant variable(const QString &name) const;
    QString expandVariables(const QString &content);
    QVariant expandVariables(const QVariant &content);
    QList<QVariant> expandVariables(const QList<QVariant> &content);

    void addPath(const QString &path);
    QStringList pathList() const;

    void setInstance(const QString &name, QObject *object);
    QObject *instance(const QString &name) const;

    void reset();

    QList<QObject *> libraries() const;

private:
    QMap<QString, QObject *> m_instances;
    QMap<QString, QObject *> m_libraries;
    QMap<QString, QVariant> m_variables; // TBD: VariableStore
    QList<QString> m_paths;
};

#endif // SLIMEXECUTIONCONTEXT_H
