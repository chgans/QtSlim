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

#include "slimserialiser.h"

QString SlimSerialiser::serialise(const QVariant &value)
{
    return serialiseString(value);
}

SlimSerialiser::SlimSerialiser()
{

}

QString SlimSerialiser::serialiseLength(int length)
{
    static const int digits = 6;
    static const int base = 10;
    static const QChar fillChar('0');
    return QString("%1").arg(length, digits, base, fillChar);
}

QString SlimSerialiser::serialiseString(const QVariant &value)
{
    QString representation;
    if (value.type() == QVariant::List)
        representation = serialiseList(value.toList());
    else if (value.type() == QVariant::Double) {
        static const int precision = 7;
        static const char format = 'g';
        static const int fieldWidth = 0;
        representation = QString("%1").arg(value.toDouble(),
                                           fieldWidth,
                                           format,
                                           precision);
    }
    else
        representation = value.toString();
    return QString("%1:%2")
            .arg(serialiseLength(representation.count()))
            .arg(representation);
}

QString SlimSerialiser::serialiseList(const QVariantList &values)
{
    QStringList serialisedValues;
    foreach (const QVariant &value, values) {
        serialisedValues << serialise(value).append(QChar(':'));
    }
    return QString("[%1:%2]")
            .arg(serialiseLength(serialisedValues.count()))
            .arg(serialisedValues.join(""));
}

