/*
 * GUID/UUID library identifier copy from testing program
 *
 * Copyright (c) 2010-2014, Joachim Metz <joachim.metz@gmail.com>
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
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include <stdio.h>

#include "fguid_test_libcerror.h"
#include "fguid_test_libcstring.h"
#include "fguid_test_libfguid.h"

/* Tests copying a GUID from a byte stream
 * Returns 1 if successful, 0 if not or -1 on error
 */
int fguid_test_identifier_copy_from_byte_stream(
     libfguid_identifier_t *guid,
     const uint8_t *byte_stream,
     size_t byte_stream_size,
     uint8_t byte_order,
     int expected_result )
{
	libcerror_error_t *error      = NULL;
	const char *byte_order_string = "unknown";
	int result                    = 0;

	if( byte_order == LIBFGUID_ENDIAN_BIG )
	{
		byte_order_string = "big-endian";
	}
	else if( byte_order == LIBFGUID_ENDIAN_LITTLE )
	{
		byte_order_string = "little-endian";
	}
        fprintf(
         stdout,
         "Testing copying identifier from byte stream: 0x%08" PRIjx " of size: %" PRIzd " and byte order: %s\t",
         (intptr_t) byte_stream,
         byte_stream_size,
         byte_order_string );

	result = libfguid_identifier_copy_from_byte_stream(
	          guid,
	          byte_stream,
	          byte_stream_size,
	          byte_order,
	          &error );

	if( result == expected_result )
	{
		fprintf(
		 stdout,
		 "(PASS)" );
	}
	else
	{
		fprintf(
		 stdout,
		 "(FAIL)" );
	}
	fprintf(
	 stdout,
	 "\n" );

	if( result == -1 )
	{
		if( expected_result != -1 )
		{
			libcerror_error_backtrace_fprint(
			 error,
			 stderr );
		}
		libcerror_error_free(
		 &error );
	}
	if( result == expected_result )
	{
		result = 1;
	}
	else
	{
		result = 0;
	}
	return( result );
}

/* Tests copying a GUID from an UTF-8 formatted string
 * Returns 1 if successful, 0 if not or -1 on error
 */
int fguid_test_identifier_copy_from_utf8_string(
     libfguid_identifier_t *guid,
     const uint8_t *utf8_string,
     size_t utf8_string_length,
     uint32_t string_format_flags,
     int expected_result )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

        fprintf(
         stdout,
         "Testing copying identifier from UTF-8 string\t" );

	result = libfguid_identifier_copy_from_utf8_string(
	          guid,
	          utf8_string,
	          utf8_string_length,
	          string_format_flags,
	          &error );

	if( result == expected_result )
	{
		fprintf(
		 stdout,
		 "(PASS)" );
	}
	else
	{
		fprintf(
		 stdout,
		 "(FAIL)" );
	}
	fprintf(
	 stdout,
	 "\n" );

	if( result == -1 )
	{
		if( expected_result != -1 )
		{
			libcerror_error_backtrace_fprint(
			 error,
			 stderr );
		}
		libcerror_error_free(
		 &error );
	}
	if( result == expected_result )
	{
		result = 1;
	}
	else
	{
		result = 0;
	}
	return( result );
}

