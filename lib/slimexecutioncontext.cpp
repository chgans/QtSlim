#include "slimexecutioncontext.h"

#include <QLoggingCategory>
Q_DECLARE_LOGGING_CATEGORY(context)
Q_LOGGING_CATEGORY(context, "qtslim.execution.context")

SlimExecutionContext::SlimExecutionContext()
{

}

void SlimExecutionContext::setVariable(const QString &name, const QVariant &value)
{
    qCDebug(context) << "Adding" << value << "to symbol dictionary as" << name;
    m_variables[name] = value;
}

QVariant SlimExecutionContext::variable(const QString &name) const
{
    QVariant result;
    if (m_variables.contains(name)) {
        result = m_variables[name];
        qCDebug(context) << "Found" << name << "in symbol dictionary:";
    }
    else {
        qCDebug(context) << "Could not find" << name << "in symbol dictionary";
    }
    return result;
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
    if (name.startsWith("library")) {
        qCDebug(context) << "Adding" << object << "to library dictionary as" << name;
        m_libraries[name] = object;
    }
    else {
        qCDebug(context) << "Adding" << object << "to object dictionary as" << name;
        m_instances[name] = object;
    }
}

QObject *SlimExecutionContext::instance(const QString &name) const
{
    QObject *result = nullptr;
    if (m_instances.contains(name)) {
        result = m_instances[name];
        qCDebug(context) << "Found" << name << "in object dictionary:" << result;
    }
    else if (m_libraries.contains(name)) {
        result = m_libraries[name];
        qCDebug(context) << "Found" << name << "in libraries dictionary:" << result;
    }
    else {
        qCDebug(context) << "Could not find" << name << "in any dictionaries";
    }

    return result;
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

