#ifndef METAMETHODLISTTESTSUITE_H
#define METAMETHODLISTTESTSUITE_H

#include <QObject>

class MetaMethodListTestSuite : public QObject
{
    Q_OBJECT
public:
    explicit MetaMethodListTestSuite(QObject *parent = 0);

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testFilterByName();
    void testFilterByName_NullName();
    void testFilterByName_EmptyName();
    void testFilterByName_NoneFound();
    void testFilterByArgumentCount();
    void testFilterByArgumentCount_NegativeCount();
    void testFilterByArgumentCount_NoneFound();

private:
    static const QMetaObject META_OBJECT;
};

#endif // METAMETHODLISTTESTSUITE_H
