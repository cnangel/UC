# $Id: Makefile.am,v 1.0.0-0 2012/05/24 17:18:07 Cnangel Exp $

AUTOMAKE_OPTIONS 				= foreign

AM_CXXFLAGS						= -I$(top_srcdir)/src \
								  $(NULL)

lib_LTLIBRARIES					= libucinterface.la libucif.la
libucinterface_la_SOURCES		= if.cpp if.h \
								  $(NULL)
libucinterface_la_LIBADD		= $(top_srcdir)/lib/libexample.la \
								  $(top_srcdir)/src/util/libnomalize.la \
								  $(top_srcdir)/src/common/libuc_s.la \
								  $(NULL)
libucinterfaceincludedir		= $(includedir)/@PACKAGE_NAME@/interface
libucinterfaceinclude_HEADERS	= if.h \
								  $(NULL)

#ucifdir							= $(libdir)
#ucif_PROGRAMS					= libucif.so
#libucif_so_SOURCES				= ucif.cpp ucif.h \
#								  $(NULL)
#libucif_so_LDADD				= libucinterface.la \
#								  $(NULL)
#libucif_so_LDFLAGS				= -L$(top_srcdir)/src/util -lsotest \
#								  -shared -fPIC \
#								  $(NULL)
libucif_la_SOURCES				= ucif.cpp ucif.h \
								  $(NULL)
libucif_la_LIBADD				= libucinterface.la \
								  $(NULL)
libucif_la_LDFLAGS				= -L$(top_srcdir)/src/util -lsotest \
								  -shared -fPIC \
								  $(NULL)
libucifincludedir				= $(includedir)/@PACKAGE_NAME@/interface
libucifinclude_HEADERS			= ucif.h \
								  $(NULL)
