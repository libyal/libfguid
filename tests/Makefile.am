AM_CPPFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/common \
	-I$(top_srcdir)/libcstring \
	@MEMWATCH_CPPFLAGS@

TESTS = \
	test_identifier_copy_from.sh \
	test_identifier_to_string.sh

check_SCRIPTS = \
	test_identifier_copy_from.sh \
	test_identifier_to_string.sh

EXTRA_DIST = \
	$(check_SCRIPTS)

check_PROGRAMS = \
	fguid_test_identifier_copy_from \
	fguid_test_identifier_to_string

fguid_test_identifier_copy_from_SOURCES = \
	fguid_test_libfguid.h \
	fguid_test_identifier_copy_from.c

fguid_test_identifier_copy_from_LDADD = \
	../libcstring/libcstring.la \
	../libfguid/libfguid.la \
        @MEMWATCH_LIBADD@

fguid_test_identifier_to_string_SOURCES = \
	fguid_test_libfguid.h \
	fguid_test_identifier_to_string.c

fguid_test_identifier_to_string_LDADD = \
	../libcstring/libcstring.la \
	../libfguid/libfguid.la \
        @MEMWATCH_LIBADD@

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f Makefile

