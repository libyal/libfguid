#!/bin/sh
# Script to run tests
#
# Version: 20260714

if [ -f "${PWD}/libfguid/.libs/libfguid.1.dylib" ] && [ -f ./pyfguid/.libs/pyfguid.so ]
then
    install_name_tool -change /usr/local/lib/libfguid.1.dylib "${PWD}/libfguid/.libs/libfguid.1.dylib" ./pyfguid/.libs/pyfguid.so
fi

make check-build > /dev/null

# shellcheck disable=SC2068
make check $@
RESULT=$?

if [ ${RESULT} -ne 0 ]
then
    find . -name \*.log -path \*.dir/\*/\*.log -print -exec cat {} \;
fi
exit ${RESULT}

