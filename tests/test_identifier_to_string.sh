#!/bin/bash
#
# GUID/UUID library identifier to string testing script
#
# Copyright (C) 2010-2015, Joachim Metz <joachim.metz@gmail.com>
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

test_identifier_to_string()
{ 
	rm -rf tmp;
	mkdir tmp;

	echo "Testing identifier to string function";

	${TEST_RUNNER} ./${FGUID_TEST_IDENTIFIER_TO_STRING};

	RESULT=$?;

	rm -rf tmp;

	echo "";

	return ${RESULT};
}

FGUID_TEST_IDENTIFIER_TO_STRING="fguid_test_identifier_to_string";

if ! test -x ${FGUID_TEST_IDENTIFIER_TO_STRING};
then
	FGUID_TEST_IDENTIFIER_TO_STRING="fguid_test_identifier_to_string.exe";
fi

if ! test -x ${FGUID_TEST_IDENTIFIER_TO_STRING};
then
	echo "Missing executable: ${FGUID_TEST_IDENTIFIER_TO_STRING}";

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

if ! test_identifier_to_string;
then
	exit ${EXIT_FAILURE};
fi

exit ${EXIT_SUCCESS};

