/*
 * GUID functions
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
#include <byte_stream.h>
#include <memory.h>
#include <types.h>

#include "libfguid_definitions.h"
#include "libfguid_identifier.h"
#include "libfguid_libcerror.h"
#include "libfguid_types.h"

/* Initialize an identifier
 * Returns 1 if successful or -1 on error
 */
int libfguid_identifier_initialize(
     libfguid_identifier_t **identifier,
     libcerror_error_t **error )
{
	libfguid_internal_identifier_t *internal_identifier = NULL;
	static char *function                               = "libfguid_identifier_initialize";

	if( identifier == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid identifier.",
		 function );

		return( -1 );
	}
	if( *identifier != NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_ALREADY_SET,
		 "%s: invalid identifier value already set.",
		 function );

		return( -1 );
	}
	internal_identifier = memory_allocate_structure(
	                       libfguid_internal_identifier_t );

	if( internal_identifier == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
		 "%s: unable to create identifier.",
		 function );

		goto on_error;
	}
	if( memory_set(
	     internal_identifier,
	     0,
	     sizeof( libfguid_internal_identifier_t ) ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_SET_FAILED,
		 "%s: unable to clear identifier.",
		 function );

		goto on_error;
	}
	*identifier = (libfguid_identifier_t *) internal_identifier;

	return( 1 );

on_error:
	if( internal_identifier != NULL )
	{
		memory_free(
		 internal_identifier );
	}
	return( -1 );
}

/* Frees an identifier
 * Returns 1 if successful or -1 on error
 */
int libfguid_identifier_free(
     libfguid_identifier_t **identifier,
     libcerror_error_t **error )
{
	libfguid_internal_identifier_t *internal_identifier = NULL;
	static char *function                               = "libfguid_identifier_free";

	if( identifier == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid identifier.",
		 function );

		return( -1 );
	}
	if( *identifier != NULL )
	{
		internal_identifier = (libfguid_internal_identifier_t *) *identifier;
		*identifier         = NULL;

		memory_free(
		 internal_identifier );
	}
	return( 1 );
}

/* Converts a byte stream into an identifier
 * Returns 1 if successful or -1 on error
 */
int libfguid_identifier_copy_from_byte_stream(
     libfguid_identifier_t *identifier,
     const uint8_t *byte_stream,
     size_t byte_stream_size,
     uint8_t byte_order,
     libcerror_error_t **error )
{
	libfguid_internal_identifier_t *internal_identifier = NULL;
	static char *function                               = "libfguid_identifier_copy_from_byte_stream";

	if( identifier == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid identifier.",
		 function );

		return( -1 );
	}
	internal_identifier = (libfguid_internal_identifier_t *) identifier;

	if( byte_stream == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid byte stream.",
		 function );

		return( -1 );
	}
	if( byte_stream_size < 16 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_TOO_SMALL,
		 "%s: byte stream too small.",
		 function );

		return( -1 );
	}
	if( byte_stream_size > (size_t) SSIZE_MAX )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_EXCEEDS_MAXIMUM,
		 "%s: byte stream size exceeds maximum.",
		 function );

		return( -1 );
	}
	if( ( byte_order != LIBFGUID_ENDIAN_BIG )
	 && ( byte_order != LIBFGUID_ENDIAN_LITTLE ) )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported byte order.",
		 function );

		return( -1 );
	}
	if( byte_order == LIBFGUID_ENDIAN_LITTLE )
	{
		byte_stream_copy_to_uint32_little_endian(
		 byte_stream,
		 internal_identifier->time.lower );

		byte_stream += 4;

		byte_stream_copy_to_uint16_little_endian(
		 byte_stream,
		 internal_identifier->time.middle );

		byte_stream += 2;

		byte_stream_copy_to_uint16_little_endian(
		 byte_stream,
		 internal_identifier->time.upper );

		byte_stream += 2;
	}
	else if( byte_order == LIBFGUID_ENDIAN_BIG )
	{
		byte_stream_copy_to_uint32_big_endian(
		 byte_stream,
		 internal_identifier->time.lower );

		byte_stream += 4;

		byte_stream_copy_to_uint16_big_endian(
		 byte_stream,
		 internal_identifier->time.middle );

		byte_stream += 2;

		byte_stream_copy_to_uint16_big_endian(
		 byte_stream,
		 internal_identifier->time.upper );

		byte_stream += 2;
	}
	internal_identifier->clock_sequence.upper = byte_stream[ 0 ];
	internal_identifier->clock_sequence.lower = byte_stream[ 1 ];
	internal_identifier->node[ 0 ]            = byte_stream[ 2 ];
	internal_identifier->node[ 1 ]            = byte_stream[ 3 ];
	internal_identifier->node[ 2 ]            = byte_stream[ 4 ];
	internal_identifier->node[ 3 ]            = byte_stream[ 5 ];
	internal_identifier->node[ 4 ]            = byte_stream[ 6 ];
	internal_identifier->node[ 5 ]            = byte_stream[ 7 ];

	return( 1 );
}

