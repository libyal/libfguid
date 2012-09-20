AM_CPPFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/common \
	@LIBCSTRING_CPPFLAGS@ \
	@LIBCERROR_CPPFLAGS@

lib_LTLIBRARIES = libfguid.la

libfguid_la_SOURCES = \
	libfguid.c \
	libfguid_definitions.h \
	libfguid_extern.h \
	libfguid_error.c libfguid_error.h \
	libfguid_libcerror.h \
	libfguid_libcstring.h \
	libfguid_identifier.c libfguid_identifier.h \
	libfguid_support.c libfguid_support.h \
	libfguid_types.h \
	libfguid_unused.h

libfguid_la_LIBADD = \
	@LIBCSTRING_LIBADD@ \
	@LIBCERROR_LIBADD@

libfguid_la_LDFLAGS = -no-undefined -version-info 1:0:0

EXTRA_DIST = \
	libfguid_definitions.h.in \
	libfguid.rc \
	libfguid.rc.in

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f libfguid_definitions.h
	/bin/rm -f libfguid.rc
	/bin/rm -f Makefile

splint:
	@echo "Running splint on libfguid ..." 
	-splint -preproc -redef $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(libfguid_la_SOURCES) 

