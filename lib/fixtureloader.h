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
