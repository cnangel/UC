# $Id: Makefile.am,v 1.0.0-0 2010/05/15 20:21:07 Cnangel Exp $

AUTOMAKE_OPTIONS 			= foreign

# AM_LDFLAGS				= -fPIC -L/usr/local/lib@BITS@ -pthread
# AM_CPPFLAGS				= -I$(top_srcdir)/src

noinst_LTLIBRARIES			= libnomalize.la
libnomalize_la_SOURCES		= nomalize.c \
							  nomalize.h \
							  $(NULL)
# libnomalize_la_LIBADD		= *.la -L/usr/lib -lmdbm
libnomalize_la_CPPFLAGS		= -I$(top_srcdir)/src
# libnomalize_la_LDFLAGS	= -no-undefined -version-info 1:0:0 -release 1.0.0 -L/usr/lib -lother
libnomalizeincludedir		= $(includedir)/@PACKAGE_NAME@/util
libnomalizeinclude_HEADERS	= nomalize.h \
							  $(NULL)

