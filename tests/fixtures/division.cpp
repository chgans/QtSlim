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

void Division::table(QVariant table)
{
    Q_UNUSED(table)
}

void Division::beginTable()
{

}

void Division::endTable()
{

}

void Division::execute()
{

}

void Division::reset()
{

}

