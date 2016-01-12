#ifndef METAMETHODINVOKERTESTSUITE_H
#define METAMETHODINVOKERTESTSUITE_H

#include <QObject>
#include <QVariant>

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
    QVariant m_invokeResult;
};

#endif // METAMETHODINVOKERTESTSUITE_H
