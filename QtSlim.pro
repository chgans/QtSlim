TEMPLATE = subdirs
CONFIG += ordered

SUBDIRS += \
    lib \
    app \
    tests \
    fitnesse \
    doc

DISTFILES += .travis.yml README.md LICENSE
