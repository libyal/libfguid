#!/bin/sh
# Script to run tests
#
# Version: 20201121

if test -f ${PWD}/libfguid/.libs/libfguid.1.dylib && test -f ./pyfguid/.libs/pyfguid.so;
then
	install_name_tool -change /usr/local/lib/libfguid.1.dylib ${PWD}/libfguid/.libs/libfguid.1.dylib ./pyfguid/.libs/pyfguid.so;
fi

make check CHECK_WITH_STDERR=1;
RESULT=$?;

if test ${RESULT} -ne 0 && test -f tests/test-suite.log;
then
	cat tests/test-suite.log;
fi
exit ${RESULT};

