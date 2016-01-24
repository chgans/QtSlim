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

#ifndef SLIMSERVICE_H
#define SLIMSERVICE_H

#include <QObject>

class QIODevice;
class SlimStringReader;
class SlimStringWriter;
class MetaObjectExecutor;
class SlimString;
class FixtureLoader;
class SlimExecutionContext;

class SlimService : public QObject
{
    Q_OBJECT

public:
    SlimService(QIODevice *inputDevice, QIODevice *outputDevice, QObject *parent = nullptr);
    ~SlimService();

public slots:
    void start();
    void stop();

private slots:
    void onStringReceived(const QString &string);

private:
    QIODevice *m_inputDevice = nullptr;
    QIODevice *m_outputDevice = nullptr;
    SlimStringReader *m_reader;
    SlimStringWriter *m_writer;
    MetaObjectExecutor *m_executor;
    FixtureLoader *m_fixtureLoader;
    SlimExecutionContext *m_executionContext;
};

#endif // SLIMSERVICE_H
