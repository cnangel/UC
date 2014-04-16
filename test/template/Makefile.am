# $Id: Makefile.am,v 1.0.0-0 2010/06/13 11:33:26 Cnangel Exp $

AUTOMAKE_OPTIONS				= foreign

EXTRA_DIST						= prime_tables.h \
								  $(NULL)

AM_LDFLAGS						= $(GTEST_LIBS) \
								  $(pkg-config --libs-only-L gtest) -lgtest_main \
								  -fPIC -L/usr/lib@BITS@ \
								  -lrt -static \
								  $(NULL)

AM_CPPFLAGS						= -I$(top_srcdir)/src \
								  $(GTEST_CFLAGS) \
								  $(NULL)

check_PROGRAMS					= sample1_unittest \
								  sample2_unittest \
								  sample3_unittest \
								  sample4_unittest \
								  sample5_unittest \
								  sample6_unittest \
								  sample7_unittest \
								  sample8_unittest \
								  sample9_unittest \
								  sample10_unittest \
								  $(NULL)
sample1_unittest_SOURCES		= sample1.cc sample1.h sample1_unittest.cc 
sample2_unittest_SOURCES		= sample2.cc sample2.h sample2_unittest.cc
sample3_unittest_SOURCES		= sample3-inl.h sample3_unittest.cc
sample4_unittest_SOURCES		= sample4.cc sample4.h sample4_unittest.cc
sample5_unittest_SOURCES		= sample5_unittest.cc sample1.cc sample1.h
sample6_unittest_SOURCES		= sample6_unittest.cc
sample7_unittest_SOURCES		= sample7_unittest.cc
sample8_unittest_SOURCES		= sample8_unittest.cc
sample9_unittest_SOURCES		= sample9_unittest.cc
sample10_unittest_SOURCES		= sample10_unittest.cc

TESTS_ENVIRONMENT				= LD_LIBRARY_PATH=/usr/lib@BITS@ HEAPCHECK=normal
TESTS							= $(check_PROGRAMS)