/* Deterimes the size of the string for the identifier
 * The string size includes the end of string character
 * Returns 1 if successful or -1 on error
 */
int libfguid_identifier_get_string_size(
     libfguid_identifier_t *identifier,
     size_t *string_size,
     libcerror_error_t **error )
{
	static char *function = "libfguid_identifier_get_string_size";

	if( identifier == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid identifier.",
		 function );

		return( -1 );
	}
	if( string_size == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid string size.",
		 function );

		return( -1 );
	}
	*string_size = 37;

	return( 1 );
}

/* Converts the identifier into an UTF-8 string
 * The string size should include the end of string character
 * Returns 1 if successful or -1 on error
 */
int libfguid_identifier_copy_to_utf8_string(
     libfguid_identifier_t *identifier,
     uint8_t *utf8_string,
     size_t utf8_string_size,
     libcerror_error_t **error )
{
	libfguid_internal_identifier_t *internal_identifier = NULL;
	static char *function                               = "libfguid_identifier_copy_to_utf8_string";
	size_t string_index                                 = 0;
	uint8_t byte_value                                  = 0;
	uint8_t node_index                                  = 0;
	int8_t byte_shift                                   = 0;

	if( identifier == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid identifier.",
		 function );

		return( -1 );
	}
	internal_identifier = (libfguid_internal_identifier_t *) identifier;

	if( utf8_string == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid UTF-8 size.",
		 function );

		return( -1 );
	}
	if( utf8_string_size > (size_t) SSIZE_MAX )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_EXCEEDS_MAXIMUM,
		 "%s: UTF-8 string size exceeds maximum.",
		 function );

		return( -1 );
	}
	if( utf8_string_size < 37 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_TOO_SMALL,
		 "%s: UTF-8 string is too small.",
		 function );

		return( -1 );
	}
	byte_shift = 28;

	do
	{
		byte_value = ( internal_identifier->time.lower >> byte_shift ) & 0x0f;

		if( byte_value <= 9 )
		{
			utf8_string[ string_index++ ] = (uint8_t) '0' + byte_value;
		}
		else
		{
			utf8_string[ string_index++ ] = (uint8_t) 'a' + byte_value - 10;
		}
		byte_shift -= 4;
	}
	while( byte_shift >= 0 );

	utf8_string[ string_index++ ] = (uint8_t) '-';

	byte_shift = 12;

	do
	{
		byte_value = ( internal_identifier->time.middle >> byte_shift ) & 0x0f;

		if( byte_value <= 9 )
		{
			utf8_string[ string_index++ ] = (uint8_t) '0' + byte_value;
		}
		else
		{
			utf8_string[ string_index++ ] = (uint8_t) 'a' + byte_value - 10;
		}
		byte_shift -= 4;
	}
	while( byte_shift >= 0 );

	utf8_string[ string_index++ ] = (uint8_t) '-';

	byte_shift = 12;

	do
	{
		byte_value = ( internal_identifier->time.upper >> byte_shift ) & 0x0f;

		if( byte_value <= 9 )
		{
			utf8_string[ string_index++ ] = (uint8_t) '0' + byte_value;
		}
		else
		{
			utf8_string[ string_index++ ] = (uint8_t) 'a' + byte_value - 10;
		}
		byte_shift -= 4;
	}
	while( byte_shift >= 0 );

	utf8_string[ string_index++ ] = (uint8_t) '-';

	byte_shift = 4;

	do
	{
		byte_value = ( internal_identifier->clock_sequence.upper >> byte_shift ) & 0x0f;

		if( byte_value <= 9 )
		{
			utf8_string[ string_index++ ] = (uint8_t) '0' + byte_value;
		}
		else
		{
			utf8_string[ string_index++ ] = (uint8_t) 'a' + byte_value - 10;
		}
		byte_shift -= 4;
	}
	while( byte_shift >= 0 );

	byte_shift = 4;

	do
	{
		byte_value = ( internal_identifier->clock_sequence.lower >> byte_shift ) & 0x0f;

		if( byte_value <= 9 )
		{
			utf8_string[ string_index++ ] = (uint8_t) '0' + byte_value;
		}
		else
		{
			utf8_string[ string_index++ ] = (uint8_t) 'a' + byte_value - 10;
		}
		byte_shift -= 4;
	}
	while( byte_shift >= 0 );

	utf8_string[ string_index++ ] = (uint8_t) '-';

	for( node_index = 0;
	     node_index < 6;
	     node_index++ )
	{
		byte_shift = 4;

		do
		{
			byte_value = ( internal_identifier->node[ node_index ] >> byte_shift ) & 0x0f;

			if( byte_value <= 9 )
			{
				utf8_string[ string_index++ ] = (uint8_t) '0' + byte_value;
			}
			else
			{
				utf8_string[ string_index++ ] = (uint8_t) 'a' + byte_value - 10;
			}
			byte_shift -= 4;
		}
		while( byte_shift >= 0 );
	}
	utf8_string[ string_index++ ] = 0;

	return( 1 );
}

