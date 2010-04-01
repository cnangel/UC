AUTOMAKE_OPTIONS		= foreign

# AM_LDFLAGS			= -fPIC -L/usr/local/lib@BITS@ -pthread
# AM_CXXFLAGS			= -Wno-deprecated
# include_HEADERS		= uc.h

SUBDIRS					= util \
						  $(NULL)


lib_LTLIBRARIES			= libuc.la

libuc_la_SOURCES		= ucmain.c ucmain.h \
						  uccpp.cpp uccpp.h \
						  uc.h \
						  $(NULL)
libuc_la_LIBADD			= util/libnomalize.la
libuc_la_CPPFLAGS		= -I$(top_srcdir)/src  -D_FILE_OFFSET_BITS=64
# libuc_la_CXXFLAGS		= -Wno-deprecated -Wall -Wno-non-virtual-dtor
libuc_la_LDFLAGS		= -no-undefined \
						  -version-info @LT_VERSION_INFO@ \
						  -release @PACKAGE_RELEASE@ \
						  $(NULL)

libucincludedir			= $(includedir)/@PACKAGE_NAME@
libucinclude_HEADERS	= uc.h \
						  ucmain.h \
						  uccpp.h \
						  $(NULL)

bin_PROGRAMS			= ucrun

ucrun_SOURCES			= ucrun.c
# ucrun_CXXFLAGS		= -Wno-deprecated
ucrun_LDADD				= libuc.la
ucrun_LDFLAGS			= -static

