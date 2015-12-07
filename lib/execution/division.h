#ifndef DIVISION_H
#define DIVISION_H

#include <QObject>

class Division : public QObject
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit Division(QObject *parent = 0);

signals:

public slots:
    void setNumerator(qreal value);
    void setDenominator(qreal value);
    qreal quotient() const;

private:
    qreal m_numerator;
    qreal m_denominator;
};

#endif // DIVISION_H
