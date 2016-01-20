#include "echofixture.h"

#include <QDebug>

namespace fitnesse
{
namespace fixtures
{

EchoFixture::EchoFixture(QObject *parent) : QObject(parent)
{

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
