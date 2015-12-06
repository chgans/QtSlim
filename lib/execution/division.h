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
    void setNumerator(qreal value)
    {
        m_numerator = value;
    }

    void setDenominator(qreal value)
    {
        m_denominator = value;
    }

    qreal quotient() const
    {
        return m_numerator/m_denominator;
    }

private:
    qreal m_numerator;
    qreal m_denominator;
};

#endif // DIVISION_H
