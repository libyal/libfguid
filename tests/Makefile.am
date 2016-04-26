AM_CPPFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/common \
	@LIBCSTRING_CPPFLAGS@ \
	@LIBCERROR_CPPFLAGS@ \
	@LIBFGUID_DLL_IMPORT@

TESTS = \
	test_api_functions.sh

check_SCRIPTS = \
	test_api_functions.sh \
	test_runner.sh

EXTRA_DIST = \
	$(check_SCRIPTS)

check_PROGRAMS = \
	fguid_test_get_version \
	fguid_test_identifier_copy_from \
	fguid_test_identifier_to_string

fguid_test_get_version_SOURCES = \
	fguid_test_get_version.c \
	fguid_test_libcstring.h \
	fguid_test_libfguid.h \
	fguid_test_unused.h

fguid_test_get_version_LDADD = \
	../libfguid/libfguid.la \
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

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f Makefile

