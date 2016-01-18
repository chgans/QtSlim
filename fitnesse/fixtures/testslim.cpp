#include "testslim.h"

#include <QDebug>

namespace fitnesse
{
namespace fixtures
{


TestSlim::TestSlim(QObject *parent) : QObject(parent)
{

}

bool TestSlim::echoBoolean(bool value)
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
