#include "testslim.h"

#include <QDebug>

namespace fitnesse
{
namespace fixtures
{


TestSlim::TestSlim():
    QObject(),
    m_ctorArg(-1)
{

}

TestSlim::TestSlim(int arg):
    QObject(),
    m_ctorArg(arg)
{

}

bool TestSlim::echoBoolean(bool value)
{
    return value;
}

int TestSlim::echoInt(int value)
{
    return value;
}

void TestSlim::setString(const QString &value)
{
    m_stringArg = value;
}

QString TestSlim::getStringArg() const
{
    return m_stringArg;
}

int TestSlim::returnConstructorArg() const
{
    return m_ctorArg;
}

void TestSlim::table(QVariant table)
{
    Q_UNUSED(table);
}

void TestSlim::beginTable()
{
}

void TestSlim::endTable()
{
}

void TestSlim::execute()
{
}

void TestSlim::reset()
{
}

}
}
