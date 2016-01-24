# Debug script and stop on error
set -xe

# For troubleshooting
pwd
which sh
sh --version
env | sort

# Set env
export MAKE="mingw32-make -j 3"
export RELEASE="QtSlim-MinGW32_${APPVEYOR_REPO_BRANCH}-${APPVEYOR_REPO_COMMIT}_build-${APPVEYOR_BUILD_NUMBER}"

# Build in separate directory
mkdir build
cd build

# Configure and build
qmake ../QtSlim.pro 
$MAKE

# Test
QT_LOGGING_CONF="*=false" $MAKE check TESTARGS='-o $(QMAKE_TARGET).xml,xunitxml'

# Make binary tarball
mkdir $RELEASE
cd $RELEASE
cp ../app/release/qtslim.exe .
cp ../tests/*/release/qtslim-testsuite-*.exe .
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
ls -l $RELEASE.zip
cd ..

# Application smoke test
# TODO: uncompress archive and run test suites and smoke tests
# ./app/qtslim --version