/* The main program
 */
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
int wmain( int argc, wchar_t * const argv[] )
#else
int main( int argc, char * const argv[] )
#endif
{
	uint8_t *utf8_string_lower        = (uint8_t *) "450d8fba-ad25-11d0-98a8-0800361b1103";
	uint8_t *utf8_string_lower_braces = (uint8_t *) "{450d8fba-ad25-11d0-98a8-0800361b1103}";
	uint8_t *utf8_string_mixed        = (uint8_t *) "450D8FBA-ad25-11D0-98a8-0800361B1103";
	uint8_t *utf8_string_upper        = (uint8_t *) "450D8FBA-AD25-11D0-98A8-0800361B1103";
	uint8_t byte_stream[ 16 ]         = { 0xba, 0x8f, 0x0d, 0x45, 0x25, 0xad, 0xd0, 0x11, 0x98, 0xa8, 0x08, 0x00, 0x36, 0x1b, 0x11, 0x03 };

	libcerror_error_t *error    = NULL;
	libfguid_identifier_t *guid = NULL;

	if( argc != 1 )
	{
		fprintf(
		 stderr,
		 "This program does not take arguments.\n" );

		return( EXIT_FAILURE );
	}
	if( libfguid_identifier_initialize(
	     &guid,
	     &error ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to create GUID.\n" );

		goto on_error;
	}
	/* Case 1: byte stream is NULL, byte stream size is 16 and byte order is little-endian
	 * Expected result: -1
	 */
	if( fguid_test_identifier_copy_from_byte_stream(
	     guid,
	     NULL,
	     16,
	     LIBFGUID_ENDIAN_LITTLE,
	     -1 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to copy byte stream to GUID.\n" );

		goto on_error;
	}
	/* Case 2: byte stream is a buffer, byte stream size is 16 and byte order is big-endian
	 * Expected result: 1
	 */
	if( fguid_test_identifier_copy_from_byte_stream(
	     guid,
	     byte_stream,
	     16,
	     LIBFGUID_ENDIAN_BIG,
	     1 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to copy byte stream to GUID.\n" );

		goto on_error;
	}
	/* Case 3: byte stream is a buffer, byte stream size is 16 and byte order is little-endian
	 * Expected result: 1
	 */
	if( fguid_test_identifier_copy_from_byte_stream(
	     guid,
	     byte_stream,
	     16,
	     LIBFGUID_ENDIAN_LITTLE,
	     1 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to copy byte stream to GUID.\n" );

		goto on_error;
	}
	/* Case 4: byte stream is a buffer, byte stream size is 16 and byte order is 'X'
	 * Expected result: -1
	 */
	if( fguid_test_identifier_copy_from_byte_stream(
	     guid,
	     byte_stream,
	     16,
	     (uint8_t) 'X',
	     -1 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to copy byte stream to GUID.\n" );

		goto on_error;
	}
	/* Case 5: byte stream is a buffer, byte stream size is 8 and byte order is little-endian
	 * Expected result: -1
	 */
	if( fguid_test_identifier_copy_from_byte_stream(
	     guid,
	     byte_stream,
	     8,
	     LIBFGUID_ENDIAN_LITTLE,
	     -1 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to copy byte stream to GUID.\n" );

		goto on_error;
	}
	/* Case 6: byte stream is a buffer, byte stream size is 0 and byte order is little-endian
	 * Expected result: -1
	 */
	if( fguid_test_identifier_copy_from_byte_stream(
	     guid,
	     byte_stream,
	     0,
	     LIBFGUID_ENDIAN_LITTLE,
	     -1 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to copy byte stream to GUID.\n" );

		goto on_error;
	}
	/* Case 7: byte stream is a buffer, byte stream size is -1 and byte order is little-endian
	 * Expected result: -1
	 */
	if( fguid_test_identifier_copy_from_byte_stream(
	     guid,
	     byte_stream,
	     (size_t) -1,
	     LIBFGUID_ENDIAN_LITTLE,
	     -1 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to copy byte stream to GUID.\n" );

		goto on_error;
	}
	/* Case 8: UTF-8 string is NULL, UTF-8 string length is 36 and string format flags are use lower-case
	 * Expected result: -1
	 */
	if( fguid_test_identifier_copy_from_utf8_string(
	     guid,
	     NULL,
	     36,
	     LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	     -1 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to copy UTF-8 string to GUID.\n" );

		goto on_error;
	}
	/* Case 9: UTF-8 string is a buffer, UTF-8 string length is 36 and string format flags are use lower-case
	 * Expected result: 1
	 */
	if( fguid_test_identifier_copy_from_utf8_string(
	     guid,
	     utf8_string_lower,
	     36,
	     LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	     1 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to copy UTF-8 string to GUID.\n" );

		goto on_error;
	}
	/* Case 10: UTF-8 string is a buffer, UTF-8 string length is 12 and string format flags are use lower-case
	 * Expected result: -1
	 */
	if( fguid_test_identifier_copy_from_utf8_string(
	     guid,
	     utf8_string_lower,
	     12,
	     LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	     -1 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to copy UTF-8 string to GUID.\n" );

		goto on_error;
	}
	/* Case 11: UTF-8 string is a buffer, UTF-8 string length is 36 and string format flags are use upper-case
	 * Expected result: 1
	 */
	if( fguid_test_identifier_copy_from_utf8_string(
	     guid,
	     utf8_string_upper,
	     36,
	     LIBFGUID_STRING_FORMAT_FLAG_USE_UPPER_CASE,
	     1 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to copy UTF-8 string to GUID.\n" );

		goto on_error;
	}
	/* Case 12: UTF-8 string is a buffer, UTF-8 string length is 36 and string format flags are use upper-case
	 * Expected result: -1
	 */
	if( fguid_test_identifier_copy_from_utf8_string(
	     guid,
	     utf8_string_mixed,
	     36,
	     LIBFGUID_STRING_FORMAT_FLAG_USE_UPPER_CASE,
	     -1 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to copy UTF-8 string to GUID.\n" );

		goto on_error;
	}
	/* Case 13: UTF-8 string is a buffer, UTF-8 string length is 36 and string format flags are use mixed-case
	 * Expected result: 1
	 */
	if( fguid_test_identifier_copy_from_utf8_string(
	     guid,
	     utf8_string_mixed,
	     36,
	     LIBFGUID_STRING_FORMAT_FLAG_USE_MIXED_CASE,
	     1 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to copy UTF-8 string to GUID.\n" );

		goto on_error;
	}
	/* Case 14: UTF-8 string is a buffer, UTF-8 string length is 36 and string format flags are use lower-case and surrounding braces
	 * Expected result: 1
	 */
	if( fguid_test_identifier_copy_from_utf8_string(
	     guid,
	     utf8_string_lower_braces,
	     38,
	     LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE | LIBFGUID_STRING_FORMAT_FLAG_USE_SURROUNDING_BRACES,
	     1 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to copy UTF-8 string to GUID.\n" );

		goto on_error;
	}
	if( libfguid_identifier_free(
	     &guid,
	     &error ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to free GUID.\n" );

		goto on_error;
	}
	return( EXIT_SUCCESS );

on_error:
	if( error != NULL )
	{
		libcerror_error_backtrace_fprint(
		 error,
		 stderr );
		libcerror_error_free(
		 &error );
	}
	if( guid != NULL )
	{
		libfguid_identifier_free(
		 &guid,
		 NULL );
	}
	return( EXIT_FAILURE );
}

