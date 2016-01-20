#ifndef ECHOFIXTURE_H
#define ECHOFIXTURE_H

#include <QObject>
#include <QDateTime>
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

    Q_INVOKABLE int echoInt(int value) const;
    Q_INVOKABLE double echoDouble(double value) const;
    Q_INVOKABLE bool echoBool(bool value) const;
    Q_INVOKABLE char echoChar(char value) const;
    Q_INVOKABLE QString echoString(const QString &value) const;

    Q_INVOKABLE QDate echoDate(const QDate &value) const;
    Q_INVOKABLE QDate echoIsoDate(const QDate &value) const;
    Q_INVOKABLE QTime echoTime(const QTime &value) const;
    Q_INVOKABLE QTime echoIsoTime(const QTime &value) const;

    Q_INVOKABLE QList<int> echoIntList(const QList<int> &value) const;
    Q_INVOKABLE QList<double> echoDoubleList(const QList<double> &value) const;
    Q_INVOKABLE QList<bool> echoBoolList(const QList<bool> &value) const;
    Q_INVOKABLE QList<char> echoCharList(const QList<char> &value) const;
    Q_INVOKABLE QList<QString> echoStringList(const QList<QString> &value) const;

private:
    QString m_name;

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

#endif // ECHOFIXTURE_H
