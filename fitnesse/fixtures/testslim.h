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

#ifndef TESTSLIM_H
#define TESTSLIM_H

#include <QObject>
#include "fixture/idecisiontable.h"

namespace fitnesse
{
namespace fixtures
{

// FIXME: using QObject *parent = 0 crashes when constructor called with int parameter and
// there's exist another ctor with int + parent paramterers
class TestSlim : public QObject, public IDecisionTable
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit TestSlim();
    Q_INVOKABLE explicit TestSlim(int arg);
    Q_INVOKABLE explicit TestSlim(int arg, TestSlim *other);

public slots:
    bool echoBoolean(bool value);
    int echoInt(int value);
    void setString(const QString &value);
    QString getStringArg() const;
    int returnConstructorArg() const;
    TestSlim *createTestSlimWithString(const QString &arg) const;
    // FIXME: should be const here, but there's conversion problem between const vs non-const via QVariant
    bool isSame(TestSlim *other) const;
    QString getStringFromOther(TestSlim *other) const;

private:
    QString m_stringArg;
    int m_ctorArg;

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

Q_DECLARE_METATYPE(fitnesse::fixtures::TestSlim*)
Q_DECLARE_METATYPE(const fitnesse::fixtures::TestSlim*)

#endif // TESTSLIM_H
