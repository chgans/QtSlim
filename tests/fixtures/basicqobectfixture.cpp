#include "basicqobectfixture.h"

BasicQObectFixture::BasicQObectFixture(QObject *parent):
    QObject(parent)
{

}

BasicQObectFixture::BasicQObectFixture(int param1):
    QObject()
{
    Q_UNUSED(param1);
}

BasicQObectFixture::BasicQObectFixture(int param1, bool param2):
    QObject()
{
    Q_UNUSED(param1);
    Q_UNUSED(param2);
}

bool BasicQObectFixture::functionMethod()
{
    return false;
}

bool BasicQObectFixture::functionMethod(int param1)
{
    Q_UNUSED(param1);
    return false;
}

bool BasicQObectFixture::functionMethod(int param1, bool param2)
{
    Q_UNUSED(param1);
    Q_UNUSED(param2);
    return false;
}

void BasicQObectFixture::slotMethodWithNoParam()
{

}

void BasicQObectFixture::slotMethodWithOneParam(const QString &param1)
{
    Q_UNUSED(param1);
}

void BasicQObectFixture::slotMethodWithTwoParams(const QString &param1, const QString &param2)
{
    Q_UNUSED(param1);
    Q_UNUSED(param2);
}

