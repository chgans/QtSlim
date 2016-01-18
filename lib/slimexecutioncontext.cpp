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

QString SlimExecutionContext::expandVariables(const QString &content)
{
    QString result = content;
    foreach (const QString &key, m_variables.keys()) {
        result.replace(QString("$%1").arg(key), m_variables.value(key).toString());
    }
    return result;
}

void SlimExecutionContext::addPath(const QString &path)
{
    if (m_paths.contains(path))
        return;
    m_paths.append(path);
}

QStringList SlimExecutionContext::pathList() const
{
    return m_paths;
}

void SlimExecutionContext::setInstance(const QString &name, QObject *object)
{
    if (name.startsWith("library"))
        m_libraries[name] = object;
    else
        m_instances[name] = object;
}

QObject *SlimExecutionContext::instance(const QString &name) const
{
    if (m_instances.contains(name))
        return m_instances[name];
    if (m_libraries.contains(name))
        return m_libraries[name];
    return nullptr;
}

// FIXME: delete objects
// Keep path and libraries
void SlimExecutionContext::reset()
{
    m_instances.clear();
    //m_variables.clear();
}

