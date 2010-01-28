# AUTOMAKE_OPTIONS = foreign 1.11.1
AUTOMAKE_OPTIONS = foreign 

EXTRA_DIST = autogen.sh \
			 uc.spec \
			 $(NULL)

CURRENTPATH = $(shell /bin/pwd)

ACLOCAL_AMFLAGS = -I m4

SUBDIRS = include \
		  lib \
		  data \
		  src \
		  conf \
		  doc \
		  scripts \
		  tools \
		  test \
		  $(NULL)

# install check.pc
pcdatadir = $(libdir)/pkgconfig
pcdata_DATA = @PACKAGE@.pc

# define rpm build root
RPMBUILDTOPDIR = $(shell unset RPMBUILDTOPDIR; if [ -f ${HOME}/.rpmmacros ]; then export RPMBUILDTOPDIR=`grep _topdir ${HOME}/.rpmmacros|awk '{print $$2}'`; else export RPMBUILDTOPDIR=/usr/src/redhat; fi; echo $${RPMBUILDTOPDIR};)
# `rpm --showrc | $(PERL) -n -e 'print if(s/.*_topdir\s+(.*)/$$1/)'` ;

.PHONY: rpm doc

doc:
	$(mkdir_p) @DOXYGEN_OUTPUT_DIR@
	doxygen

rpm: doc dist @PACKAGE@.spec
	$(RM) ${RPMBUILDTOPDIR}/SOURCES/$(distdir).tar.gz
	$(RM) ${RPMBUILDTOPDIR}/SPECS/@PACKAGE@.spec
	$(LN_S) `pwd`/$(distdir).tar.gz ${RPMBUILDTOPDIR}/SOURCES
	$(LN_S) `pwd`/@PACKAGE@.spec ${RPMBUILDTOPDIR}/SPECS
	rpmbuild -ba ${RPMBUILDTOPDIR}/SPECS/@PACKAGE@.spec

DISTCLEANFILES = .deps Makefile 
CLEANFILES = *~ *.log uc-*.tar.gz
MAINTAINERCLEANFILES = Makefile.in
