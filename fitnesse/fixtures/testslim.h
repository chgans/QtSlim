#ifndef TESTSLIM_H
#define TESTSLIM_H

#include <QObject>
#include "fixture/idecisiontable.h"

namespace fitnesse
{
namespace fixtures
{

class TestSlim : public QObject, public IDecisionTable
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit TestSlim(QObject *parent = 0);

public slots:
    bool echoBoolean(bool value);
    void setString(const QString &value);
    QString getStringArg() const;

private:
    QString m_stringArg;

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
