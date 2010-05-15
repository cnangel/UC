# $Id: Makefile.am,v 1.0.0-0 2010/05/14 11:09:28 Cnangel Exp $

# AUTOMAKE_OPTIONS	= foreign 1.11.1
AUTOMAKE_OPTIONS	= foreign 

CURRENTPATH			= $(shell /bin/pwd)

ACLOCAL_AMFLAGS		= -I m4
# install m4 files
m4datadir			= aclocal
m4data_DATA			= @PACKAGE@.m4 

# install @PACKAGE@.pc
pcdatadir			= $(libdir)/pkgconfig
pcdata_DATA			= @PACKAGE@.pc

# install @PACKAGE@-config
bin_SCRIPTS			= @PACKAGE@-config

# define rpm build root
RPMBUILDTOPDIR		= $(shell unset RPMBUILDTOPDIR; if [ -f ${HOME}/.rpmmacros ]; then export RPMBUILDTOPDIR=`grep _topdir ${HOME}/.rpmmacros|awk '{print $$2}'`; else export RPMBUILDTOPDIR=/usr/src/redhat; fi; echo $${RPMBUILDTOPDIR};)
# `rpm --showrc | $(PERL) -n -e 'print if(s/.*_topdir\s+(.*)/$$1/)'` ;

EXTRA_DIST			= autogen.sh \
					  @PACKAGE@.spec \
					  acinclude.m4 \
					  @PACKAGE@.m4 \
					  $(NULL)

SUBDIRS				= include \
					  lib \
					  data \
					  src \
					  conf \
					  doc \
					  scripts \
					  tools \
					  test \
					  $(NULL)


.PHONY: rpm doc

doc:
	$(mkdir_p) @DOXYGEN_OUTPUT_DIR@
	doxygen
	sed -i -e "s/charset=iso-8859-1/charset=utf-8/g" $(top_srcdir)/doc/doxygen/html/*.html

rpm: doc dist @PACKAGE@.spec
	$(RM) ${RPMBUILDTOPDIR}/SOURCES/$(distdir).tar.gz
	$(RM) ${RPMBUILDTOPDIR}/SPECS/@PACKAGE@.spec
	$(LN_S) `pwd`/$(distdir).tar.gz ${RPMBUILDTOPDIR}/SOURCES
	$(LN_S) `pwd`/@PACKAGE@.spec ${RPMBUILDTOPDIR}/SPECS
	rpmbuild -ba ${RPMBUILDTOPDIR}/SPECS/@PACKAGE@.spec

CLEANDIRS			= doc/doxygen
DISTCLEANFILES		= .deps Makefile 
CLEANFILES			= *~ *.log @PACKAGE@-*.tar.gz @PACKAGE@-config
MAINTAINERCLEANFILES = Makefile.in

clean-local:
	-test -z "$(CLEANDIRS)" || rm -rf $(CLEANDIRS)

