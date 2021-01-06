/*
 * Library identifier type test program
 *
 * Copyright (C) 2010-2021, Joachim Metz <joachim.metz@gmail.com>
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
#include <memory.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "fguid_test_libfguid.h"
#include "fguid_test_libcerror.h"
#include "fguid_test_macros.h"
#include "fguid_test_memory.h"
#include "fguid_test_unused.h"

#include "../libfguid/libfguid_identifier.h"

uint8_t fguid_test_identifier_byte_stream[ 16 ] = {
	0xba, 0x8f, 0x0d, 0x45, 0x25, 0xad, 0xd0, 0x11, 0x9b, 0xa8, 0x08, 0x00, 0x36, 0x1b, 0x11, 0x03 };

uint8_t *fguid_test_identifier_utf8_string_lower = \
	(uint8_t *) "450d8fba-ad25-11d0-9ba8-0800361b1103";

uint8_t *fguid_test_identifier_utf8_string_lower_with_braces = \
	(uint8_t *) "{450d8fba-ad25-11d0-9ba8-0800361b1103}";

uint8_t *fguid_test_identifier_utf8_string_mixed = \
	(uint8_t *) "450D8FBA-ad25-11D0-9ba8-0800361B1103";

uint8_t *fguid_test_identifier_utf8_string_upper = \
	(uint8_t *) "450D8FBA-AD25-11D0-9BA8-0800361B1103";

uint8_t *fguid_test_identifier_utf8_string_lower_with_invalid_first_brace = \
	(uint8_t *) "[450d8fba-ad25-11d0-9ba8-0800361b1103}";

uint8_t *fguid_test_identifier_utf8_string_lower_with_invalid_last_brace = \
	(uint8_t *) "{450d8fba-ad25-11d0-9ba8-0800361b1103]";

uint8_t *fguid_test_identifier_utf8_string_lower_with_invalid_first_separator = \
	(uint8_t *) "450d8fba_ad25-11d0-9ba8-0800361b1103";

uint8_t *fguid_test_identifier_utf8_string_lower_with_invalid_second_separator = \
	(uint8_t *) "450d8fba-ad25_11d0-9ba8-0800361b1103";

uint8_t *fguid_test_identifier_utf8_string_lower_with_invalid_third_separator = \
	(uint8_t *) "450d8fba-ad25-11d0_9ba8-0800361b1103";

uint8_t *fguid_test_identifier_utf8_string_lower_with_invalid_fourth_separator = \
	(uint8_t *) "450d8fba-ad25-11d0-9ba8_0800361b1103";

uint16_t fguid_test_identifier_utf16_string_lower[ 36 ] = {
	0x34, 0x35, 0x30, 0x64, 0x38, 0x66, 0x62, 0x61, 0x2d, 0x61, 0x64, 0x32, 0x35, 0x2d, 0x31, 0x31, 
	0x64, 0x30, 0x2d, 0x39, 0x62, 0x61, 0x38, 0x2d, 0x30, 0x38, 0x30, 0x30, 0x33, 0x36, 0x31, 0x62, 
	0x31, 0x31, 0x30, 0x33 };

uint16_t fguid_test_identifier_utf16_string_lower_with_braces[ 38 ] = {
	0x7b, 0x34, 0x35, 0x30, 0x64, 0x38, 0x66, 0x62, 0x61, 0x2d, 0x61, 0x64, 0x32, 0x35, 0x2d, 0x31, 
	0x31, 0x64, 0x30, 0x2d, 0x39, 0x62, 0x61, 0x38, 0x2d, 0x30, 0x38, 0x30, 0x30, 0x33, 0x36, 0x31, 
	0x62, 0x31, 0x31, 0x30, 0x33, 0x7d };

uint16_t fguid_test_identifier_utf16_string_mixed[ 36 ] = {
	0x34, 0x35, 0x30, 0x44, 0x38, 0x46, 0x42, 0x41, 0x2d, 0x61, 0x64, 0x32, 0x35, 0x2d, 0x31, 0x31,
	0x44, 0x30, 0x2d, 0x39, 0x62, 0x61, 0x38, 0x2d, 0x30, 0x38, 0x30, 0x30, 0x33, 0x36, 0x31, 0x42,
	0x31, 0x31, 0x30, 0x33 };

uint16_t fguid_test_identifier_utf16_string_upper[ 36 ] = {
	0x34, 0x35, 0x30, 0x44, 0x38, 0x46, 0x42, 0x41, 0x2d, 0x41, 0x44, 0x32, 0x35, 0x2d, 0x31, 0x31,
	0x44, 0x30, 0x2d, 0x39, 0x42, 0x41, 0x38, 0x2d, 0x30, 0x38, 0x30, 0x30, 0x33, 0x36, 0x31, 0x42,
	0x31, 0x31, 0x30, 0x33 };

uint16_t fguid_test_identifier_utf16_string_lower_with_invalid_first_brace[ 38 ] = {
	0x5b, 0x34, 0x35, 0x30, 0x64, 0x38, 0x66, 0x62, 0x61, 0x2d, 0x61, 0x64, 0x32, 0x35, 0x2d, 0x31, 
	0x31, 0x64, 0x30, 0x2d, 0x39, 0x62, 0x61, 0x38, 0x2d, 0x30, 0x38, 0x30, 0x30, 0x33, 0x36, 0x31, 
	0x62, 0x31, 0x31, 0x30, 0x33, 0x7d };

uint16_t fguid_test_identifier_utf16_string_lower_with_invalid_last_brace[ 38 ] = {
	0x7b, 0x34, 0x35, 0x30, 0x64, 0x38, 0x66, 0x62, 0x61, 0x2d, 0x61, 0x64, 0x32, 0x35, 0x2d, 0x31, 
	0x31, 0x64, 0x30, 0x2d, 0x39, 0x62, 0x61, 0x38, 0x2d, 0x30, 0x38, 0x30, 0x30, 0x33, 0x36, 0x31, 
	0x62, 0x31, 0x31, 0x30, 0x33, 0x5d };

uint16_t fguid_test_identifier_utf16_string_lower_with_invalid_first_separator[ 36 ] = {
	0x34, 0x35, 0x30, 0x64, 0x38, 0x66, 0x62, 0x61, 0x5f, 0x61, 0x64, 0x32, 0x35, 0x2d, 0x31, 0x31, 
	0x64, 0x30, 0x2d, 0x39, 0x62, 0x61, 0x38, 0x2d, 0x30, 0x38, 0x30, 0x30, 0x33, 0x36, 0x31, 0x62, 
	0x31, 0x31, 0x30, 0x33 };

uint16_t fguid_test_identifier_utf16_string_lower_with_invalid_second_separator[ 36 ] = {
	0x34, 0x35, 0x30, 0x64, 0x38, 0x66, 0x62, 0x61, 0x2d, 0x61, 0x64, 0x32, 0x35, 0x5f, 0x31, 0x31, 
	0x64, 0x30, 0x2d, 0x39, 0x62, 0x61, 0x38, 0x2d, 0x30, 0x38, 0x30, 0x30, 0x33, 0x36, 0x31, 0x62, 
	0x31, 0x31, 0x30, 0x33 };

uint16_t fguid_test_identifier_utf16_string_lower_with_invalid_third_separator[ 36 ] = {
	0x34, 0x35, 0x30, 0x64, 0x38, 0x66, 0x62, 0x61, 0x2d, 0x61, 0x64, 0x32, 0x35, 0x2d, 0x31, 0x31, 
	0x64, 0x30, 0x5f, 0x39, 0x62, 0x61, 0x38, 0x2d, 0x30, 0x38, 0x30, 0x30, 0x33, 0x36, 0x31, 0x62, 
	0x31, 0x31, 0x30, 0x33 };

uint16_t fguid_test_identifier_utf16_string_lower_with_invalid_fourth_separator[ 36 ] = {
	0x34, 0x35, 0x30, 0x64, 0x38, 0x66, 0x62, 0x61, 0x2d, 0x61, 0x64, 0x32, 0x35, 0x2d, 0x31, 0x31, 
	0x64, 0x30, 0x2d, 0x39, 0x62, 0x61, 0x38, 0x5f, 0x30, 0x38, 0x30, 0x30, 0x33, 0x36, 0x31, 0x62, 
	0x31, 0x31, 0x30, 0x33 };

uint32_t fguid_test_identifier_utf32_string_lower[ 36 ] = {
	0x34, 0x35, 0x30, 0x64, 0x38, 0x66, 0x62, 0x61, 0x2d, 0x61, 0x64, 0x32, 0x35, 0x2d, 0x31, 0x31, 
	0x64, 0x30, 0x2d, 0x39, 0x62, 0x61, 0x38, 0x2d, 0x30, 0x38, 0x30, 0x30, 0x33, 0x36, 0x31, 0x62, 
	0x31, 0x31, 0x30, 0x33 };

uint32_t fguid_test_identifier_utf32_string_lower_with_braces[ 38 ] = {
	0x7b, 0x34, 0x35, 0x30, 0x64, 0x38, 0x66, 0x62, 0x61, 0x2d, 0x61, 0x64, 0x32, 0x35, 0x2d, 0x31, 
	0x31, 0x64, 0x30, 0x2d, 0x39, 0x62, 0x61, 0x38, 0x2d, 0x30, 0x38, 0x30, 0x30, 0x33, 0x36, 0x31, 
	0x62, 0x31, 0x31, 0x30, 0x33, 0x7d };

uint32_t fguid_test_identifier_utf32_string_mixed[ 36 ] = {
	0x34, 0x35, 0x30, 0x44, 0x38, 0x46, 0x42, 0x41, 0x2d, 0x61, 0x64, 0x32, 0x35, 0x2d, 0x31, 0x31,
	0x44, 0x30, 0x2d, 0x39, 0x62, 0x61, 0x38, 0x2d, 0x30, 0x38, 0x30, 0x30, 0x33, 0x36, 0x31, 0x42,
	0x31, 0x31, 0x30, 0x33 };

uint32_t fguid_test_identifier_utf32_string_upper[ 36 ] = {
	0x34, 0x35, 0x30, 0x44, 0x38, 0x46, 0x42, 0x41, 0x2d, 0x41, 0x44, 0x32, 0x35, 0x2d, 0x31, 0x31,
	0x44, 0x30, 0x2d, 0x39, 0x42, 0x41, 0x38, 0x2d, 0x30, 0x38, 0x30, 0x30, 0x33, 0x36, 0x31, 0x42,
	0x31, 0x31, 0x30, 0x33 };

uint32_t fguid_test_identifier_utf32_string_lower_with_invalid_first_brace[ 38 ] = {
	0x5b, 0x34, 0x35, 0x30, 0x64, 0x38, 0x66, 0x62, 0x61, 0x2d, 0x61, 0x64, 0x32, 0x35, 0x2d, 0x31, 
	0x31, 0x64, 0x30, 0x2d, 0x39, 0x62, 0x61, 0x38, 0x2d, 0x30, 0x38, 0x30, 0x30, 0x33, 0x36, 0x31, 
	0x62, 0x31, 0x31, 0x30, 0x33, 0x7d };

uint32_t fguid_test_identifier_utf32_string_lower_with_invalid_last_brace[ 38 ] = {
	0x7b, 0x34, 0x35, 0x30, 0x64, 0x38, 0x66, 0x62, 0x61, 0x2d, 0x61, 0x64, 0x32, 0x35, 0x2d, 0x31, 
	0x31, 0x64, 0x30, 0x2d, 0x39, 0x62, 0x61, 0x38, 0x2d, 0x30, 0x38, 0x30, 0x30, 0x33, 0x36, 0x31, 
	0x62, 0x31, 0x31, 0x30, 0x33, 0x5d };

uint32_t fguid_test_identifier_utf32_string_lower_with_invalid_first_separator[ 36 ] = {
	0x34, 0x35, 0x30, 0x64, 0x38, 0x66, 0x62, 0x61, 0x5f, 0x61, 0x64, 0x32, 0x35, 0x2d, 0x31, 0x31, 
	0x64, 0x30, 0x2d, 0x39, 0x62, 0x61, 0x38, 0x2d, 0x30, 0x38, 0x30, 0x30, 0x33, 0x36, 0x31, 0x62, 
	0x31, 0x31, 0x30, 0x33 };

uint32_t fguid_test_identifier_utf32_string_lower_with_invalid_second_separator[ 36 ] = {
	0x34, 0x35, 0x30, 0x64, 0x38, 0x66, 0x62, 0x61, 0x2d, 0x61, 0x64, 0x32, 0x35, 0x5f, 0x31, 0x31, 
	0x64, 0x30, 0x2d, 0x39, 0x62, 0x61, 0x38, 0x2d, 0x30, 0x38, 0x30, 0x30, 0x33, 0x36, 0x31, 0x62, 
	0x31, 0x31, 0x30, 0x33 };

uint32_t fguid_test_identifier_utf32_string_lower_with_invalid_third_separator[ 36 ] = {
	0x34, 0x35, 0x30, 0x64, 0x38, 0x66, 0x62, 0x61, 0x2d, 0x61, 0x64, 0x32, 0x35, 0x2d, 0x31, 0x31, 
	0x64, 0x30, 0x5f, 0x39, 0x62, 0x61, 0x38, 0x2d, 0x30, 0x38, 0x30, 0x30, 0x33, 0x36, 0x31, 0x62, 
	0x31, 0x31, 0x30, 0x33 };

uint32_t fguid_test_identifier_utf32_string_lower_with_invalid_fourth_separator[ 36 ] = {
	0x34, 0x35, 0x30, 0x64, 0x38, 0x66, 0x62, 0x61, 0x2d, 0x61, 0x64, 0x32, 0x35, 0x2d, 0x31, 0x31, 
	0x64, 0x30, 0x2d, 0x39, 0x62, 0x61, 0x38, 0x5f, 0x30, 0x38, 0x30, 0x30, 0x33, 0x36, 0x31, 0x62, 
	0x31, 0x31, 0x30, 0x33 };

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

	identifier = NULL;

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

#if defined( HAVE_FGUID_TEST_MEMORY )

	/* 1 fail in memory_allocate_structure
	 */
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
	/* 1 fail in memset after memory_allocate_structure
	 */
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

	/* Test regular cases
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

/* Tests the libfguid_identifier_copy_to_byte_stream function
 * Returns 1 if successful or 0 if not
 */
