# $Id: Makefile.am,v 1.0.0-0 2010/05/15 20:21:28 Cnangel Exp $

AUTOMAKE_OPTIONS			= foreign

# you can include some Makefile.am for yourself, like this: 
# include $(top_srcdir)/config/MakeGlobal.am

# AM_LDFLAGS				= -fPIC -L/usr/local/lib@BITS@ -pthread
# AM_CXXFLAGS				= -Wno-deprecated
# include_HEADERS			= uc.h

# man_MANS					= uc.1

LIST_HEADER_ALL				=  $(wildcard *.h) 

SUBDIRS						= util \
							  common \
							  . \
							  interface \
							  $(NULL)

# you can use pkglib_LTLIBRARIES = libuc.la
lib_LTLIBRARIES				= libuc.la

libuc_la_SOURCES			= uccexam.c \
							  uccppexam.cpp \
							  $(LIST_HEADER_ALL) \
							  $(NULL)
libuc_la_LIBADD				= util/libnomalize.la
libuc_la_CPPFLAGS			= -I$(top_srcdir)/src \
							  -D_FILE_OFFSET_BITS=64 \
							  $(NULL)
# libuc_la_CXXFLAGS			= -Wno-deprecated -Wall -Wno-non-virtual-dtor
# you can use -avoid-version miss -version-info
# and add -module, not need "lib" for head
# and shared library use '-shared'
libuc_la_LDFLAGS			= -no-undefined \
							  -version-info @LT_VERSION_INFO@ \
							  -release @PACKAGE_RELEASE@ \
							  $(NULL)
libucincludedir				= $(includedir)/@PACKAGE_NAME@
libucinclude_HEADERS		= $(LIST_HEADER_ALL)

bin_PROGRAMS				= uccmain uccppmain

uccmain_SOURCES				= uccmain.c
# uccmain_CXXFLAGS			= -Wno-deprecated
uccmain_LDADD				= libuc.la
uccmain_LDFLAGS				= -static
uccmain_CPPFLAGS			= -I$(top_srcdir)/src 

uccppmain_SOURCES			= uccppmain.cpp
# uccppmain_CXXFLAGS		= -Wno-deprecated
uccppmain_LDADD				= libuc.la
#uccppmain_LDFLAGS			= -static
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

#install-exec-local: $(bin_PROGRAMS) $(noinst_PROGRAMS)
#	@list='$(noinst_PROGRAMS)'; for p in $$list; do \
#	  if test -f $$p; then \
#	    echo " $(LIBTOOL)  --mode=install $(INSTALL_PROGRAM) $$p $(bindir)/`echo $$p|sed -e 's/$(EXEEXT)$$//' -e 's/-new//' -e 's/cxxfilt/$(DEMANGLER_NAME)/'|sed '$(transform)'|sed 's/$$/$(EXEEXT)/'`"; \
#	    $(LIBTOOL)  --mode=install $(INSTALL_PROGRAM) $$p $(bindir)/`echo $$p|sed -e 's/$(EXEEXT)$$//' -e 's/-new//' -e 's/cxxfilt/$(DEMANGLER_NAME)/'|sed '$(transform)'|sed 's/$$/$(EXEEXT)/'`; \
#	  else :; fi; \
#	done
#	$(mkinstalldirs) $(tooldir)/bin
#	for i in $(TOOL_PROGS); do \
#	  if [ -f $$i$(EXEEXT) ]; then \
#	    j=`echo $$i | sed -e 's/-new//'`; \
#	    k=`echo $$j | sed '$(transform)'`; \
#	    if [ "$(bindir)/$$k$(EXEEXT)" != "$(tooldir)/bin/$$j$(EXEEXT)" ]; then \
#	      rm -f $(tooldir)/bin/$$j$(EXEEXT); \
#	      ln $(bindir)/$$k$(EXEEXT) $(tooldir)/bin/$$j$(EXEEXT) >/dev/null 2>/dev/null \
#		|| $(LIBTOOL) --mode=install $(INSTALL_PROGRAM) $$i$(EXEEXT) $(tooldir)/bin/$$j$(EXEEXT); \
#	    fi; \
#	  else true; \
#	  fi; \
#	done
