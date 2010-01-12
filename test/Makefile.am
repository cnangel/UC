AUTOMAKE_OPTIONS 	= foreign

EXTRA_DIST			= template.cpp template.h 

AM_CPPFLAGS			= -I$(top_srcdir)/src 
# AM_LDFLAGS			= -fPIC -L/usr/local/lib@BITS@ -pthread

LDADD				= $(top_srcdir)/src/libuc.la -lcppunit -lpthread -ldl

test_sources		= uctf.cpp uctf.h \
					  $(NULL)

check_PROGRAMS		= dotest
dotest_SOURCES		= dotest.cpp $(test_sources)
dotest_LDFLAGS		= --static-libtool-libs \
					  $(NULL)

dotest_CPPFLAGS		= -I$(top_srcdir)/src \
					  $(NULL)

TESTS_ENVIRONMENT	= LD_LIBRARY_PATH=/usr/local/lib HEAPCHECK=normal
TESTS				= $(check_PROGRAMS)
