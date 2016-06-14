TEMPLATE = subdirs
CONFIG += ordered

SUBDIRS += \
    lib \
    app \
    tests \
    fitnesse \
    doc

DISTFILES += README.md LICENSE \
    .gitignore \
    .travis.yml appveyor.yml .coveralls.yml \
    ci-scripts/appveyor-build.sh  \
    ci-scripts/travis-after-success.env  \
    ci-scripts/travis-install.env  \
    ci-scripts/travis-script.env  \
    ci-scripts/travis-simulate-env.env \
    lcov.sh
