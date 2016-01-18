#ifndef TESTQUERY_H
#define TESTQUERY_H

#include <QObject>
#include "fixture/idecisiontable.h"
#include <QList>

namespace fitnesse
{
namespace fixtures
{

typedef QList<QString> TableColumn;
typedef QList<TableColumn> TableRow;
typedef QList<TableRow> Table;

class TestQuery : public QObject, public IDecisionTable
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit TestQuery(int arg);

public slots:
    Table query() const;

private:
    int m_arg;

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

Q_DECLARE_METATYPE(fitnesse::fixtures::TableColumn)
Q_DECLARE_METATYPE(fitnesse::fixtures::TableRow)
Q_DECLARE_METATYPE(fitnesse::fixtures::Table)

#endif // TESTQUERY_H