/* Converts the identifier into an UTF-16 string
 * The string size should include the end of string character
 * Returns 1 if successful or -1 on error
 */
int libfguid_identifier_copy_to_utf16_string(
     libfguid_identifier_t *identifier,
     uint16_t *utf16_string,
     size_t utf16_string_size,
     libcerror_error_t **error )
{
	libfguid_internal_identifier_t *internal_identifier = NULL;
	static char *function                               = "libfguid_identifier_copy_to_utf16_string";
	size_t string_index                                 = 0;
	uint8_t byte_value                                  = 0;
	uint8_t node_index                                  = 0;
	int8_t byte_shift                                   = 0;

	if( identifier == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid identifier.",
		 function );

		return( -1 );
	}
	internal_identifier = (libfguid_internal_identifier_t *) identifier;

	if( utf16_string == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid UTF-16 size.",
		 function );

		return( -1 );
	}
	if( utf16_string_size > (size_t) SSIZE_MAX )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_EXCEEDS_MAXIMUM,
		 "%s: UTF-16 string size exceeds maximum.",
		 function );

		return( -1 );
	}
	if( utf16_string_size < 37 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_TOO_SMALL,
		 "%s: UTF-16 string is too small.",
		 function );

		return( -1 );
	}
	byte_shift = 28;

	do
	{
		byte_value = ( internal_identifier->time.lower >> byte_shift ) & 0x0f;

		if( byte_value <= 9 )
		{
			utf16_string[ string_index++ ] = (uint16_t) '0' + byte_value;
		}
		else
		{
			utf16_string[ string_index++ ] = (uint16_t) 'a' + byte_value - 10;
		}
		byte_shift -= 4;
	}
	while( byte_shift >= 0 );

	utf16_string[ string_index++ ] = (uint16_t) '-';

	byte_shift = 12;

	do
	{
		byte_value = ( internal_identifier->time.middle >> byte_shift ) & 0x0f;

		if( byte_value <= 9 )
		{
			utf16_string[ string_index++ ] = (uint16_t) '0' + byte_value;
		}
		else
		{
			utf16_string[ string_index++ ] = (uint16_t) 'a' + byte_value - 10;
		}
		byte_shift -= 4;
	}
	while( byte_shift >= 0 );

	utf16_string[ string_index++ ] = (uint16_t) '-';

	byte_shift = 12;

	do
	{
		byte_value = ( internal_identifier->time.upper >> byte_shift ) & 0x0f;

		if( byte_value <= 9 )
		{
			utf16_string[ string_index++ ] = (uint16_t) '0' + byte_value;
		}
		else
		{
			utf16_string[ string_index++ ] = (uint16_t) 'a' + byte_value - 10;
		}
		byte_shift -= 4;
	}
	while( byte_shift >= 0 );

	utf16_string[ string_index++ ] = (uint16_t) '-';

	byte_shift = 4;

	do
	{
		byte_value = ( internal_identifier->clock_sequence.upper >> byte_shift ) & 0x0f;

		if( byte_value <= 9 )
		{
			utf16_string[ string_index++ ] = (uint16_t) '0' + byte_value;
		}
		else
		{
			utf16_string[ string_index++ ] = (uint16_t) 'a' + byte_value - 10;
		}
		byte_shift -= 4;
	}
	while( byte_shift >= 0 );

	byte_shift = 4;

	do
	{
		byte_value = ( internal_identifier->clock_sequence.lower >> byte_shift ) & 0x0f;

		if( byte_value <= 9 )
		{
			utf16_string[ string_index++ ] = (uint16_t) '0' + byte_value;
		}
		else
		{
			utf16_string[ string_index++ ] = (uint16_t) 'a' + byte_value - 10;
		}
		byte_shift -= 4;
	}
	while( byte_shift >= 0 );

	utf16_string[ string_index++ ] = (uint16_t) '-';

	for( node_index = 0;
	     node_index < 6;
	     node_index++ )
	{
		byte_shift = 4;

		do
		{
			byte_value = ( internal_identifier->node[ node_index ] >> byte_shift ) & 0x0f;

			if( byte_value <= 9 )
			{
				utf16_string[ string_index++ ] = (uint16_t) '0' + byte_value;
			}
			else
			{
				utf16_string[ string_index++ ] = (uint16_t) 'a' + byte_value - 10;
			}
			byte_shift -= 4;
		}
		while( byte_shift >= 0 );
	}
	utf16_string[ string_index++ ] = 0;

	return( 1 );
}

