#ifndef BASICQOBECTFIXTURE_H
#define BASICQOBECTFIXTURE_H

#include <QObject>

class BasicQObectFixture : public QObject
{
    Q_OBJECT
public:
    explicit BasicQObectFixture(QObject *parent = 0);

    Q_INVOKABLE explicit BasicQObectFixture(int param1);
    Q_INVOKABLE explicit BasicQObectFixture(int param1, bool param2);

    Q_INVOKABLE bool functionMethod();
    Q_INVOKABLE bool functionMethod(int param1);
    Q_INVOKABLE bool functionMethod(int param1, bool param2);

signals:
    void signalMethodWithNoParam();
    void signalMethodWithOneParam(int param1);
    void signalMethodWithTwoParams(bool param1, qreal param2);

public slots:
    void slotMethodWithNoParam();
    void slotMethodWithOneParam(const QString &param1);
    void slotMethodWithTwoParams(const QString &param1, const QString &param2);
};

#endif // BASICQOBECTFIXTURE_H
