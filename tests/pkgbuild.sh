#!/bin/sh
# Script to build a MacOS pkg
#
# Version: 20241015

set -e

make install DESTDIR=${PWD}/osx-pkg
mkdir -p ${PWD}/osx-pkg/usr/share/doc/libfguid
cp AUTHORS COPYING COPYING.LESSER NEWS README ${PWD}/osx-pkg/usr/share/doc/libfguid

VERSION=`sed '5!d; s/^  \[//;s/\],$//' configure.ac`
pkgbuild --root osx-pkg --identifier com.github.libyal.libfguid --version ${VERSION} --ownership recommended ../libfguid-${VERSION}.pkg

