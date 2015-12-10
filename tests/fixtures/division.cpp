#include "division.h"

#include <QDebug>

Division::Division(QObject *parent):
    QObject(parent), m_numerator(0.0), m_denominator(0.0)
{
}

qreal Division::numerator() const
{
    return m_numerator;
}

qreal Division::denominator() const
{
    return m_denominator;
}

void Division::setNumerator(qreal value)
{
    m_numerator = value;
    qDebug() << "Division::setNumerator" << value;
}

void Division::setDenominator(qreal value)
{
    m_denominator = value;
    qDebug() << "Division::setDenominator" << value;
}

qreal Division::quotient() const
{
    qreal result = m_numerator/m_denominator;
    qDebug() << "Division::quotient" << result;
    return result;
}

