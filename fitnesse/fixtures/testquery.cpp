#include "testquery.h"

fitnesse::fixtures::TestQuery::TestQuery(int arg):
    m_arg(arg)
{

}

fitnesse::fixtures::Table fitnesse::fixtures::TestQuery::query() const
{
    Table table;
    for (int i=0; i < m_arg; i++) {
        QList<QString> col1;
        col1 << "n" << QString("%1").arg(i);
        QList<QString> col2;
        col2 << "2n" << QString("%1").arg(2*i);
        QList<QList<QString> > row;
        row << col1 << col2;
        table << row;
    }
    return table;
}

void fitnesse::fixtures::TestQuery::table(QVariant table)
{
    Q_UNUSED(table)
}

void fitnesse::fixtures::TestQuery::beginTable()
{
}

void fitnesse::fixtures::TestQuery::endTable()
{
}

void fitnesse::fixtures::TestQuery::execute()
{
}

void fitnesse::fixtures::TestQuery::reset()
{
}
