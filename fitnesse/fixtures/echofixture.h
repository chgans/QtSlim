#ifndef ECHOFIXTURE_H
#define ECHOFIXTURE_H

#include <QObject>
#include "fixture/idecisiontable.h"

namespace fitnesse
{
namespace fixtures
{


class EchoFixture : public QObject, public IDecisionTable
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit EchoFixture(QObject *parent = 0);

    Q_INVOKABLE QString name() const;
    Q_INVOKABLE void setname(const QString &name);
    Q_INVOKABLE bool nameContains(const QString &text) const;
    Q_INVOKABLE QString echo(const QString &text) const;
    Q_INVOKABLE int echoInt(int number) const;

private:
    QString m_name;

    // IDecisionTable interface
public:
    void table(QVariant table);
    void beginTable();
    void endTable();
    void execute();
    void reset();
};

}
}

#endif // ECHOFIXTURE_H
