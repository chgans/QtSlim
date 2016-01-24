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

#ifndef BASICQOBECTFIXTURE_H
#define BASICQOBECTFIXTURE_H

#include <QObject>

class BasicQObectFixture : public QObject
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit BasicQObectFixture(QObject *parent = 0);

    Q_INVOKABLE explicit BasicQObectFixture(int param1);
    Q_INVOKABLE explicit BasicQObectFixture(int param1, bool param2);

    Q_INVOKABLE bool functionMethod();
    Q_INVOKABLE bool functionMethod(int param1);
    Q_INVOKABLE bool functionMethod(int param1, bool param2);

signals:
    void signalMethodWithNoParam();
    void signalMethodWithOneParam(int param1);
    void signalMethodWithTwoParams(bool param1, qreal param2);

public slots:
    void slotMethodWithNoParam();
    void slotMethodWithOneParam(const QString &param1);
    void slotMethodWithTwoParams(const QString &param1, const QString &param2);
};

#endif // BASICQOBECTFIXTURE_H
