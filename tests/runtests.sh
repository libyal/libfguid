#!/bin/sh
# Script to run tests
#
# Version: 20260609

if test -f ${PWD}/libfguid/.libs/libfguid.1.dylib && test -f ./pyfguid/.libs/pyfguid.so
then
	install_name_tool -change /usr/local/lib/libfguid.1.dylib ${PWD}/libfguid/.libs/libfguid.1.dylib ./pyfguid/.libs/pyfguid.so
fi

make check-build > /dev/null

make check $@
RESULT=$?

if test ${RESULT} -ne 0
then
	find . -name \*.log -path \*.dir/\*/\*.log -print -exec cat {} \;
fi
exit ${RESULT}

