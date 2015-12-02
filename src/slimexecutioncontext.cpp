#include "slimexecutioncontext.h"

SlimExecutionContext::SlimExecutionContext()
{

}

void SlimExecutionContext::setVariable(const QString &name, const QVariant &value)
{
    m_variables[name] = value;
}

QVariant SlimExecutionContext::variable(const QString &name) const
{
    if (m_variables.contains(name))
        return m_variables[name];
    return QVariant();
}

void SlimExecutionContext::addPath(const QString &path)
{
    if (m_paths.contains(path))
        return;
    m_paths.append(path);
}

void SlimExecutionContext::setInstance(const QString &name, QObject *object)
{
    m_instances[name] = object;
}

QObject *SlimExecutionContext::instance(const QString &name) const
{
    if (m_instances.contains(name))
        return m_instances[name];
    return nullptr;
}

