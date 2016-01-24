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

#ifndef SLIMDESERIALISER_H
#define SLIMDESERIALISER_H

#include <QVariant>

class SlimDeserialiser
{
public:
    static QVariant deserialise(const QString &data);

private:
    SlimDeserialiser();
    static QString deserialiseString(const QString &data);
    static QVariant deserialiseList(const QString &data);
    static QString removeNextListItem(QString &data);
};

#endif // SLIMDESERIALISER_H
