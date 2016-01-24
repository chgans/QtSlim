/****************************************************************************
**
** Copyright (C) 2016 Christian Gagneraud <chgans@gna.org>
** All rights reserved.
**
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 3 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL3 included in the packaging of this file.
** Please review the following information to ensure the GNU Lesser General
** Public License version 3 requirements will be met:
** https://www.gnu.org/licenses/lgpl-3.0.html.
**
****************************************************************************/

#include <QString>
#include <QtTest>
#include <QCoreApplication>

#include "introspection/metaobjectmaker.h"
#include "../fixtures/basicqobectfixture.h"

class MetaObjectMakerTest : public QObject
{
    Q_OBJECT
public:
    explicit MetaObjectMakerTest(QObject *parent = 0);

private slots:
    void initTestCase();
    void cleanupTestCase();

    void testMake();
};

MetaObjectMakerTest::MetaObjectMakerTest(QObject *parent) : QObject(parent)
{

}

void MetaObjectMakerTest::initTestCase()
{

}

void MetaObjectMakerTest::cleanupTestCase()
{

}

void MetaObjectMakerTest::testMake()
{
    MetaObjectMaker maker(BasicQObectFixture::staticMetaObject);
    maker.setParameters(QVariantList());
    QCOMPARE(maker.validate(), true);
    QCOMPARE(maker.make(), true);
    QCOMPARE(maker.errorMessage(), QString());
    QVERIFY(maker.object() != nullptr);
    qDebug() << maker.object();
    qDebug() << maker.object()->metaObject()->className();
    QVERIFY(qobject_cast<BasicQObectFixture *>(maker.object()) != nullptr);
}

QTEST_MAIN(MetaObjectMakerTest)

#include "tst_metaobjectmaker.moc"
