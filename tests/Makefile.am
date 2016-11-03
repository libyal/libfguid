AM_CPPFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/common \
	@LIBCSTRING_CPPFLAGS@ \
	@LIBCERROR_CPPFLAGS@ \
	@LIBFGUID_DLL_IMPORT@

TESTS = \
	test_api_functions.sh \
	test_api_types.sh

check_SCRIPTS = \
	test_api_functions.sh \
	test_api_types.sh \
	test_runner.sh

EXTRA_DIST = \
	$(check_SCRIPTS)

check_PROGRAMS = \
	fguid_test_error \
	fguid_test_identifier \
	fguid_test_identifier_copy_from \
	fguid_test_identifier_to_string \
	fguid_test_support

fguid_test_error_SOURCES = \
	fguid_test_error.c \
	fguid_test_libcstring.h \
	fguid_test_libfguid.h \
	fguid_test_macros.h \
	fguid_test_unused.h

fguid_test_error_LDADD = \
	../libfguid/libfguid.la \
	@LIBCSTRING_LIBADD@

fguid_test_identifier_SOURCES = \
	fguid_test_identifier.c \
	fguid_test_libcstring.h \
	fguid_test_libfguid.h \
	fguid_test_macros.h \
	fguid_test_memory.c fguid_test_memory.h \
	fguid_test_unused.h

fguid_test_identifier_LDADD = \
	../libfguid/libfguid.la \
	@LIBCERROR_LIBADD@ \
	@LIBCSTRING_LIBADD@

fguid_test_identifier_copy_from_SOURCES = \
	fguid_test_libcerror.h \
	fguid_test_libcstring.h \
	fguid_test_libfguid.h \
	fguid_test_identifier_copy_from.c

fguid_test_identifier_copy_from_LDADD = \
	../libfguid/libfguid.la \
	@LIBCERROR_LIBADD@ \
	@LIBCSTRING_LIBADD@

fguid_test_identifier_to_string_SOURCES = \
	fguid_test_libcerror.h \
	fguid_test_libcstring.h \
	fguid_test_libfguid.h \
	fguid_test_identifier_to_string.c

fguid_test_identifier_to_string_LDADD = \
	../libfguid/libfguid.la \
	@LIBCERROR_LIBADD@ \
	@LIBCSTRING_LIBADD@

fguid_test_support_SOURCES = \
	fguid_test_libcstring.h \
	fguid_test_libfguid.h \
	fguid_test_macros.h \
	fguid_test_support.c \
	fguid_test_unused.h

fguid_test_support_LDADD = \
	../libfguid/libfguid.la \
	@LIBCSTRING_LIBADD@

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f Makefile

