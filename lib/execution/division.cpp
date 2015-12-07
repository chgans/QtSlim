#include "division.h"

#include <QDebug>

Division::Division(QObject *parent) : QObject(parent)
{

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
    qDebug() << "Division::quotient" << m_numerator/m_denominator;
    return m_numerator/m_denominator;
}

