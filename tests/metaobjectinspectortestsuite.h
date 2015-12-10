#ifndef METAOBJECTINSPECTORTESTSUITE_H
#define METAOBJECTINSPECTORTESTSUITE_H

#include <QObject>

class MetaObjectInspectorTestSuite : public QObject
{
    Q_OBJECT
public:
    explicit MetaObjectInspectorTestSuite(QObject *parent = 0);

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testConstructors();
    void testAllMethods();
    void testFunctionMethods();
    void testSignalMethods();
    void testSlotMethods();

private:
    static const QMetaObject META_OBJECT;
};

#endif // METAOBJECTINSPECTORTESTSUITE_H
