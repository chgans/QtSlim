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

#ifndef DIVISION_H
#define DIVISION_H

#include <QObject>
#include "fixture/idecisiontable.h"

namespace fitnesse
{
namespace fixtures
{

class Division : public QObject, public IDecisionTable
{
    Q_OBJECT
    Q_PROPERTY(qreal numerator READ numerator WRITE setNumerator)
    Q_PROPERTY(qreal denominator READ denominator WRITE setDenominator)

public:
    Q_INVOKABLE explicit Division(QObject *parent = 0);

    Q_INVOKABLE qreal numerator() const;
    Q_INVOKABLE qreal denominator() const;

public slots:
    void setNumerator(qreal value);
    void setDenominator(qreal value);
    qreal quotient() const;

private:
    qreal m_numerator;
    qreal m_denominator;

    // IDecisionTable interface
public slots:
    void table(QVariant table);
    void beginTable();
    void endTable();
    void execute();
    void reset();
};

}
}

#endif // DIVISION_H
