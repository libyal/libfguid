AM_CPPFLAGS = \
	-I../include -I$(top_srcdir)/include \
	-I../common -I$(top_srcdir)/common \
	@LIBCERROR_CPPFLAGS@ \
	@LIBFGUID_DLL_EXPORT@

lib_LTLIBRARIES = libfguid.la

libfguid_la_SOURCES = \
	libfguid.c \
	libfguid_definitions.h \
	libfguid_extern.h \
	libfguid_error.c libfguid_error.h \
	libfguid_libcerror.h \
	libfguid_identifier.c libfguid_identifier.h \
	libfguid_support.c libfguid_support.h \
	libfguid_types.h \
	libfguid_unused.h

libfguid_la_LIBADD = \
	@LIBCERROR_LIBADD@

libfguid_la_LDFLAGS = -no-undefined -version-info 1:0:0

EXTRA_DIST = \
	libfguid_definitions.h.in \
	libfguid.rc \
	libfguid.rc.in

DISTCLEANFILES = \
	libfguid_definitions.h \
	libfguid.rc \
	Makefile \
	Makefile.in

sources-local: $(BUILT_SOURCES)

splint-local:
	@echo "Running splint on libfguid ..."
	-splint -preproc -redef $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(libfguid_la_SOURCES)

