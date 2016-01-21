#include "pagedriver.h"


fitnesse::fixtures::PageDriver::PageDriver(QObject *parent) : QObject(parent)
{

}

void fitnesse::fixtures::PageDriver::table(QVariant table)
{
    Q_UNUSED(table);
}

void fitnesse::fixtures::PageDriver::beginTable()
{
}

void fitnesse::fixtures::PageDriver::endTable()
{
}

void fitnesse::fixtures::PageDriver::execute()
{
}

void fitnesse::fixtures::PageDriver::reset()
{
}
