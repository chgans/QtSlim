#ifndef IDECISIONTABLE_H
#define IDECISIONTABLE_H

#include <QVariant>

class IDecisionTable
{
public:
    IDecisionTable() {}
    virtual ~IDecisionTable() {}

    virtual void table(QVariant table) = 0;
    virtual void beginTable() = 0;
    virtual void endTable() = 0;
    virtual void execute() = 0;
    virtual void reset() = 0;
};

#endif // IDECISIONTABLE_H
