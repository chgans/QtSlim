#ifndef METAOBJECTMAKERTESTSUITE_H
#define METAOBJECTMAKERTESTSUITE_H

#include <QObject>

class MetaObjectMakerTestSuite : public QObject
{
    Q_OBJECT
public:
    explicit MetaObjectMakerTestSuite(QObject *parent = 0);

private slots:
    void initTestCase();
    void cleanupTestCase();

    void testMake();
};

#endif // METAOBJECTMAKERTESTSUITE_H
