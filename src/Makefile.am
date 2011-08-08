# $Id: Makefile.am,v 1.0.0-0 2010/05/15 20:21:28 Cnangel Exp $

AUTOMAKE_OPTIONS			= foreign

# AM_LDFLAGS				= -fPIC -L/usr/local/lib@BITS@ -pthread
# AM_CXXFLAGS				= -Wno-deprecated
# include_HEADERS			= uc.h

SUBDIRS						= util \
							  $(NULL)

lib_LTLIBRARIES				= libuc.la

libuc_la_SOURCES			= uccexam.c uccexam.h \
							  uccppexam.cpp uccppexam.h \
							  uc.h common.h \
							  $(NULL)
libuc_la_LIBADD				= util/libnomalize.la
libuc_la_CPPFLAGS			= -I$(top_srcdir)/src \
							  -D_FILE_OFFSET_BITS=64 \
							  $(NULL)
# libuc_la_CXXFLAGS			= -Wno-deprecated -Wall -Wno-non-virtual-dtor
libuc_la_LDFLAGS			= -no-undefined \
							  -version-info @LT_VERSION_INFO@ \
							  -release @PACKAGE_RELEASE@ \
							  $(NULL)
libucincludedir				= $(includedir)/@PACKAGE_NAME@
libucinclude_HEADERS		= uc.h \
							  common.h \
							  uccexam.h \
							  uccppexam.h \
							  $(NULL)

bin_PROGRAMS				= uccmain uccppmain

uccmain_SOURCES				= uccmain.c
# uccmain_CXXFLAGS			= -Wno-deprecated
uccmain_LDADD				= libuc.la
uccmain_LDFLAGS				= -static
uccmain_CPPFLAGS			= -I$(top_srcdir)/src 

uccppmain_SOURCES			= uccppmain.cpp
# uccppmain_CXXFLAGS		= -Wno-deprecated
uccppmain_LDADD				= libuc.la
uccppmain_LDFLAGS			= -static
uccppmain_CPPFLAGS			= -I$(top_srcdir)/src 

# you can self-define target like this
# mybindir					= $(bindir)/mime
# mybin_PROGRAMS			= mybin
# mylalibdir				= $(libdir)/mime
# mylalib_LTLIBRARIES		= my.la
# mysodir					= $(libdir)/mime
# myso_PROGRAMS				= my.so
# my_so_CXXFLAGS       		= -fPIC
# my_so_LDFLAGS        		= -shared -fpic
