# Qt Slim

An implementation of the Slim test system (part of http://fitnesse.org) for use in Qt based projects

## Continuous integration

| Runner | Platform | Status |
|--------|----------|--------|
| https://www.appveyor.com | Windows | [![Build status](https://ci.appveyor.com/api/projects/status/jj5oa6n0cls5puaw?svg=true)](https://ci.appveyor.com/project/chgans/qtslim) |
| https://travis-ci.org | Linux and Mac | [![Build Status](https://travis-ci.org/chgans/QtSlim.svg?branch=master)](https://travis-ci.org/chgans/QtSlim) [![Coverage Status](https://coveralls.io/repos/github/chgans/QtSlim/badge.svg?branch=master)](https://coveralls.io/github/chgans/QtSlim?branch=master) |

## Supported platform

Binary packages are provided for the following platforms:
- Linux: Ubuntu 14.04, x86-64, Qt 5.2
- Windows: MinGW 4.9, x86-32, Qt 5.4
- Mac: Mac OS X 10.9, x86-64, Qt 5.5

Building the sources requires Qt 5.2 or later.

Qt Slim dependes on the following Qt modules:
- QtCore
- QtNetwork
- QtTest

## Compiling Qt Slim

You can build Qt Slim with

    git clone https://github.com/chgans/QtSlim.git
    cd QtSlim
    mkdir build
    qmake ..
    make (or mingw32-make or nmake or jom, depending on your platform)

Installation ("make install") is not needed. It is however possible, using

    make install INSTALL_ROOT=$INSTALL_DIRECTORY

## TODO

- [X] Run unit tests in CI
- [ ] Run FitNesse tests in CI
- [ ] Upload build artifact from CI to github
- [X] Add code coverage
- [ ] Fix code coverage result difference b/w cpp-coverals and lcov
- [ ] Add Clang static-analiser?
- [ ] Add licensing information to README, LICENSE and source code files
- [X] Add build instruction to README
- [ ] Add tutorial/examples
- [ ] Move CI logic to ci-scripts folder
- [ ] Add a UDP logger and a log viewer
- [ ] Switch CI Windows build to 64 bits
- [ ] Build unit tests and fitnesse fixtures only in debug mode

