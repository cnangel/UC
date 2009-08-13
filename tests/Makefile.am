AUTOMAKE_OPTIONS = foreign

# EXTRA_DIST = dotest.c t1.c
AM_CPPFLAGS			= -I$(top_srcdir)/src
LDADD				= ../src/uc

test_sources		= t1.c \
					  $(NULL)

check_PROGRAMS		= dotest
dotest_SOURCES		= dotest.c $(test_sources)
dotest_LDFLAGS		= -static-libtool-libs

TESTS_ENVIRONMENT	= LD_LIBRARY_PATH=/usr/local/lib HEAPCHECK=normal
TESTS				= $(check_PROGRAMS)
