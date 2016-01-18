#ifndef PAGEDRIVER_H
#define PAGEDRIVER_H

#include <QObject>
#include "fixture/idecisiontable.h"

namespace fitnesse
{
namespace fixtures
{

class PageDriver : public QObject, public IDecisionTable
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit PageDriver(QObject *parent = 0);

public slots:

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
#endif // PAGEDRIVER_H
