#include "slimlibraryhelper.h"
#include "slimexecutioncontext.h"

#include <QDebug>

SlimLibraryHelper::SlimLibraryHelper(QObject *parent) : QObject(parent)
{

}

void SlimLibraryHelper::setExecutionContext(SlimExecutionContext *context)
{
    m_context =  context;
}

QObject *SlimLibraryHelper::getFixture()
{
    return m_context->instance("scriptTableActor");
}

void SlimLibraryHelper::pushFixture()
{
    QObject *fixture = getFixture();
    m_fixtureStack.push(fixture);
}

void SlimLibraryHelper::popFixture()
{
    QObject *fixture = m_fixtureStack.pop();
    m_context->setInstance("scriptTableActor", fixture);
}

QObject *SlimLibraryHelper::cloneSymbol(QObject *symbol)
{
    return symbol;
}
