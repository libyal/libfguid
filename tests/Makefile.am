AM_CPPFLAGS = \
	-I../include -I$(top_srcdir)/include \
	-I../common -I$(top_srcdir)/common \
	@LIBCERROR_CPPFLAGS@ \
	@LIBFGUID_DLL_IMPORT@

TESTS = \
	test_library.sh

check_SCRIPTS = \
	test_library.sh \
	test_manpage.sh \
	test_runner.sh

EXTRA_DIST = \
	$(check_SCRIPTS)

check_PROGRAMS = \
	fguid_test_error \
	fguid_test_identifier \
	fguid_test_support

fguid_test_error_SOURCES = \
	fguid_test_error.c \
	fguid_test_libfguid.h \
	fguid_test_macros.h \
	fguid_test_unused.h

fguid_test_error_LDADD = \
	../libfguid/libfguid.la

fguid_test_identifier_SOURCES = \
	fguid_test_identifier.c \
	fguid_test_libcerror.h \
	fguid_test_libfguid.h \
	fguid_test_macros.h \
	fguid_test_memory.c fguid_test_memory.h \
	fguid_test_unused.h

fguid_test_identifier_LDADD = \
	../libfguid/libfguid.la \
	@LIBCERROR_LIBADD@

fguid_test_support_SOURCES = \
	fguid_test_libfguid.h \
	fguid_test_macros.h \
	fguid_test_support.c \
	fguid_test_unused.h

fguid_test_support_LDADD = \
	../libfguid/libfguid.la

DISTCLEANFILES = \
	Makefile \
	Makefile.in

