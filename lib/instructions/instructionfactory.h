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

#ifndef INSTRUCTIONFACTORY_H
#define INSTRUCTIONFACTORY_H

#include "instruction.h"

class AssignInstruction;
class CallAndAssignInstruction;
class CallInstruction;
class ImportInstruction;
class InvalidInstruction;
class MakeInstruction;

class InstructionFactory
{
public:
    static Instruction *createInstruction(const QVariantList &tokens);

private:
    InstructionFactory();
    static Instruction *createAssignInstruction(const QString &id, const QVariantList &tokens);
    static Instruction *createCallAndAssignInstruction(const QString &id, const QVariantList &tokens);
    static Instruction *createCallInstruction(const QString &id, const QVariantList &tokens);
    static Instruction *createImportInstruction(const QString &id, const QVariantList &tokens);
    static Instruction *createInvalidInstruction(const QString &id, const QString &name, const QVariantList &tokens);
    static Instruction *createMakeInstruction(const QString &id, const QVariantList &tokens);
};

#endif // INSTRUCTIONFACTORY_H
