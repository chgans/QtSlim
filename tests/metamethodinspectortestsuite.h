#ifndef METAMETHODINSPECTORTESTSUITE_H
#define METAMETHODINSPECTORTESTSUITE_H

#include <QObject>

// TBD: test parameterNames()
class MetaMethodInspectorTestSuite: public QObject
{
    Q_OBJECT
public:
    MetaMethodInspectorTestSuite(QObject *parent = 0);

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testMethodWitParameters();
    void testMethodWithoutParameters();
    void testMethodWitReturnValue();
    void testMethodWithoutReturnValue();

private:
    static const QMetaObject META_OBJECT;
};

#endif // METAMETHODINSPECTORTESTSUITE_H
