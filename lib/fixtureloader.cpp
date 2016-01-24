/****************************************************************************
**
** Copyright (C) 2016 Christian Gagneraud <chgans@gna.org>
** All rights reserved.
**
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 3 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL3 included in the packaging of this file.
** Please review the following information to ensure the GNU Lesser General
** Public License version 3 requirements will be met:
** https://www.gnu.org/licenses/lgpl-3.0.html.
**
****************************************************************************/

#include "fixtureloader.h"

#include <QCoreApplication>
#include <QPluginLoader>
#include <QDir>

#include <QLoggingCategory>
Q_DECLARE_LOGGING_CATEGORY(loader)
Q_LOGGING_CATEGORY(loader, "qtslim.fixture.loader")

FixtureLoader::FixtureLoader()
{

}

void FixtureLoader::setPath(const QString &path)
{
    m_pathList = path.split(QChar(':'));
}

void FixtureLoader::load()
{
    qCDebug(loader) << "Loading static fixture providers...";
    foreach (QObject *plugin, QPluginLoader::staticInstances())
        addPlugin(plugin);

    qCDebug(loader) << "Loading dynamic fixture providers...";
    QDir fixturesDir = QDir(qApp->applicationDirPath());
    fixturesDir.setNameFilters(QStringList() << QString("*.so"));
    fixturesDir.setFilter(QDir::Files|QDir::Readable|QDir::Executable);
    fixturesDir.setSorting(QDir::Name|QDir::IgnoreCase);
    fixturesDir.cd("../fitnesse/fixtures"); // FIXME
    foreach (QString fileName, fixturesDir.entryList()) {
        qCDebug(loader) << "Adding fixtures from " << fileName;
        QPluginLoader pluginLoader(fixturesDir.absoluteFilePath(fileName));
        QObject *plugin = pluginLoader.instance();
        if (plugin == nullptr)
            qCWarning(loader) << pluginLoader.errorString();
        else
            addPlugin(plugin);
    }
}

QList<const QMetaObject *> FixtureLoader::fixtureMetaObjects() const
{
    return m_fixtureMetaObjects;
}

void FixtureLoader::addPlugin(QObject *plugin)
{
    IFixtureProvider *fixtureProvider = qobject_cast<IFixtureProvider *>(plugin);
    if (fixtureProvider == nullptr) {
        qCWarning(loader) << "Not a QtSlim fixture provider:" << plugin;
        return;
    }
    m_fixtureMetaObjects.append(fixtureProvider->fixtureMetaObjects());
}
