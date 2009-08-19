AUTOMAKE_OPTIONS		= foreign

# AM_LDFLAGS			= -fPIC -L/usr/local/lib@BITS@ -pthread
# include_HEADERS		= uc.h

SUBDIRS					= util


lib_LTLIBRARIES			= libuc.la

libuc_la_SOURCES		= ucmain.c ucmain.h \
						  uc.h \
						  $(NULL)
libuc_la_LIBADD			= util/libnomalize.la
libuc_la_CPPFLAGS		= -I$(top_srcdir)/src
libuc_la_LDFLAGS		= -no-undefined \
						  -version-info @LT_VERSION_INFO@ \
						  -release @PACKAGE_RELEASE@ \
						  $(NULL)

libucincludedir			= $(includedir)/@PACKAGE_NAME@
libucinclude_HEADERS	= uc.h \
						  $(NULL)

bin_PROGRAMS			= ucrun

ucrun_SOURCES			= ucrun.c
ucrun_LDADD				= libuc.la
ucrun_LDFLAGS			= -static

