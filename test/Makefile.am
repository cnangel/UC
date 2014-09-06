# $Id: Makefile.am,v 1.0.0-0 2011/08/08 21:37:21 Cnangel Exp $

AUTOMAKE_OPTIONS 	= foreign

EXTRA_DIST			= template.cpp template.h 

SUBDIRS				= template \
					  $(NULL)

test_sources		= uctf.cpp uctf.h \
					  $(NULL)
# AM_DEFAULT_SOURCE_EXT = .cpp

check_PROGRAMS		= dotest
dotest_SOURCES		= dotest.cpp $(test_sources)
dotest_CPPFLAGS		= -I$(top_srcdir)/src \
					  `cppunit-config --cflags` \
					  $(NULL)
dotest_LDADD		= $(top_builddir)/src/libuc.la
dotest_LDFLAGS		= `cppunit-config --libs` \
					  $(NULL)


TESTS_ENVIRONMENT	= LD_LIBRARY_PATH=/usr/local/lib HEAPCHECK=normal
TESTS				= $(check_PROGRAMS)
