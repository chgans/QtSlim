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

#include "slimlibraryhelper.h"
#include "slimexecutioncontext.h"

#include <QDebug>

SlimLibraryHelper::SlimLibraryHelper(QObject *parent) : QObject(parent)
{

}

void SlimLibraryHelper::setExecutionContext(SlimExecutionContext *context)
{
    m_context =  context;
}

QObject *SlimLibraryHelper::getFixture()
{
    return m_context->instance("scriptTableActor");
}

void SlimLibraryHelper::pushFixture()
{
    QObject *fixture = getFixture();
    m_fixtureStack.push(fixture);
}

void SlimLibraryHelper::popFixture()
{
    QObject *fixture = m_fixtureStack.pop();
    m_context->setInstance("scriptTableActor", fixture);
}

QObject *SlimLibraryHelper::cloneSymbol(QObject *symbol)
{
    return symbol;
}
