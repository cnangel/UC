AUTOMAKE_OPTIONS	= foreign

# AM_LDFLAGS		= -fPIC -L/usr/local/lib@BITS@ -pthread

SUBDIRS				= util

include_HEADERS		= uc.h

lib_LTLIBRARIES		= libuc.la

libuc_la_SOURCES	= uc.c uc.h
libuc_la_LIBADD		= util/libnomalize.la
libuc_la_LDFLAGS	= -no-undefined -version-info @LT_VERSION_INFO@ -release @PACKAGE_VERSION@

bin_PROGRAMS		= ucrun

ucrun_SOURCES		= ucrun.c
ucrun_LDADD			= libuc.la
ucrun_LDFLAGS		= -static

