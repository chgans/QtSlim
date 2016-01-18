#ifndef TESTSLIM_H
#define TESTSLIM_H

#include <QObject>
#include "fixture/idecisiontable.h"

namespace fitnesse
{
namespace fixtures
{

// FIXME: using QObject *parent = 0 crashes when constructor called with int parameter and
// there's exist another ctor with int + parent paramterers
class TestSlim : public QObject, public IDecisionTable
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit TestSlim();
    Q_INVOKABLE explicit TestSlim(int arg);

public slots:
    bool echoBoolean(bool value);
    int echoInt(int value);
    void setString(const QString &value);
    QString getStringArg() const;
    int returnConstructorArg() const;

private:
    QString m_stringArg;
    int m_ctorArg;

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
#endif // TESTSLIM_H
