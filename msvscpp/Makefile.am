MSVSCPP_FILES = \
	fguid_test_identifier_copy_from/fguid_test_identifier_copy_from.vcproj \
	fguid_test_identifier_to_string/fguid_test_identifier_to_string.vcproj \
	libcerror/libcerror.vcproj \
	libcstring/libcstring.vcproj \
	libfguid/libfguid.vcproj \
	libfguid.sln

SCRIPT_FILES = \
	scripts/vs2008_x64.sh \
	scripts/vs2008_x64_sln.sed \
	scripts/vs2008_x64_vcproj.sed \
	scripts/vs2010_x64.sh \
	scripts/vs2010_x64_sln.sed \
	scripts/vs2010_x64_vcxproj.sed

EXTRA_DIST = \
	$(MSVSCPP_FILES) \
	$(SCRIPT_FILES)

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f Makefile