int fguid_test_identifier_copy_to_byte_stream(
     void )
{
	uint8_t guid_data[ 16 ];

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

	/* Test regular cases
	 */
	result = libfguid_identifier_copy_to_byte_stream(
	          identifier,
	          guid_data,
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

	result = libfguid_identifier_copy_to_byte_stream(
	          identifier,
	          guid_data,
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
	result = libfguid_identifier_copy_to_byte_stream(
	          NULL,
	          guid_data,
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

	result = libfguid_identifier_copy_to_byte_stream(
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

	result = libfguid_identifier_copy_to_byte_stream(
	          identifier,
	          guid_data,
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

	result = libfguid_identifier_copy_to_byte_stream(
	          identifier,
	          guid_data,
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
	result = libfguid_identifier_copy_to_byte_stream(
	          identifier,
	          guid_data,
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
	result = libfguid_identifier_copy_to_byte_stream(
	          identifier,
	          guid_data,
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

/* Tests the libfguid_identifier_get_string_size function
 * Returns 1 if successful or 0 if not
 */
int fguid_test_identifier_get_string_size(
     libfguid_identifier_t *identifier )
{
	libcerror_error_t *error = NULL;
	size_t string_size       = 0;
	int result               = 0;

	/* Test regular cases
	 */
	result = libfguid_identifier_get_string_size(
	          identifier,
	          &string_size,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "string_size",
	 string_size,
	 (size_t) 37 );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfguid_identifier_get_string_size(
	          identifier,
	          &string_size,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE | LIBFGUID_STRING_FORMAT_FLAG_USE_SURROUNDING_BRACES,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "string_size",
	 string_size,
	 (size_t) 39 );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfguid_identifier_get_string_size(
	          NULL,
	          &string_size,
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

	result = libfguid_identifier_get_string_size(
	          identifier,
	          NULL,
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

	result = libfguid_identifier_get_string_size(
	          identifier,
	          &string_size,
	          0x00000000UL,
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

	result = libfguid_identifier_get_string_size(
	          identifier,
	          &string_size,
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

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfguid_identifier_copy_from_utf8_string function
 * Returns 1 if successful or 0 if not
 */
int fguid_test_identifier_copy_from_utf8_string(
     libfguid_identifier_t *identifier )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test regular cases
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

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfguid_identifier_copy_from_utf8_string_with_index function
 * Returns 1 if successful or 0 if not
 */
int fguid_test_identifier_copy_from_utf8_string_with_index(
     libfguid_identifier_t *identifier )
{
	libcerror_error_t *error = NULL;
	size_t utf8_string_index = 0;
	int result               = 0;

	/* Test regular cases
	 */
	utf8_string_index = 0;

	result = libfguid_identifier_copy_from_utf8_string_with_index(
	          identifier,
	          fguid_test_identifier_utf8_string_lower,
	          36,
	          &utf8_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_index",
	 utf8_string_index,
	 (size_t) 36 );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	utf8_string_index = 0;

	result = libfguid_identifier_copy_from_utf8_string_with_index(
	          identifier,
	          fguid_test_identifier_utf8_string_upper,
	          36,
	          &utf8_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_UPPER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_index",
	 utf8_string_index,
	 (size_t) 36 );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	utf8_string_index = 0;

	result = libfguid_identifier_copy_from_utf8_string_with_index(
	          identifier,
	          fguid_test_identifier_utf8_string_mixed,
	          36,
	          &utf8_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_MIXED_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_index",
	 utf8_string_index,
	 (size_t) 36 );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	utf8_string_index = 0;

	result = libfguid_identifier_copy_from_utf8_string_with_index(
	          identifier,
	          fguid_test_identifier_utf8_string_lower_with_braces,
	          38,
	          &utf8_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE | LIBFGUID_STRING_FORMAT_FLAG_USE_SURROUNDING_BRACES,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_index",
	 utf8_string_index,
	 (size_t) 38 );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	utf8_string_index = 0;

	result = libfguid_identifier_copy_from_utf8_string_with_index(
	          NULL,
	          fguid_test_identifier_utf8_string_lower,
	          36,
	          &utf8_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_index",
	 utf8_string_index,
	 (size_t) 0 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfguid_identifier_copy_from_utf8_string_with_index(
	          identifier,
	          NULL,
	          36,
	          &utf8_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_index",
	 utf8_string_index,
	 (size_t) 0 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfguid_identifier_copy_from_utf8_string_with_index(
	          identifier,
	          fguid_test_identifier_utf8_string_lower,
	          (size_t) SSIZE_MAX + 1,
	          &utf8_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_index",
	 utf8_string_index,
	 (size_t) 0 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfguid_identifier_copy_from_utf8_string_with_index(
	          identifier,
	          fguid_test_identifier_utf8_string_lower,
	          36,
	          NULL,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_index",
	 utf8_string_index,
	 (size_t) 0 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfguid_identifier_copy_from_utf8_string_with_index(
	          identifier,
	          fguid_test_identifier_utf8_string_lower,
	          36,
	          &utf8_string_index,
	          0x00000000UL,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_index",
	 utf8_string_index,
	 (size_t) 0 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfguid_identifier_copy_from_utf8_string_with_index(
	          identifier,
	          fguid_test_identifier_utf8_string_lower,
	          36,
	          &utf8_string_index,
	          0xffffffffUL,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_index",
	 utf8_string_index,
	 (size_t) 0 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* UTF-8 string too small
	 */
	result = libfguid_identifier_copy_from_utf8_string_with_index(
	          identifier,
	          fguid_test_identifier_utf8_string_lower,
	          12,
	          &utf8_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_index",
	 utf8_string_index,
	 (size_t) 0 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Incorrect case
	 */
	result = libfguid_identifier_copy_from_utf8_string_with_index(
	          identifier,
	          fguid_test_identifier_utf8_string_mixed,
	          36,
	          &utf8_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_UPPER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_index",
	 utf8_string_index,
	 (size_t) 0 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Incorrect first surrounding brace
	 */
	result = libfguid_identifier_copy_from_utf8_string_with_index(
	          identifier,
	          fguid_test_identifier_utf8_string_lower_with_invalid_first_brace,
	          38,
	          &utf8_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE | LIBFGUID_STRING_FORMAT_FLAG_USE_SURROUNDING_BRACES,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_index",
	 utf8_string_index,
	 (size_t) 0 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Incorrect last surrounding brace
	 */
	result = libfguid_identifier_copy_from_utf8_string_with_index(
	          identifier,
	          fguid_test_identifier_utf8_string_lower_with_invalid_last_brace,
	          38,
	          &utf8_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE | LIBFGUID_STRING_FORMAT_FLAG_USE_SURROUNDING_BRACES,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_index",
	 utf8_string_index,
	 (size_t) 0 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Incorrect first separator
	 */
	result = libfguid_identifier_copy_from_utf8_string_with_index(
	          identifier,
	          fguid_test_identifier_utf8_string_lower_with_invalid_first_separator,
	          36,
	          &utf8_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_index",
	 utf8_string_index,
	 (size_t) 0 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Incorrect second separator
	 */
	result = libfguid_identifier_copy_from_utf8_string_with_index(
	          identifier,
	          fguid_test_identifier_utf8_string_lower_with_invalid_second_separator,
	          36,
	          &utf8_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_index",
	 utf8_string_index,
	 (size_t) 0 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Incorrect third separator
	 */
	result = libfguid_identifier_copy_from_utf8_string_with_index(
	          identifier,
	          fguid_test_identifier_utf8_string_lower_with_invalid_third_separator,
	          36,
	          &utf8_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_index",
	 utf8_string_index,
	 (size_t) 0 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Incorrect fourth separator
	 */
	result = libfguid_identifier_copy_from_utf8_string_with_index(
	          identifier,
	          fguid_test_identifier_utf8_string_lower_with_invalid_fourth_separator,
	          36,
	          &utf8_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_index",
	 utf8_string_index,
	 (size_t) 0 );

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

/* Tests the libfguid_identifier_copy_to_utf8_string function
 * Returns 1 if successful or 0 if not
 */
int fguid_test_identifier_copy_to_utf8_string(
     libfguid_identifier_t *identifier )
{
	uint8_t utft8_string[ 48 ];

	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test regular cases
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

	result = memory_compare(
	          fguid_test_identifier_utf8_string_lower,
	          utft8_string,
	          sizeof( uint8_t ) * 36 );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

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

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfguid_identifier_copy_to_utf8_string_with_index function
 * Returns 1 if successful or 0 if not
 */
int fguid_test_identifier_copy_to_utf8_string_with_index(
     libfguid_identifier_t *identifier )
{
	uint8_t utft8_string[ 48 ];

	libcerror_error_t *error = NULL;
	size_t utf8_string_index = 0;
	int result               = 0;

	/* Test regular cases
	 */
	utf8_string_index = 0;

	result = libfguid_identifier_copy_to_utf8_string_with_index(
	          identifier,
	          utft8_string,
	          37,
	          &utf8_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          fguid_test_identifier_utf8_string_lower,
	          utft8_string,
	          sizeof( uint8_t ) * 36 );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf8_string_index = 0;

	result = libfguid_identifier_copy_to_utf8_string_with_index(
	          identifier,
	          utft8_string,
	          37,
	          &utf8_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_UPPER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          fguid_test_identifier_utf8_string_upper,
	          utft8_string,
	          sizeof( uint8_t ) * 36 );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf8_string_index = 0;

	result = libfguid_identifier_copy_to_utf8_string_with_index(
	          identifier,
	          utft8_string,
	          39,
	          &utf8_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE | LIBFGUID_STRING_FORMAT_FLAG_USE_SURROUNDING_BRACES,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          fguid_test_identifier_utf8_string_lower_with_braces,
	          utft8_string,
	          sizeof( uint8_t ) * 38 );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	utf8_string_index = 0;

	result = libfguid_identifier_copy_to_utf8_string_with_index(
	          NULL,
	          utft8_string,
	          37,
	          &utf8_string_index,
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

	result = libfguid_identifier_copy_to_utf8_string_with_index(
	          identifier,
	          NULL,
	          37,
	          &utf8_string_index,
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

	result = libfguid_identifier_copy_to_utf8_string_with_index(
	          identifier,
	          utft8_string,
	          (size_t) SSIZE_MAX + 1,
	          &utf8_string_index,
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

	result = libfguid_identifier_copy_to_utf8_string_with_index(
	          identifier,
	          utft8_string,
	          37,
	          NULL,
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

	result = libfguid_identifier_copy_to_utf8_string_with_index(
	          identifier,
	          utft8_string,
	          37,
	          &utf8_string_index,
	          0x00000000UL,
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

	result = libfguid_identifier_copy_to_utf8_string_with_index(
	          identifier,
	          utft8_string,
	          37,
	          &utf8_string_index,
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
	result = libfguid_identifier_copy_to_utf8_string_with_index(
	          identifier,
	          utft8_string,
	          0,
	          &utf8_string_index,
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
	result = libfguid_identifier_copy_to_utf8_string_with_index(
	          identifier,
	          utft8_string,
	          18,
	          &utf8_string_index,
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

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfguid_identifier_copy_from_utf16_string function
 * Returns 1 if successful or 0 if not
 */
int fguid_test_identifier_copy_from_utf16_string(
     libfguid_identifier_t *identifier )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test regular cases
	 */
	result = libfguid_identifier_copy_from_utf16_string(
	          identifier,
	          fguid_test_identifier_utf16_string_lower,
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

	/* Test error cases
	 */
	result = libfguid_identifier_copy_from_utf16_string(
	          NULL,
	          fguid_test_identifier_utf16_string_lower,
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

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfguid_identifier_copy_from_utf16_string_with_index function
 * Returns 1 if successful or 0 if not
 */
int fguid_test_identifier_copy_from_utf16_string_with_index(
     libfguid_identifier_t *identifier )
{
	libcerror_error_t *error  = NULL;
	size_t utf16_string_index = 0;
	int result                = 0;

	/* Test regular cases
	 */
	utf16_string_index = 0;

	result = libfguid_identifier_copy_from_utf16_string_with_index(
	          identifier,
	          fguid_test_identifier_utf16_string_lower,
	          36,
	          &utf16_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_index",
	 utf16_string_index,
	 (size_t) 36 );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	utf16_string_index = 0;

	result = libfguid_identifier_copy_from_utf16_string_with_index(
	          identifier,
	          fguid_test_identifier_utf16_string_upper,
	          36,
	          &utf16_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_UPPER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_index",
	 utf16_string_index,
	 (size_t) 36 );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	utf16_string_index = 0;

	result = libfguid_identifier_copy_from_utf16_string_with_index(
	          identifier,
	          fguid_test_identifier_utf16_string_mixed,
	          36,
	          &utf16_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_MIXED_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_index",
	 utf16_string_index,
	 (size_t) 36 );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	utf16_string_index = 0;

	result = libfguid_identifier_copy_from_utf16_string_with_index(
	          identifier,
	          fguid_test_identifier_utf16_string_lower_with_braces,
	          38,
	          &utf16_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE | LIBFGUID_STRING_FORMAT_FLAG_USE_SURROUNDING_BRACES,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_index",
	 utf16_string_index,
	 (size_t) 38 );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	utf16_string_index = 0;

	result = libfguid_identifier_copy_from_utf16_string_with_index(
	          NULL,
	          fguid_test_identifier_utf16_string_lower,
	          36,
	          &utf16_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_index",
	 utf16_string_index,
	 (size_t) 0 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfguid_identifier_copy_from_utf16_string_with_index(
	          identifier,
	          NULL,
	          36,
	          &utf16_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_index",
	 utf16_string_index,
	 (size_t) 0 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfguid_identifier_copy_from_utf16_string_with_index(
	          identifier,
	          fguid_test_identifier_utf16_string_lower,
	          (size_t) SSIZE_MAX + 1,
	          &utf16_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_index",
	 utf16_string_index,
	 (size_t) 0 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfguid_identifier_copy_from_utf16_string_with_index(
	          identifier,
	          fguid_test_identifier_utf16_string_lower,
	          36,
	          NULL,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_index",
	 utf16_string_index,
	 (size_t) 0 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfguid_identifier_copy_from_utf16_string_with_index(
	          identifier,
	          fguid_test_identifier_utf16_string_lower,
	          36,
	          &utf16_string_index,
	          0x00000000UL,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_index",
	 utf16_string_index,
	 (size_t) 0 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfguid_identifier_copy_from_utf16_string_with_index(
	          identifier,
	          fguid_test_identifier_utf16_string_lower,
	          36,
	          &utf16_string_index,
	          0xffffffffUL,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_index",
	 utf16_string_index,
	 (size_t) 0 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* UTF-16 string too small
	 */
	result = libfguid_identifier_copy_from_utf16_string_with_index(
	          identifier,
	          fguid_test_identifier_utf16_string_lower,
	          12,
	          &utf16_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_index",
	 utf16_string_index,
	 (size_t) 0 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Incorrect case
	 */
	result = libfguid_identifier_copy_from_utf16_string_with_index(
	          identifier,
	          fguid_test_identifier_utf16_string_mixed,
	          36,
	          &utf16_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_UPPER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_index",
	 utf16_string_index,
	 (size_t) 0 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Incorrect first surrounding brace
	 */
	result = libfguid_identifier_copy_from_utf16_string_with_index(
	          identifier,
	          fguid_test_identifier_utf16_string_lower_with_invalid_first_brace,
	          38,
	          &utf16_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE | LIBFGUID_STRING_FORMAT_FLAG_USE_SURROUNDING_BRACES,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_index",
	 utf16_string_index,
	 (size_t) 0 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Incorrect last surrounding brace
	 */
	result = libfguid_identifier_copy_from_utf16_string_with_index(
	          identifier,
	          fguid_test_identifier_utf16_string_lower_with_invalid_last_brace,
	          38,
	          &utf16_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE | LIBFGUID_STRING_FORMAT_FLAG_USE_SURROUNDING_BRACES,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_index",
	 utf16_string_index,
	 (size_t) 0 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Incorrect first separator
	 */
	result = libfguid_identifier_copy_from_utf16_string_with_index(
	          identifier,
	          fguid_test_identifier_utf16_string_lower_with_invalid_first_separator,
	          36,
	          &utf16_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_index",
	 utf16_string_index,
	 (size_t) 0 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Incorrect second separator
	 */
	result = libfguid_identifier_copy_from_utf16_string_with_index(
	          identifier,
	          fguid_test_identifier_utf16_string_lower_with_invalid_second_separator,
	          36,
	          &utf16_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_index",
	 utf16_string_index,
	 (size_t) 0 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Incorrect third separator
	 */
	result = libfguid_identifier_copy_from_utf16_string_with_index(
	          identifier,
	          fguid_test_identifier_utf16_string_lower_with_invalid_third_separator,
	          36,
	          &utf16_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_index",
	 utf16_string_index,
	 (size_t) 0 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Incorrect fourth separator
	 */
	result = libfguid_identifier_copy_from_utf16_string_with_index(
	          identifier,
	          fguid_test_identifier_utf16_string_lower_with_invalid_fourth_separator,
	          36,
	          &utf16_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_index",
	 utf16_string_index,
	 (size_t) 0 );

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

/* Tests the libfguid_identifier_copy_to_utf16_string function
 * Returns 1 if successful or 0 if not
 */
int fguid_test_identifier_copy_to_utf16_string(
     libfguid_identifier_t *identifier )
{
	uint16_t utft16_string[ 48 ];

	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test regular cases
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

	result = memory_compare(
	          fguid_test_identifier_utf16_string_lower,
	          utft16_string,
	          sizeof( uint16_t ) * 36 );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

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

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfguid_identifier_copy_to_utf16_string_with_index function
 * Returns 1 if successful or 0 if not
 */
int fguid_test_identifier_copy_to_utf16_string_with_index(
     libfguid_identifier_t *identifier )
{
	uint16_t utft16_string[ 48 ];

	libcerror_error_t *error  = NULL;
	size_t utf16_string_index = 0;
	int result                = 0;

	/* Test regular cases
	 */
	utf16_string_index = 0;

	result = libfguid_identifier_copy_to_utf16_string_with_index(
	          identifier,
	          utft16_string,
	          37,
	          &utf16_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          fguid_test_identifier_utf16_string_lower,
	          utft16_string,
	          sizeof( uint16_t ) * 36 );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf16_string_index = 0;

	result = libfguid_identifier_copy_to_utf16_string_with_index(
	          identifier,
	          utft16_string,
	          37,
	          &utf16_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_UPPER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          fguid_test_identifier_utf16_string_upper,
	          utft16_string,
	          sizeof( uint16_t ) * 36 );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf16_string_index = 0;

	result = libfguid_identifier_copy_to_utf16_string_with_index(
	          identifier,
	          utft16_string,
	          39,
	          &utf16_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE | LIBFGUID_STRING_FORMAT_FLAG_USE_SURROUNDING_BRACES,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          fguid_test_identifier_utf16_string_lower_with_braces,
	          utft16_string,
	          sizeof( uint16_t ) * 38 );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	utf16_string_index = 0;

	result = libfguid_identifier_copy_to_utf16_string_with_index(
	          NULL,
	          utft16_string,
	          37,
	          &utf16_string_index,
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

	result = libfguid_identifier_copy_to_utf16_string_with_index(
	          identifier,
	          NULL,
	          37,
	          &utf16_string_index,
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

	result = libfguid_identifier_copy_to_utf16_string_with_index(
	          identifier,
	          utft16_string,
	          (size_t) SSIZE_MAX + 1,
	          &utf16_string_index,
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

	result = libfguid_identifier_copy_to_utf16_string_with_index(
	          identifier,
	          utft16_string,
	          37,
	          NULL,
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

	result = libfguid_identifier_copy_to_utf16_string_with_index(
	          identifier,
	          utft16_string,
	          37,
	          &utf16_string_index,
	          0x00000000UL,
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

	result = libfguid_identifier_copy_to_utf16_string_with_index(
	          identifier,
	          utft16_string,
	          37,
	          &utf16_string_index,
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
	result = libfguid_identifier_copy_to_utf16_string_with_index(
	          identifier,
	          utft16_string,
	          0,
	          &utf16_string_index,
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
	result = libfguid_identifier_copy_to_utf16_string_with_index(
	          identifier,
	          utft16_string,
	          18,
	          &utf16_string_index,
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

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfguid_identifier_copy_from_utf32_string function
 * Returns 1 if successful or 0 if not
 */
int fguid_test_identifier_copy_from_utf32_string(
     libfguid_identifier_t *identifier )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test regular cases
	 */
	result = libfguid_identifier_copy_from_utf32_string(
	          identifier,
	          fguid_test_identifier_utf32_string_lower,
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

	/* Test error cases
	 */
	result = libfguid_identifier_copy_from_utf32_string(
	          NULL,
	          fguid_test_identifier_utf32_string_lower,
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

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfguid_identifier_copy_from_utf32_string_with_index function
 * Returns 1 if successful or 0 if not
 */
int fguid_test_identifier_copy_from_utf32_string_with_index(
     libfguid_identifier_t *identifier )
{
	libcerror_error_t *error  = NULL;
	size_t utf32_string_index = 0;
	int result                = 0;

	/* Test regular cases
	 */
	utf32_string_index = 0;

	result = libfguid_identifier_copy_from_utf32_string_with_index(
	          identifier,
	          fguid_test_identifier_utf32_string_lower,
	          36,
	          &utf32_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 36 );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	utf32_string_index = 0;

	result = libfguid_identifier_copy_from_utf32_string_with_index(
	          identifier,
	          fguid_test_identifier_utf32_string_upper,
	          36,
	          &utf32_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_UPPER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 36 );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	utf32_string_index = 0;

	result = libfguid_identifier_copy_from_utf32_string_with_index(
	          identifier,
	          fguid_test_identifier_utf32_string_mixed,
	          36,
	          &utf32_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_MIXED_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 36 );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	utf32_string_index = 0;

	result = libfguid_identifier_copy_from_utf32_string_with_index(
	          identifier,
	          fguid_test_identifier_utf32_string_lower_with_braces,
	          38,
	          &utf32_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE | LIBFGUID_STRING_FORMAT_FLAG_USE_SURROUNDING_BRACES,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 38 );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	utf32_string_index = 0;

	result = libfguid_identifier_copy_from_utf32_string_with_index(
	          NULL,
	          fguid_test_identifier_utf32_string_lower,
	          36,
	          &utf32_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 0 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfguid_identifier_copy_from_utf32_string_with_index(
	          identifier,
	          NULL,
	          36,
	          &utf32_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 0 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfguid_identifier_copy_from_utf32_string_with_index(
	          identifier,
	          fguid_test_identifier_utf32_string_lower,
	          (size_t) SSIZE_MAX + 1,
	          &utf32_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 0 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfguid_identifier_copy_from_utf32_string_with_index(
	          identifier,
	          fguid_test_identifier_utf32_string_lower,
	          36,
	          NULL,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 0 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfguid_identifier_copy_from_utf32_string_with_index(
	          identifier,
	          fguid_test_identifier_utf32_string_lower,
	          36,
	          &utf32_string_index,
	          0x00000000UL,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 0 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfguid_identifier_copy_from_utf32_string_with_index(
	          identifier,
	          fguid_test_identifier_utf32_string_lower,
	          36,
	          &utf32_string_index,
	          0xffffffffUL,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 0 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* UTF-32 string too small
	 */
	result = libfguid_identifier_copy_from_utf32_string_with_index(
	          identifier,
	          fguid_test_identifier_utf32_string_lower,
	          12,
	          &utf32_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 0 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Incorrect case
	 */
	result = libfguid_identifier_copy_from_utf32_string_with_index(
	          identifier,
	          fguid_test_identifier_utf32_string_mixed,
	          36,
	          &utf32_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_UPPER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 0 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Incorrect first surrounding brace
	 */
	result = libfguid_identifier_copy_from_utf32_string_with_index(
	          identifier,
	          fguid_test_identifier_utf32_string_lower_with_invalid_first_brace,
	          38,
	          &utf32_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE | LIBFGUID_STRING_FORMAT_FLAG_USE_SURROUNDING_BRACES,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 0 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Incorrect last surrounding brace
	 */
	result = libfguid_identifier_copy_from_utf32_string_with_index(
	          identifier,
	          fguid_test_identifier_utf32_string_lower_with_invalid_last_brace,
	          38,
	          &utf32_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE | LIBFGUID_STRING_FORMAT_FLAG_USE_SURROUNDING_BRACES,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 0 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Incorrect first separator
	 */
	result = libfguid_identifier_copy_from_utf32_string_with_index(
	          identifier,
	          fguid_test_identifier_utf32_string_lower_with_invalid_first_separator,
	          36,
	          &utf32_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 0 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Incorrect second separator
	 */
	result = libfguid_identifier_copy_from_utf32_string_with_index(
	          identifier,
	          fguid_test_identifier_utf32_string_lower_with_invalid_second_separator,
	          36,
	          &utf32_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 0 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Incorrect third separator
	 */
	result = libfguid_identifier_copy_from_utf32_string_with_index(
	          identifier,
	          fguid_test_identifier_utf32_string_lower_with_invalid_third_separator,
	          36,
	          &utf32_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 0 );

	FGUID_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Incorrect fourth separator
	 */
	result = libfguid_identifier_copy_from_utf32_string_with_index(
	          identifier,
	          fguid_test_identifier_utf32_string_lower_with_invalid_fourth_separator,
	          36,
	          &utf32_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FGUID_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 0 );

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

/* Tests the libfguid_identifier_copy_to_utf32_string function
 * Returns 1 if successful or 0 if not
 */
int fguid_test_identifier_copy_to_utf32_string(
     libfguid_identifier_t *identifier )
{
	uint32_t utft32_string[ 48 ];

	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test regular cases
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

	result = memory_compare(
	          fguid_test_identifier_utf32_string_lower,
	          utft32_string,
	          sizeof( uint32_t ) * 36 );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

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

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfguid_identifier_copy_to_utf32_string_with_index function
 * Returns 1 if successful or 0 if not
 */
int fguid_test_identifier_copy_to_utf32_string_with_index(
     libfguid_identifier_t *identifier )
{
	uint32_t utft32_string[ 48 ];

	libcerror_error_t *error  = NULL;
	size_t utf32_string_index = 0;
	int result                = 0;

	/* Test regular cases
	 */
	utf32_string_index = 0;

	result = libfguid_identifier_copy_to_utf32_string_with_index(
	          identifier,
	          utft32_string,
	          37,
	          &utf32_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          fguid_test_identifier_utf32_string_lower,
	          utft32_string,
	          sizeof( uint32_t ) * 36 );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf32_string_index = 0;

	result = libfguid_identifier_copy_to_utf32_string_with_index(
	          identifier,
	          utft32_string,
	          37,
	          &utf32_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_UPPER_CASE,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          fguid_test_identifier_utf32_string_upper,
	          utft32_string,
	          sizeof( uint32_t ) * 36 );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf32_string_index = 0;

	result = libfguid_identifier_copy_to_utf32_string_with_index(
	          identifier,
	          utft32_string,
	          39,
	          &utf32_string_index,
	          LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE | LIBFGUID_STRING_FORMAT_FLAG_USE_SURROUNDING_BRACES,
	          &error );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FGUID_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          fguid_test_identifier_utf32_string_lower_with_braces,
	          utft32_string,
	          sizeof( uint32_t ) * 38 );

	FGUID_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	utf32_string_index = 0;

	result = libfguid_identifier_copy_to_utf32_string_with_index(
	          NULL,
	          utft32_string,
	          37,
	          &utf32_string_index,
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

	result = libfguid_identifier_copy_to_utf32_string_with_index(
	          identifier,
	          NULL,
	          37,
	          &utf32_string_index,
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

	result = libfguid_identifier_copy_to_utf32_string_with_index(
	          identifier,
	          utft32_string,
	          (size_t) SSIZE_MAX + 1,
	          &utf32_string_index,
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

	result = libfguid_identifier_copy_to_utf32_string_with_index(
	          identifier,
	          utft32_string,
	          37,
	          NULL,
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

	result = libfguid_identifier_copy_to_utf32_string_with_index(
	          identifier,
	          utft32_string,
	          37,
	          &utf32_string_index,
	          0x00000000UL,
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

	result = libfguid_identifier_copy_to_utf32_string_with_index(
	          identifier,
	          utft32_string,
	          37,
	          &utf32_string_index,
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
	result = libfguid_identifier_copy_to_utf32_string_with_index(
	          identifier,
	          utft32_string,
	          0,
	          &utf32_string_index,
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
	result = libfguid_identifier_copy_to_utf32_string_with_index(
	          identifier,
	          utft32_string,
	          18,
	          &utf32_string_index,
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
	libcerror_error_t *error          = NULL;
	libfguid_identifier_t *identifier = NULL;
	int result                        = 0;

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

	FGUID_TEST_RUN(
	 "libfguid_identifier_copy_to_byte_stream",
	 fguid_test_identifier_copy_to_byte_stream );

#if !defined( __BORLANDC__ ) || ( __BORLANDC__ >= 0x0560 )

	/* Initialize identifier for tests
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

	FGUID_TEST_RUN_WITH_ARGS(
	 "libfguid_identifier_get_string_size",
	 fguid_test_identifier_get_string_size,
	 identifier );

	FGUID_TEST_RUN_WITH_ARGS(
	 "libfguid_identifier_copy_from_utf8_string",
	 fguid_test_identifier_copy_from_utf8_string,
	 identifier );

	FGUID_TEST_RUN_WITH_ARGS(
	 "libfguid_identifier_copy_from_utf8_string_with_index",
	 fguid_test_identifier_copy_from_utf8_string_with_index,
	 identifier );

	FGUID_TEST_RUN_WITH_ARGS(
	 "libfguid_identifier_copy_to_utf8_string",
	 fguid_test_identifier_copy_to_utf8_string,
	 identifier );

	FGUID_TEST_RUN_WITH_ARGS(
	 "libfguid_identifier_copy_to_utf8_string_with_index",
	 fguid_test_identifier_copy_to_utf8_string_with_index,
	 identifier );

	FGUID_TEST_RUN_WITH_ARGS(
	 "libfguid_identifier_copy_from_utf16_string",
	 fguid_test_identifier_copy_from_utf16_string,
	 identifier );

	FGUID_TEST_RUN_WITH_ARGS(
	 "libfguid_identifier_copy_from_utf16_string_with_index",
	 fguid_test_identifier_copy_from_utf16_string_with_index,
	 identifier );

	FGUID_TEST_RUN_WITH_ARGS(
	 "libfguid_identifier_copy_to_utf16_string",
	 fguid_test_identifier_copy_to_utf16_string,
	 identifier );

	FGUID_TEST_RUN_WITH_ARGS(
	 "libfguid_identifier_copy_to_utf16_string_with_index",
	 fguid_test_identifier_copy_to_utf16_string_with_index,
	 identifier );

	FGUID_TEST_RUN_WITH_ARGS(
	 "libfguid_identifier_copy_from_utf32_string",
	 fguid_test_identifier_copy_from_utf32_string,
	 identifier );

	FGUID_TEST_RUN_WITH_ARGS(
	 "libfguid_identifier_copy_from_utf32_string_with_index",
	 fguid_test_identifier_copy_from_utf32_string_with_index,
	 identifier );

	FGUID_TEST_RUN_WITH_ARGS(
	 "libfguid_identifier_copy_to_utf32_string",
	 fguid_test_identifier_copy_to_utf32_string,
	 identifier );

	FGUID_TEST_RUN_WITH_ARGS(
	 "libfguid_identifier_copy_to_utf32_string_with_index",
	 fguid_test_identifier_copy_to_utf32_string_with_index,
	 identifier );

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

#endif /* !defined( __BORLANDC__ ) || ( __BORLANDC__ >= 0x0560 ) */

	return( EXIT_SUCCESS );

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
	return( EXIT_FAILURE );
}

