#include "addupchange.h"

fitnesse::fixtures::AddUpChange::AddUpChange():
    m_totalCents(0)
{
    m_coinValues["1c"] = 1;
    m_coinValues["5c"] = 5;
    m_coinValues["10c"] = 10;
    m_coinValues["25c"] = 25;
    m_coinValues["50c"] = 50;
    m_coinValues["$1"] = 100;
}

void fitnesse::fixtures::AddUpChange::reset()
{
    m_totalCents = 0;
}

void fitnesse::fixtures::AddUpChange::set(const QString coin, int amount)
{
    if (!m_coinValues.contains(coin))
        return;
    m_totalCents += amount*m_coinValues.value(coin);
}

QString fitnesse::fixtures::AddUpChange::get(const QString &requestedValue)
{
    if (requestedValue == QString("$ total"))
        return QString("%L1").arg(m_totalCents/100.0, 0, 'f', 2);
    else
        return QString("%1").arg(m_totalCents);
}

