#ifndef ADDUPCHANGE_H
#define ADDUPCHANGE_H

#include <QObject>
#include <QMap>

namespace fitnesse
{
namespace fixtures
{

class AddUpChange : public QObject
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit AddUpChange();

public slots:
    void reset();
    void set(const QString coin, int amount);
    QString get(const QString &requestedValue);

private:
    QMap<QString, int> m_coinValues;
    int m_totalCents;
};

}
}
#endif // ADDUPCHANGE_H
