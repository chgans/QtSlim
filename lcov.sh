TOP_SRCDIR=$PWD
TOP_BUILDDIR=$PWD/build
COV_HTMLDIR=$TOP_BUILDDIR/lcov
COV_PREFIX=$(cd $TOP_SRCDIR/..; pwd)

rm -Rf build
mkdir build
cd build

# Configure for coverage and build
qmake .. -spec linux-g++ CONFIG+=debug "QMAKE_CXXFLAGS+=--coverage" "QMAKE_LFLAGS+=--coverage"
for dir in lib tests;
do
    make -j10
done

# Create coverage info with zero counters
lcov --directory $TOP_BUILDDIR \
      --capture --initial \
      --output-file zero.info

# Capture coverage info for unit test suites
# TODO: Capture for each test suite and add them all up
# TODO: Same for fitnesse tests
make check
lcov --directory $TOP_BUILDDIR \
     --capture \
     --test-name unit-tests \
     --output-file tests.info

# Add up coverages info
lcov --add-tracefile zero.info \
     --add-tracefile tests.info \
     --output-file all.info
     
# Clean up coverage info
lcov --remove all.info \
     "/usr/include/*" \
     "$TOP_BUILDDIR/*" \
     "$TOP_SRCDIR/tests/*" \
     "$TOP_SRCDIR/fitnesse/*" \
     "$TOP_SRCDIR/app/*" \
     --output-file qtslim.info

# Generate report
# TODO: move to gcovr once travis moves to newer ubuntu?
genhtml --output-directory $COV_HTMLDIR \
	--prefix $COV_PREFIX \
	--demangle-cpp \
	qtslim.info

firefox file://$COV_HTMLDIR/index.html
