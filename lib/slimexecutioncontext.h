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

    void addPath(const QString &path);
    QStringList pathList() const;

    void setInstance(const QString &name, QObject *object);
    QObject *instance(const QString &name) const;

private:
    QMap<QString, QObject *> m_instances;
    // TBD: QList<Library> m_libraries;
    QMap<QString, QVariant> m_variables; // TBD: VariableStore
    QList<QString> m_paths;
};

#endif // SLIMEXECUTIONCONTEXT_H
