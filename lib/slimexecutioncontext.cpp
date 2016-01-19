#include "slimexecutioncontext.h"

#include <QLoggingCategory>
Q_DECLARE_LOGGING_CATEGORY(context)
Q_LOGGING_CATEGORY(context, "qtslim.execution.context", QtDebugMsg)

SlimExecutionContext::SlimExecutionContext()
{

}

void SlimExecutionContext::setVariable(const QString &name, const QVariant &value)
{
    qCDebug(context) << "Assiging value" << value << "to variable" << name;
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
    qCDebug(context) << "Variable expanded from" << content << "to" << result;
    return result;
}

QVariant SlimExecutionContext::expandVariables(const QVariant &content)
{
    if (content.type() != QVariant::String)
        return content;

    foreach (const QString &key, m_variables.keys()) {
        if (content.value<QString>() == QString("$%1").arg(key)) {
            QVariant result = m_variables.value(key);
            qCDebug(context) << "Variable expanded from" << content << "to" << result;
            return result;
        }
    }

    return content;
}

QList<QVariant> SlimExecutionContext::expandVariables(const QList<QVariant> &contentList)
{
    QList<QVariant> result;
    foreach (const QVariant &content, contentList) {
        result.append(expandVariables(content));
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
    qCDebug(context) << "Assigning object" << object << "to" << name;
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
    //m_libraries.clear();
    //m_variables.clear();
}

QList<QObject *> SlimExecutionContext::libraries() const
{
    return m_libraries.values();
}

