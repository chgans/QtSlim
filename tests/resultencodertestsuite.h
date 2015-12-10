#ifndef RESULTECODERTESTSUITE_H
#define RESULTECODERTESTSUITE_H

#include <QObject>

class ResultEncoderTestSuite : public QObject
{
    Q_OBJECT
public:
    explicit ResultEncoderTestSuite(QObject *parent = 0);

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testEncodeResult();
    void testEncodeOkResult();
    void testEncodeErrorResult();
    void testEncodeVoidResult();
};

#endif // RESULTECODERTESTSUITE_H
