/*
 * Library identifier type test program
 *
 * Copyright (C) 2010-2017, Joachim Metz <joachim.metz@gmail.com>
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
#include <file_stream.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "fguid_test_libfguid.h"
#include "fguid_test_libcerror.h"
#include "fguid_test_macros.h"
#include "fguid_test_memory.h"
#include "fguid_test_unused.h"

uint8_t fguid_test_identifier_byte_stream[ 16 ] = {
	0xba, 0x8f, 0x0d, 0x45, 0x25, 0xad, 0xd0, 0x11, 0x98, 0xa8, 0x08, 0x00, 0x36, 0x1b, 0x11, 0x03 };

uint8_t *fguid_test_identifier_utf8_string_lower = \
	(uint8_t *) "450d8fba-ad25-11d0-98a8-0800361b1103";

uint8_t *fguid_test_identifier_utf8_string_lower_with_braces = \
	(uint8_t *) "{450d8fba-ad25-11d0-98a8-0800361b1103}";

uint8_t *fguid_test_identifier_utf8_string_mixed = \
	(uint8_t *) "450D8FBA-ad25-11D0-98a8-0800361B1103";

uint8_t *fguid_test_identifier_utf8_string_upper = \
	(uint8_t *) "450D8FBA-AD25-11D0-98A8-0800361B1103";

/* Tests the libfguid_identifier_initialize function
 * Returns 1 if successful or 0 if not
 */
