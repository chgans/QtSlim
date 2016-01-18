#ifndef TEARDOWN_H
#define TEARDOWN_H

#include <QObject>
#include "fixture/idecisiontable.h"

namespace fitnesse
{
namespace fixtures
{

class TearDown : public QObject, public IDecisionTable
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit TearDown();


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
#endif // TEARDOWN_H
