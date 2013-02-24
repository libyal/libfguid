/*
 * GUID/UUID library identifier to string testing program
 *
 * Copyright (c) 2010-2013, Joachim Metz <joachim.metz@gmail.com>
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

/* Tests copying a GUID to a string
 * Returns 1 if successful, 0 if not or -1 on error
 */
int fguid_test_identifier_to_string(
     libfguid_identifier_t *guid,
     libcstring_system_character_t *guid_string,
     size_t guid_string_size,
     uint32_t string_format_flags,
     int expected_result )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

        fprintf(
         stdout,
         "Testing copying identifier to string: 0x%08" PRIjx " of size: %" PRIzd "\t",
         (intptr_t) guid_string,
         guid_string_size );

#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
	result = libfguid_identifier_copy_to_utf16_string(
		  guid,
		  (uint16_t *) guid_string,
		  guid_string_size,
		  string_format_flags,
		  &error );
#else
	result = libfguid_identifier_copy_to_utf8_string(
		  guid,
		  (uint8_t *) guid_string,
		  guid_string_size,
		  string_format_flags,
		  &error );
#endif
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

	if( result == 1 )
	{
		fprintf(
		 stdout,
		 "GUID\t: %" PRIs_LIBCSTRING_SYSTEM "\n",
		 guid_string );
	}
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
        libcstring_system_character_t guid_string[ 48 ];

	uint8_t byte_stream[ 16 ] = { 0xba, 0x8f, 0x0d, 0x45, 0x25, 0xad, 0xd0, 0x11, 0x98, 0xa8, 0x08, 0x00, 0x36, 0x1b, 0x11, 0x03 };

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
	if( libfguid_identifier_copy_from_byte_stream(
	     guid,
	     byte_stream,
	     16,
	     LIBFGUID_ENDIAN_LITTLE,
	     &error ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to copy byte stream to GUID.\n" );

		goto on_error;
	}
	/* Case 1: string is NULL, string size is 37
	 * Expected result: -1
	 */
	if( fguid_test_identifier_to_string(
	     guid,
	     NULL,
	     37,
	     LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	     -1 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to copy GUID to string.\n" );

		goto on_error;
	}
	/* Case 2: string is a buffer, string size is 37
	 * Expected result: 1
	 */
	if( fguid_test_identifier_to_string(
	     guid,
	     guid_string,
	     37,
	     LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	     1 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to copy GUID to string.\n" );

		goto on_error;
	}
	/* Case 3: string is a buffer, string size is 0
	 * Expected result: -1
	 */
	if( fguid_test_identifier_to_string(
	     guid,
	     guid_string,
	     0,
	     LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	     -1 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to copy GUID to string.\n" );

		goto on_error;
	}
	/* Case 4: string is a buffer, string size is 18
	 * Expected result: -1
	 */
	if( fguid_test_identifier_to_string(
	     guid,
	     guid_string,
	     18,
	     LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
	     -1 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to copy GUID to string.\n" );

		goto on_error;
	}
	/* Case 5: string is a buffer, string size is 37
	 * Expected result: 1
	 */
	if( fguid_test_identifier_to_string(
	     guid,
	     guid_string,
	     37,
	     LIBFGUID_STRING_FORMAT_FLAG_USE_UPPER_CASE,
	     1 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to copy GUID to string.\n" );

		goto on_error;
	}
	/* Case 6: string is a buffer, string size is 39
	 * Expected result: 1
	 */
	if( fguid_test_identifier_to_string(
	     guid,
	     guid_string,
	     39,
	     LIBFGUID_STRING_FORMAT_FLAG_USE_UPPER_CASE | LIBFGUID_STRING_FORMAT_FLAG_USE_SURROUNDING_BRACES,
	     1 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to copy GUID to string.\n" );

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

