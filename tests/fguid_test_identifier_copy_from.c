/*
 * GUID/UUID library identifier copy from testing program
 *
 * Copyright (c) 2010-2012, Joachim Metz <jbmetz@users.sourceforge.net>
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

#include <libcstring.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include <stdio.h>

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
	libfguid_error_t *error       = NULL;
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
			libfguid_error_backtrace_fprint(
			 error,
			 stderr );
		}
		libfguid_error_free(
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
	uint8_t byte_stream[ 16 ] = { 0xba, 0x8f, 0x0d, 0x45, 0x25, 0xad, 0xd0, 0x11, 0x98, 0xa8, 0x08, 0x00, 0x36, 0x1b, 0x11, 0x03 };

	libfguid_identifier_t *guid = NULL;
	libfguid_error_t *error     = NULL;

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
		libfguid_error_backtrace_fprint(
		 error,
		 stderr );
		libfguid_error_free(
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

