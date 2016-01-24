#!/bin/bash

set -xe

testsuite=$1
Testsuite=`echo ${testsuite:0:1} | tr  '[a-z]' '[A-Z]'`${testsuite:1}

cp -a template/ $testsuite
mv $testsuite/testsuite.pro $testsuite/$testsuite.pro
mv $testsuite/tst_testsuite.cpp $testsuite/tst_$testsuite.cpp
for f in $testsuite/$testsuite.pro $testsuite/tst_$testsuite.cpp;
do
    sed -i -e "s/%testsuite%/$testsuite/g" $f
    sed -i -e "s/%Testsuite%/$Testsuite/g" $f
done

echo "SUBDIRS += $testsuite" >> tests.pro
