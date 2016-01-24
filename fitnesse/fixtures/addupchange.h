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

#ifndef ADDUPCHANGE_H
#define ADDUPCHANGE_H

#include <QObject>
#include <QMap>

namespace fitnesse
{
namespace fixtures
{

class AddUpChange : public QObject
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit AddUpChange();

public slots:
    void reset();
    void set(const QString coin, int amount);
    QString get(const QString &requestedValue);

private:
    QMap<QString, int> m_coinValues;
    int m_totalCents;
};

}
}
#endif // ADDUPCHANGE_H