int fguid_test_identifier_initialize(
     void )
{
	libcerror_error_t *error          = NULL;
	libfguid_identifier_t *identifier = NULL;
	int result                        = 0;

#if defined( HAVE_FGUID_TEST_MEMORY )
	int number_of_malloc_fail_tests   = 1;
	int number_of_memset_fail_tests   = 1;
	int test_number                   = 0;
#endif

	/* Test regular cases
	 */
	result = libfguid_identifier_initialize(
	          &identifier,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
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

	FGUID_TEST_ASSERT_EQUAL_INT(
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

	FGUID_TEST_ASSERT_EQUAL_INT(
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

	FGUID_TEST_ASSERT_EQUAL_INT(
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

	for( test_number = 0;
	     test_number < number_of_malloc_fail_tests;
	     test_number++ )
	{
		/* Test libfguid_identifier_initialize with malloc failing
		 */
		fguid_test_malloc_attempts_before_fail = test_number;

		result = libfguid_identifier_initialize(
		          &identifier,
		          &error );

		if( fguid_test_malloc_attempts_before_fail != -1 )
		{
			fguid_test_malloc_attempts_before_fail = -1;

			if( identifier != NULL )
			{
				libfguid_identifier_free(
				 &identifier,
				 NULL );
			}
		}
		else
		{
			FGUID_TEST_ASSERT_EQUAL_INT(
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
	}
	for( test_number = 0;
	     test_number < number_of_memset_fail_tests;
	     test_number++ )
	{
		/* Test libfguid_identifier_initialize with memset failing
		 */
		fguid_test_memset_attempts_before_fail = test_number;

		result = libfguid_identifier_initialize(
		          &identifier,
		          &error );

		if( fguid_test_memset_attempts_before_fail != -1 )
		{
			fguid_test_memset_attempts_before_fail = -1;

			if( identifier != NULL )
			{
				libfguid_identifier_free(
				 &identifier,
				 NULL );
			}
		}
		else
		{
			FGUID_TEST_ASSERT_EQUAL_INT(
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

	FGUID_TEST_ASSERT_EQUAL_INT(
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

/* Tests the libfguid_identifier_copy_from_byte_stream function
 * Returns 1 if successful or 0 if not
 */
int fguid_test_identifier_copy_from_byte_stream(
     void )
{
	libcerror_error_t *error          = NULL;
	libfguid_identifier_t *identifier = NULL;
	int result                        = 0;

	/* Initialize test
	 */
	result = libfguid_identifier_initialize(
	          &identifier,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "identifier",
	 identifier );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test copy from byte stream
	 */
	result = libfguid_identifier_copy_from_byte_stream(
	          identifier,
	          fguid_test_identifier_byte_stream,
	          16,
	          LIBFGUID_ENDIAN_BIG,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfguid_identifier_copy_from_byte_stream(
	          identifier,
	          fguid_test_identifier_byte_stream,
	          16,
	          LIBFGUID_ENDIAN_LITTLE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfguid_identifier_copy_from_byte_stream(
	          NULL,
	          fguid_test_identifier_byte_stream,
	          16,
	          LIBFGUID_ENDIAN_LITTLE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfguid_identifier_copy_from_byte_stream(
	          identifier,
	          NULL,
	          16,
	          LIBFGUID_ENDIAN_LITTLE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfguid_identifier_copy_from_byte_stream(
	          identifier,
	          fguid_test_identifier_byte_stream,
	          (size_t) SSIZE_MAX + 1,
	          LIBFGUID_ENDIAN_LITTLE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfguid_identifier_copy_from_byte_stream(
	          identifier,
	          fguid_test_identifier_byte_stream,
	          16,
	          (uint8_t) 'X',
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Byte stream too small
	 */
	result = libfguid_identifier_copy_from_byte_stream(
	          identifier,
	          fguid_test_identifier_byte_stream,
	          0,
	          LIBFGUID_ENDIAN_LITTLE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Byte stream too small
	 */
	result = libfguid_identifier_copy_from_byte_stream(
	          identifier,
	          fguid_test_identifier_byte_stream,
	          8,
	          LIBFGUID_ENDIAN_LITTLE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfguid_identifier_free(
	          &identifier,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_IS_NULL(
	 "identifier",
	 identifier );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

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

/* Tests the libfguid_identifier_copy_from_utf8_string function
 * Returns 1 if successful or 0 if not
 */
int fguid_test_identifier_copy_from_utf8_string(
     void )
{
	libcerror_error_t *error          = NULL;
	libfguid_identifier_t *identifier = NULL;
	int result                        = 0;

	/* Initialize test
	 */
	result = libfguid_identifier_initialize(
	          &identifier,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "identifier",
	 identifier );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test copy from UTF-8 string
	 */
	result = libfguid_identifier_copy_from_utf8_string(
	          identifier,
	          fguid_test_identifier_utf8_string_lower,
	          36,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfguid_identifier_copy_from_utf8_string(
	          identifier,
	          fguid_test_identifier_utf8_string_upper,
	          36,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_UPPER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfguid_identifier_copy_from_utf8_string(
	          identifier,
	          fguid_test_identifier_utf8_string_mixed,
	          36,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_MIXED_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfguid_identifier_copy_from_utf8_string(
	          identifier,
	          fguid_test_identifier_utf8_string_lower_with_braces,
	          38,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE | LIBFGUID_STRING_FORMAT_FLAG_USE_SURROUNDING_BRACES,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfguid_identifier_copy_from_utf8_string(
	          NULL,
	          fguid_test_identifier_utf8_string_lower,
	          36,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfguid_identifier_copy_from_utf8_string(
	          identifier,
	          NULL,
	          36,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfguid_identifier_copy_from_utf8_string(
	          identifier,
	          fguid_test_identifier_utf8_string_lower,
	          (size_t) SSIZE_MAX + 1,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfguid_identifier_copy_from_utf8_string(
	          identifier,
	          fguid_test_identifier_utf8_string_lower,
	          36,
	          0xffffffffUL,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* UTF-8 string too small
	 */
	result = libfguid_identifier_copy_from_utf8_string(
	          identifier,
	          fguid_test_identifier_utf8_string_lower,
	          12,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Incorrect case
	 */
	result = libfguid_identifier_copy_from_utf8_string(
	          identifier,
	          fguid_test_identifier_utf8_string_mixed,
	          36,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_UPPER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfguid_identifier_free(
	          &identifier,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_IS_NULL(
	 "identifier",
	 identifier );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

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

/* Tests the libfguid_identifier_copy_to_utf8_string function
 * Returns 1 if successful or 0 if not
 */
int fguid_test_identifier_copy_to_utf8_string(
     void )
{
	uint8_t utft8_string[ 48 ];

	libcerror_error_t *error          = NULL;
	libfguid_identifier_t *identifier = NULL;
	int result                        = 0;

	/* Initialize test
	 */
	result = libfguid_identifier_initialize(
	          &identifier,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "identifier",
	 identifier );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfguid_identifier_copy_from_byte_stream(
	          identifier,
	          fguid_test_identifier_byte_stream,
	          16,
	          LIBFGUID_ENDIAN_LITTLE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test copy to UTF-8 string
	 */
	result = libfguid_identifier_copy_to_utf8_string(
	          identifier,
	          utft8_string,
	          37,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

/* TODO compare string */

	result = libfguid_identifier_copy_to_utf8_string(
	          identifier,
	          utft8_string,
	          37,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_UPPER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

/* TODO compare string */

	result = libfguid_identifier_copy_to_utf8_string(
	          identifier,
	          utft8_string,
	          39,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_UPPER_CASE | LIBFGUID_STRING_FORMAT_FLAG_USE_SURROUNDING_BRACES,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

/* TODO compare string */

	/* Test error cases
	 */
	result = libfguid_identifier_copy_to_utf8_string(
	          NULL,
	          utft8_string,
	          37,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfguid_identifier_copy_to_utf8_string(
	          identifier,
	          NULL,
	          37,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfguid_identifier_copy_to_utf8_string(
	          identifier,
	          utft8_string,
	          (size_t) SSIZE_MAX + 1,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfguid_identifier_copy_to_utf8_string(
	          identifier,
	          utft8_string,
	          37,
	          0xffffffffUL,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* UTF-8 string too small
	 */
	result = libfguid_identifier_copy_to_utf8_string(
	          identifier,
	          utft8_string,
	          0,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* UTF-8 string too small
	 */
	result = libfguid_identifier_copy_to_utf8_string(
	          identifier,
	          utft8_string,
	          18,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfguid_identifier_free(
	          &identifier,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_IS_NULL(
	 "identifier",
	 identifier );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

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

/* Tests the libfguid_identifier_copy_to_utf16_string function
 * Returns 1 if successful or 0 if not
 */
int fguid_test_identifier_copy_to_utf16_string(
     void )
{
	uint16_t utft16_string[ 48 ];

	libcerror_error_t *error          = NULL;
	libfguid_identifier_t *identifier = NULL;
	int result                        = 0;

	/* Initialize test
	 */
	result = libfguid_identifier_initialize(
	          &identifier,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "identifier",
	 identifier );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfguid_identifier_copy_from_byte_stream(
	          identifier,
	          fguid_test_identifier_byte_stream,
	          16,
	          LIBFGUID_ENDIAN_LITTLE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test copy to UTF-16 string
	 */
	result = libfguid_identifier_copy_to_utf16_string(
	          identifier,
	          utft16_string,
	          37,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

/* TODO compare string */

	result = libfguid_identifier_copy_to_utf16_string(
	          identifier,
	          utft16_string,
	          37,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_UPPER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

/* TODO compare string */

	result = libfguid_identifier_copy_to_utf16_string(
	          identifier,
	          utft16_string,
	          39,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_UPPER_CASE | LIBFGUID_STRING_FORMAT_FLAG_USE_SURROUNDING_BRACES,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

/* TODO compare string */

	/* Test error cases
	 */
	result = libfguid_identifier_copy_to_utf16_string(
	          NULL,
	          utft16_string,
	          37,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfguid_identifier_copy_to_utf16_string(
	          identifier,
	          NULL,
	          37,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfguid_identifier_copy_to_utf16_string(
	          identifier,
	          utft16_string,
	          (size_t) SSIZE_MAX + 1,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfguid_identifier_copy_to_utf16_string(
	          identifier,
	          utft16_string,
	          37,
	          0xffffffffUL,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* UTF-16 string too small
	 */
	result = libfguid_identifier_copy_to_utf16_string(
	          identifier,
	          utft16_string,
	          0,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* UTF-16 string too small
	 */
	result = libfguid_identifier_copy_to_utf16_string(
	          identifier,
	          utft16_string,
	          18,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfguid_identifier_free(
	          &identifier,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_IS_NULL(
	 "identifier",
	 identifier );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

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

/* Tests the libfguid_identifier_copy_to_utf32_string function
 * Returns 1 if successful or 0 if not
 */
int fguid_test_identifier_copy_to_utf32_string(
     void )
{
	uint32_t utft32_string[ 48 ];

	libcerror_error_t *error          = NULL;
	libfguid_identifier_t *identifier = NULL;
	int result                        = 0;

	/* Initialize test
	 */
	result = libfguid_identifier_initialize(
	          &identifier,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "identifier",
	 identifier );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfguid_identifier_copy_from_byte_stream(
	          identifier,
	          fguid_test_identifier_byte_stream,
	          16,
	          LIBFGUID_ENDIAN_LITTLE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test copy to UTF-32 string
	 */
	result = libfguid_identifier_copy_to_utf32_string(
	          identifier,
	          utft32_string,
	          37,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

/* TODO compare string */

	result = libfguid_identifier_copy_to_utf32_string(
	          identifier,
	          utft32_string,
	          37,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_UPPER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

/* TODO compare string */

	result = libfguid_identifier_copy_to_utf32_string(
	          identifier,
	          utft32_string,
	          39,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_UPPER_CASE | LIBFGUID_STRING_FORMAT_FLAG_USE_SURROUNDING_BRACES,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

/* TODO compare string */

	/* Test error cases
	 */
	result = libfguid_identifier_copy_to_utf32_string(
	          NULL,
	          utft32_string,
	          37,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfguid_identifier_copy_to_utf32_string(
	          identifier,
	          NULL,
	          37,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfguid_identifier_copy_to_utf32_string(
	          identifier,
	          utft32_string,
	          (size_t) SSIZE_MAX + 1,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfguid_identifier_copy_to_utf32_string(
	          identifier,
	          utft32_string,
	          37,
	          0xffffffffUL,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* UTF-32 string too small
	 */
	result = libfguid_identifier_copy_to_utf32_string(
	          identifier,
	          utft32_string,
	          0,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* UTF-32 string too small
	 */
	result = libfguid_identifier_copy_to_utf32_string(
	          identifier,
	          utft32_string,
	          18,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfguid_identifier_free(
	          &identifier,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_IS_NULL(
	 "identifier",
	 identifier );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

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
	 "libfguid_identifier_initialize",
	 fguid_test_identifier_initialize );

	FGUID_TEST_RUN(
	 "libfguid_identifier_free",
	 fguid_test_identifier_free );

	FGUID_TEST_RUN(
	 "libfguid_identifier_copy_from_byte_stream",
	 fguid_test_identifier_copy_from_byte_stream );

	/* TODO: add test for libfguid_identifier_copy_to_byte_stream */
	/* TODO: add test for libfguid_identifier_get_string_size */

	FGUID_TEST_RUN(
	 "libfguid_identifier_copy_from_utf8_string",
	 fguid_test_identifier_copy_from_utf8_string );

	/* TODO: add test for libfguid_identifier_copy_from_utf8_string_with_index */

	FGUID_TEST_RUN(
	 "libfguid_identifier_copy_to_utf8_string",
	 fguid_test_identifier_copy_to_utf8_string );

	/* TODO: add test for libfguid_identifier_copy_to_utf8_string_with_index */

	/* TODO: add test for libfguid_identifier_copy_from_utf16_string */
	/* TODO: add test for libfguid_identifier_copy_from_utf16_string_with_index */

	FGUID_TEST_RUN(
	 "libfguid_identifier_copy_to_utf16_string",
	 fguid_test_identifier_copy_to_utf16_string );

	/* TODO: add test for libfguid_identifier_copy_to_utf16_string_with_index */

	/* TODO: add test for libfguid_identifier_copy_from_utf32_string */
	/* TODO: add test for libfguid_identifier_copy_from_utf32_string_with_index */

	FGUID_TEST_RUN(
	 "libfguid_identifier_copy_to_utf32_string",
	 fguid_test_identifier_copy_to_utf32_string );

	/* TODO: add test for libfguid_identifier_copy_to_utf32_string_with_index */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

