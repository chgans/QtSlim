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

#include "echofixture.h"

#include <QDebug>

namespace fitnesse
{
namespace fixtures
{

EchoFixture::EchoFixture():
    m_name("Uncle Bob"),
    m_calledConstructorSignature("EchoFixture::EchoFixture()")
{

}

EchoFixture::EchoFixture(const QString &unusedArgument):
    m_name("Uncle Bob"),
    m_calledConstructorSignature("EchoFixture::EchoFixture(QString)")
{
    Q_UNUSED(unusedArgument);
}

QString EchoFixture::name() const
{
    return m_name;
}

void EchoFixture::setname(const QString &name)
{
    m_name = name;
}

bool EchoFixture::nameContains(const QString &text) const
{
    return m_name.contains(text);
}

QString EchoFixture::echo(const QString &text) const
{
    return text;
}

void EchoFixture::echoVoid() const
{
    return;
}

int EchoFixture::echoInt(int value) const
{
    return value;
}

double EchoFixture::echoDouble(double value) const
{
    return value;
}

bool EchoFixture::echoBool(bool value) const
{
    return value;
}

char EchoFixture::echoChar(char value) const
{
    return value;
}

QString EchoFixture::echoString(const QString &value) const
{
    return value;
}

QDate EchoFixture::echoDate(const QDate &value) const
{
    return value;
}

QDate EchoFixture::echoIsoDate(const QDate &value) const
{
    return value;
}

QTime EchoFixture::echoTime(const QTime &value) const
{
    return value;
}

QTime EchoFixture::echoIsoTime(const QTime &value) const
{
    return value;
}

QList<int> EchoFixture::echoIntList(const QList<int> &value) const
{
    return value;
}

QList<double> EchoFixture::echoDoubleList(const QList<double> &value) const
{
    return value;
}

QList<bool> EchoFixture::echoBoolList(const QList<bool> &value) const
{
    return value;
}

QList<char> EchoFixture::echoCharList(const QList<char> &value) const
{
    return value;
}

QList<QString> EchoFixture::echoStringList(const QList<QString> &value) const
{
    return value;
}

void EchoFixture::methodReturningVoid()
{

}

QString EchoFixture::methodReturningString()
{
    return QString("this is a string");
}

int EchoFixture::methodReturningInt()
{
    return 42;
}

double EchoFixture::methodReturningDouble()
{
    return 4.2;
}

QString EchoFixture::methodWithDifferentSignatures()
{
   return QString("EchoFixture::methodWithDifferentSignatures()");
}

QString EchoFixture::methodWithDifferentSignatures(const QString &unusedArg)
{
    Q_UNUSED(unusedArg);
    return QString("EchoFixture::methodWithDifferentSignatures(QString)");
}

QString EchoFixture::calledConstructorSignature()
{
    return m_calledConstructorSignature;
}


void EchoFixture::table(QVariant table)
{
    Q_UNUSED(table);
}

void EchoFixture::beginTable()
{

}

void EchoFixture::endTable()
{

}

void EchoFixture::execute()
{

}

void EchoFixture::reset()
{

}

}
}