/* Converts the identifier into an UTF-32 string
 * The string size should include the end of string character
 * Returns 1 if successful or -1 on error
 */
int libfguid_identifier_copy_to_utf32_string(
     libfguid_identifier_t *identifier,
     uint32_t *utf32_string,
     size_t utf32_string_size,
     libcerror_error_t **error )
{
	libfguid_internal_identifier_t *internal_identifier = NULL;
	static char *function                               = "libfguid_identifier_copy_to_utf32_string";
	size_t string_index                                 = 0;
	uint8_t byte_value                                  = 0;
	uint8_t node_index                                  = 0;
	int8_t byte_shift                                   = 0;

	if( identifier == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid identifier.",
		 function );

		return( -1 );
	}
	internal_identifier = (libfguid_internal_identifier_t *) identifier;

	if( utf32_string == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid UTF-32 size.",
		 function );

		return( -1 );
	}
	if( utf32_string_size > (size_t) SSIZE_MAX )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_EXCEEDS_MAXIMUM,
		 "%s: UTF-32 string size exceeds maximum.",
		 function );

		return( -1 );
	}
	if( utf32_string_size < 37 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_TOO_SMALL,
		 "%s: UTF-32 string is too small.",
		 function );

		return( -1 );
	}
	byte_shift = 28;

	do
	{
		byte_value = ( internal_identifier->time.lower >> byte_shift ) & 0x0f;

		if( byte_value <= 9 )
		{
			utf32_string[ string_index++ ] = (uint32_t) '0' + byte_value;
		}
		else
		{
			utf32_string[ string_index++ ] = (uint32_t) 'a' + byte_value - 10;
		}
		byte_shift -= 4;
	}
	while( byte_shift >= 0 );

	utf32_string[ string_index++ ] = (uint32_t) '-';

	byte_shift = 12;

	do
	{
		byte_value = ( internal_identifier->time.middle >> byte_shift ) & 0x0f;

		if( byte_value <= 9 )
		{
			utf32_string[ string_index++ ] = (uint32_t) '0' + byte_value;
		}
		else
		{
			utf32_string[ string_index++ ] = (uint32_t) 'a' + byte_value - 10;
		}
		byte_shift -= 4;
	}
	while( byte_shift >= 0 );

	utf32_string[ string_index++ ] = (uint32_t) '-';

	byte_shift = 12;

	do
	{
		byte_value = ( internal_identifier->time.upper >> byte_shift ) & 0x0f;

		if( byte_value <= 9 )
		{
			utf32_string[ string_index++ ] = (uint32_t) '0' + byte_value;
		}
		else
		{
			utf32_string[ string_index++ ] = (uint32_t) 'a' + byte_value - 10;
		}
		byte_shift -= 4;
	}
	while( byte_shift >= 0 );

	utf32_string[ string_index++ ] = (uint32_t) '-';

	byte_shift = 4;

	do
	{
		byte_value = ( internal_identifier->clock_sequence.upper >> byte_shift ) & 0x0f;

		if( byte_value <= 9 )
		{
			utf32_string[ string_index++ ] = (uint32_t) '0' + byte_value;
		}
		else
		{
			utf32_string[ string_index++ ] = (uint32_t) 'a' + byte_value - 10;
		}
		byte_shift -= 4;
	}
	while( byte_shift >= 0 );

	byte_shift = 4;

	do
	{
		byte_value = ( internal_identifier->clock_sequence.lower >> byte_shift ) & 0x0f;

		if( byte_value <= 9 )
		{
			utf32_string[ string_index++ ] = (uint32_t) '0' + byte_value;
		}
		else
		{
			utf32_string[ string_index++ ] = (uint32_t) 'a' + byte_value - 10;
		}
		byte_shift -= 4;
	}
	while( byte_shift >= 0 );

	utf32_string[ string_index++ ] = (uint32_t) '-';

	for( node_index = 0;
	     node_index < 6;
	     node_index++ )
	{
		byte_shift = 4;

		do
		{
			byte_value = ( internal_identifier->node[ node_index ] >> byte_shift ) & 0x0f;

			if( byte_value <= 9 )
			{
				utf32_string[ string_index++ ] = (uint32_t) '0' + byte_value;
			}
			else
			{
				utf32_string[ string_index++ ] = (uint32_t) 'a' + byte_value - 10;
			}
			byte_shift -= 4;
		}
		while( byte_shift >= 0 );
	}
	utf32_string[ string_index++ ] = 0;

	return( 1 );
}

