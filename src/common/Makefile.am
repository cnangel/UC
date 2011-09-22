# $Id: Makefile.am,v 1.0.0-0 2011/09/23 00:19:35 Cnangel Exp $

AUTOMAKE_OPTIONS 				= foreign

AM_CXXFLAGS						= -I$(top_srcdir)/src \
								  $(NULL)

noinst_LTLIBRARIES				= libuc_s.la
libuc_s_la_SOURCES				= stringutility.cpp stringutility.h \
								  $(NULL)
libuc_sincludedir				= $(includedir)/@PACKAGE_NAME@/common
libuc_sinclude_HEADERS			= stringutility.h \
								  $(NULL)

