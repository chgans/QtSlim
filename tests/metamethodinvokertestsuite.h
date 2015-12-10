#ifndef METAMETHODINVOKERTESTSUITE_H
#define METAMETHODINVOKERTESTSUITE_H

#include <QObject>

class MetaMethodInvokerTestSuite : public QObject
{
    Q_OBJECT
public:
    explicit MetaMethodInvokerTestSuite(QObject *parent = 0);

private slots:
    void initTestCase();
    void cleanupTestCase();

    void testInvoke();

private:
    void invoke(QObject *object, const QString &methodName, const QVariantList &parameters);

};

#endif // METAMETHODINVOKERTESTSUITE_H
