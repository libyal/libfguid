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
	/bin/rm -f libfguid.h
	/bin/rm -f libfguid/definitions.h
	/bin/rm -f libfguid/features.h
	/bin/rm -f libfguid/types.h
	/bin/rm -f Makefile

