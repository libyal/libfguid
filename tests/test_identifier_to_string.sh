#!/bin/bash
# Library GUID/UUID identifier to string testing script
#
# Version: 20160217

EXIT_SUCCESS=0;
EXIT_FAILURE=1;
EXIT_IGNORE=77;

TEST_PREFIX=`pwd`;
TEST_PREFIX=`dirname ${TEST_PREFIX}`;
TEST_PREFIX=`basename ${TEST_PREFIX} | sed 's/^lib//'`;

test_to_string()
{
	echo "Testing GUID/UUID identifier to string function";

	TMPDIR="tmp$$";

	rm -rf ${TMPDIR};
	mkdir ${TMPDIR};

	${TEST_RUNNER} ${TMPDIR} ${TEST_TO_STRING};

	RESULT=$?;

	rm -rf ${TMPDIR};

	echo "";

	return ${RESULT};
}

if ! test -z ${SKIP_LIBRARY_TESTS};
then
	exit ${EXIT_IGNORE};
fi

TEST_TO_STRING="./${TEST_PREFIX}_test_identifier_to_string";

if ! test -x ${TEST_TO_STRING};
then
	TEST_TO_STRING="${TEST_PREFIX}_test_identifier_to_string.exe";
fi

if ! test -x ${TEST_TO_STRING};
then
	echo "Missing executable: ${TEST_TO_STRING}";

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

if ! test_to_string;
then
	exit ${EXIT_FAILURE};
fi

exit ${EXIT_SUCCESS};

