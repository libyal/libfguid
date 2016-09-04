/*
 * Library identifier type testing program
 *
 * Copyright (C) 2010-2016, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <common.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "fguid_test_libfguid.h"
#include "fguid_test_libcerror.h"
#include "fguid_test_libcstring.h"
#include "fguid_test_macros.h"
#include "fguid_test_memory.h"
#include "fguid_test_unused.h"

/* Tests the libfguid_identifier_initialize function
 * Returns 1 if successful or 0 if not
 */
int fguid_test_identifier_initialize(
     void )
{
	libfguid_identifier_t *identifier = NULL;
	libcerror_error_t *error          = NULL;
	int result                        = 0;

	/* Test libfguid_identifier_initialize without entries
	 */
	result = libfguid_identifier_initialize(
	          &identifier,
	          &error );

	FGUID_TEST_ASSERT_EQUAL(
	 "result",
	 result,
	 1 );

        FGUID_TEST_ASSERT_IS_NOT_NULL(
         "identifier",
         identifier );

        FGUID_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libfguid_identifier_free(
	          &identifier,
	          &error );

	FGUID_TEST_ASSERT_EQUAL(
	 "result",
	 result,
	 1 );

        FGUID_TEST_ASSERT_IS_NULL(
         "identifier",
         identifier );

        FGUID_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libfguid_identifier_initialize(
	          NULL,
	          &error );

	FGUID_TEST_ASSERT_EQUAL(
	 "result",
	 result,
	 -1 );

        FGUID_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	identifier = (libfguid_identifier_t *) 0x12345678UL;

	result = libfguid_identifier_initialize(
	          &identifier,
	          &error );

	FGUID_TEST_ASSERT_EQUAL(
	 "result",
	 result,
	 -1 );

        FGUID_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	identifier = NULL;

#if defined( HAVE_FGUID_TEST_MEMORY )

	/* Test libfguid_identifier_initialize with malloc failing
	 */
	fguid_test_malloc_attempts_before_fail = 0;

	result = libfguid_identifier_initialize(
	          &identifier,
	          &error );

	if( fguid_test_malloc_attempts_before_fail != -1 )
	{
		fguid_test_malloc_attempts_before_fail = -1;
	}
	else
	{
		FGUID_TEST_ASSERT_EQUAL(
		 "result",
		 result,
		 -1 );

		FGUID_TEST_ASSERT_IS_NULL(
		 "identifier",
		 identifier );

		FGUID_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Test libfguid_identifier_initialize with memset failing
	 */
	fguid_test_memset_attempts_before_fail = 0;

	result = libfguid_identifier_initialize(
	          &identifier,
	          &error );

	if( fguid_test_memset_attempts_before_fail != -1 )
	{
		fguid_test_memset_attempts_before_fail = -1;
	}
	else
	{
		FGUID_TEST_ASSERT_EQUAL(
		 "result",
		 result,
		 -1 );

		FGUID_TEST_ASSERT_IS_NULL(
		 "identifier",
		 identifier );

		FGUID_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
#endif /* defined( HAVE_FGUID_TEST_MEMORY ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( identifier != NULL )
	{
		libfguid_identifier_free(
		 &identifier,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfguid_identifier_free function
 * Returns 1 if successful or 0 if not
 */
int fguid_test_identifier_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libfguid_identifier_free(
	          NULL,
	          &error );

	FGUID_TEST_ASSERT_EQUAL(
	 "result",
	 result,
	 -1 );

        FGUID_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* The main program
 */
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
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
	 "libfguid_identifier_initialize",
	 fguid_test_identifier_initialize() )

	FGUID_TEST_RUN(
	 "libfguid_identifier_free",
	 fguid_test_identifier_free() )

	/* TODO: add test for libfguid_identifier_copy_from_byte_stream */
	/* TODO: add test for libfguid_identifier_copy_to_byte_stream */
	/* TODO: add test for libfguid_identifier_get_string_size */

	/* TODO: add test for libfguid_identifier_copy_from_utf8_string */
	/* TODO: add test for libfguid_identifier_copy_from_utf8_string_with_index */
	/* TODO: add test for libfguid_identifier_copy_to_utf8_string */
	/* TODO: add test for libfguid_identifier_copy_to_utf8_string_with_index */

	/* TODO: add test for libfguid_identifier_copy_from_utf16_string */
	/* TODO: add test for libfguid_identifier_copy_from_utf16_string_with_index */
	/* TODO: add test for libfguid_identifier_copy_to_utf16_string */
	/* TODO: add test for libfguid_identifier_copy_to_utf16_string_with_index */

	/* TODO: add test for libfguid_identifier_copy_from_utf32_string */
	/* TODO: add test for libfguid_identifier_copy_from_utf32_string_with_index */
	/* TODO: add test for libfguid_identifier_copy_to_utf32_string */
	/* TODO: add test for libfguid_identifier_copy_to_utf32_string_with_index */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

