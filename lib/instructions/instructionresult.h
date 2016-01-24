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

#ifndef INSTRUCTIONRESULT_H
#define INSTRUCTIONRESULT_H

#include <QString>
#include <QVariant>


// TBD:
// - Do we need two InstructionResult classes? One for Application error and one
//   for SLim error (exception?)
// - Should we keep InstructionResult abstract and add a ValueInstructionResult (re Void InstructionResult)

class InstructionResult
{
public:
    InstructionResult(const QString &id, const QVariant &result = QVariant());

    QString id() const;
    QVariant result() const;

    virtual bool hasResult() const;
    virtual bool hasError() const;

private:
    QString m_id;
    QVariant m_value;
};

#endif // INSTRUCTIONRESULT_H
