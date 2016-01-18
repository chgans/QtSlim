#ifndef SETUP_H
#define SETUP_H

#include <QObject>
#include "fixture/idecisiontable.h"

namespace fitnesse
{
namespace fixtures
{

class SetUp : public QObject, public IDecisionTable
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit SetUp(const QString &configuration);

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
#endif // SETUP_H
