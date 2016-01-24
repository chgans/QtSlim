# Run in top-level directory
cd `dirname "$0"`/..

# Stop on error
set -e

pwd
which sh
sh --version
env | sort

# Set env
export MAKE="mingw32-make -j 8"

# Configure and build
qmake ../QtSlim.pro 
$MAKE

# Test
QT_LOGGING_CONF="*=false" $MAKE check TESTARGS="-o $(QMAKE_TARGET).xml,xunitxml"

# Make binary tarball
mkdir $RELEASE
cd $RELEASE
cp ../app/release/qtslim.exe .
cp ../tests/*/qtslim-*-testsuite.exe .
cp $QTDIR/bin/Qt5Core.dll .
cp $QTDIR/bin/Qt5Network.dll .
cp $QTDIR/bin/Qt5Test.dll .
cp $QTDIR/bin/libgcc_s_dw2-1.dll .
cp $QTDIR/bin/libstdc++-6.dll .
cp $QTDIR/bin/icuin53.dll .
cp $QTDIR/bin/icuuc53.dll .
cp $QTDIR/bin/libwinpthread-1.dll .
cp $QTDIR/bin/icudt53.dll .
cp -R $QTDIR/plugins/platforms .
rm -f platforms/*d.dll
cd ..
7z a -tzip $RELEASE.zip $RELEASE
ls -l $RELEASE$.zip
