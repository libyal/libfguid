include_HEADERS = \
	libfguid.h

pkginclude_HEADERS = \
	libfguid/definitions.h \
	libfguid/error.h \
	libfguid/extern.h \
	libfguid/features.h \
	libfguid/types.h

EXTRA_DIST = \
	libfguid.h.in \
	libfguid/definitions.h.in \
	libfguid/features.h.in \
	libfguid/types.h.in

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	-rm -f libfguid.h
	-rm -f libfguid/definitions.h
	-rm -f libfguid/features.h
	-rm -f libfguid/types.h
	-rm -f Makefile

