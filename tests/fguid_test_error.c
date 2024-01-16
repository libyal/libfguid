/*
 * Library error functions test program
 *
 * Copyright (C) 2010-2024, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <file_stream.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "fguid_test_libfguid.h"
#include "fguid_test_macros.h"
#include "fguid_test_unused.h"

/* Tests the libfguid_error_free function
 * Returns 1 if successful or 0 if not
 */
int fguid_test_error_free(
     void )
{
	/* Test invocation of function only
	 */
	libfguid_error_free(
	 NULL );

	return( 1 );
}

/* Tests the libfguid_error_fprint function
 * Returns 1 if successful or 0 if not
 */
int fguid_test_error_fprint(
     void )
{
	/* Test invocation of function only
	 */
	libfguid_error_fprint(
	 NULL,
	 NULL );

	return( 1 );
}

/* Tests the libfguid_error_sprint function
 * Returns 1 if successful or 0 if not
 */
int fguid_test_error_sprint(
     void )
{
	/* Test invocation of function only
	 */
	libfguid_error_sprint(
	 NULL,
	 NULL,
	 0 );

	return( 1 );
}

/* Tests the libfguid_error_backtrace_fprint function
 * Returns 1 if successful or 0 if not
 */
int fguid_test_error_backtrace_fprint(
     void )
{
	/* Test invocation of function only
	 */
	libfguid_error_backtrace_fprint(
	 NULL,
	 NULL );

	return( 1 );
}

/* Tests the libfguid_error_backtrace_sprint function
 * Returns 1 if successful or 0 if not
 */
int fguid_test_error_backtrace_sprint(
     void )
{
	/* Test invocation of function only
	 */
	libfguid_error_backtrace_sprint(
	 NULL,
	 NULL,
	 0 );

	return( 1 );
}

/* The main program
 */
#if defined( HAVE_WIDE_SYSTEM_CHARACTER )
int wmain(
     int argc FGUID_TEST_ATTRIBUTE_UNUSED,
     wchar_t * const argv[] FGUID_TEST_ATTRIBUTE_UNUSED )
#else
int main(
     int argc FGUID_TEST_ATTRIBUTE_UNUSED,
     char * const argv[] FGUID_TEST_ATTRIBUTE_UNUSED )
#endif
{
	FGUID_TEST_UNREFERENCED_PARAMETER( argc )
	FGUID_TEST_UNREFERENCED_PARAMETER( argv )

	FGUID_TEST_RUN(
	 "libfguid_error_free",
	 fguid_test_error_free );

	FGUID_TEST_RUN(
	 "libfguid_error_fprint",
	 fguid_test_error_fprint );

	FGUID_TEST_RUN(
	 "libfguid_error_sprint",
	 fguid_test_error_sprint );

	FGUID_TEST_RUN(
	 "libfguid_error_backtrace_fprint",
	 fguid_test_error_backtrace_fprint );

	FGUID_TEST_RUN(
	 "libfguid_error_backtrace_sprint",
	 fguid_test_error_backtrace_sprint );

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

