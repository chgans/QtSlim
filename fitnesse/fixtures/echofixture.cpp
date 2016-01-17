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

int EchoFixture::echoInt(int number) const
{
    return number;
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
