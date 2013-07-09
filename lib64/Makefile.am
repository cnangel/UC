# $Id: Makefile.am,v 1.0.0-0 2011/08/08 17:47:52 Cnangel Exp $

AUTOMAKE_OPTIONS			= foreign

uclib_files					= libexample.so \
							  libexample.a \
							  libexample.la \
							  $(NULL)

dotlibsdir					= .libs

EXTRA_DIST					= $(uclib_files)

uclibdatadir				= $(datadir)/@PACKAGE@/lib@BITS@
uclibdata_DATA				= $(uclib_files)

all-am: lib-local 

lib-local:
	@echo cp libexample.a file to .libs directory 
	@test -d $(dotlibsdir) || mkdir -p $(dotlibsdir)
	test -f $(dotlibsdir)/libexample.a || cp libexample.a $(dotlibsdir)
