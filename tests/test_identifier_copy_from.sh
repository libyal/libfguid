#!/bin/bash
#
# GUID/UUID library identifier copy from testing script
#
# Copyright (c) 2010-2014, Joachim Metz <joachim.metz@gmail.com>
#
# Refer to AUTHORS for acknowledgements.
#
# This software is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This software is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this software.  If not, see <http://www.gnu.org/licenses/>.
#

EXIT_SUCCESS=0;
EXIT_FAILURE=1;
EXIT_IGNORE=77;

test_identifier_copy_from()
{ 
	rm -rf tmp;
	mkdir tmp;

	echo "Testing identifier copy from function";

	${TEST_RUNNER} ./${FGUID_TEST_IDENTIFIER_COPY_FROM};

	RESULT=$?;

	rm -rf tmp;

	echo "";

	return ${RESULT};
}

FGUID_TEST_IDENTIFIER_COPY_FROM="fguid_test_identifier_copy_from";

if ! test -x ${FGUID_TEST_IDENTIFIER_COPY_FROM};
then
	FGUID_TEST_IDENTIFIER_COPY_FROM="fguid_test_identifier_copy_from.exe";
fi

if ! test -x ${FGUID_TEST_IDENTIFIER_COPY_FROM};
then
	echo "Missing executable: ${FGUID_TEST_IDENTIFIER_COPY_FROM}";

	exit ${EXIT_FAILURE};
fi

TEST_RUNNER="tests/test_runner.sh";

if ! test -x ${TEST_RUNNER};
then
	TEST_RUNNER="./test_runner.sh";
fi

if ! test -x ${TEST_RUNNER};
then
	echo "Missing test runner: ${TEST_RUNNER}";

	exit ${EXIT_FAILURE};
fi

if ! test_identifier_copy_from;
then
	exit ${EXIT_FAILURE};
fi

exit ${EXIT_SUCCESS};

