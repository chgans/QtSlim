#ifndef FIXTURELOADER_H
#define FIXTURELOADER_H

#include "ifixtureprovider.h"
#include <QStringList>

class QPluginLoader;


// TBD: QPluginLoader::staticPlugins() and  QPluginLoader::staticInstances()
class FixtureLoader
{
public:
    FixtureLoader();

    void setPath(const QString &path);
    void load();

    QList<const QMetaObject *> fixtureMetaObjects() const;

private:
    QStringList m_pathList;
    QList<const QMetaObject *> m_fixtureMetaObjects;
    void addPlugin(QObject *plugin);
};

#endif // FIXTURELOADER_H
