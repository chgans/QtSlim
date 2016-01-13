#include "fixtureloader.h"

#include <QPluginLoader>

#include <QLoggingCategory>
Q_DECLARE_LOGGING_CATEGORY(loader)
Q_LOGGING_CATEGORY(loader, "qtslim.plugin.fixtureloader", QtWarningMsg)

FixtureLoader::FixtureLoader()
{

}

IFixtureProvider *FixtureLoader::load(const QString filename)
{
    QPluginLoader pluginLoader(filename);

    qCDebug(loader) << "Loading" << filename;

    if (!pluginLoader.load()) {
        setErrorString(pluginLoader.errorString());
        return nullptr;
    }

    IFixtureProvider *fixtureProvider = qobject_cast<IFixtureProvider *>(pluginLoader.instance());
    if (fixtureProvider == nullptr) {
        setErrorString(QString("%1: Not a QtSlim fixture provider").arg(filename));
        return nullptr;
    }

    m_errorString.clear();
    return fixtureProvider;
}

bool FixtureLoader::hasError() const
{
    return !m_errorString.isNull();
}

QString FixtureLoader::errorString() const
{
    return m_errorString;
}

void FixtureLoader::setErrorString(const QString &message)
{
    m_errorString = message;
    qCWarning(loader) << m_errorString;
}
