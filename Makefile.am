# AUTOMAKE_OPTIONS	= foreign 1.11.1
AUTOMAKE_OPTIONS	= foreign 

CURRENTPATH			= $(shell /bin/pwd)

ACLOCAL_AMFLAGS		= -I m4
# install m4 files
m4datadir			= aclocal
m4data_DATA			= uc.m4 

# install uc.pc
pcdatadir			= $(libdir)/pkgconfig
pcdata_DATA			= @PACKAGE@.pc

# install uc-config
bin_SCRIPTS			= uc-config

# define rpm build root
RPMBUILDTOPDIR		= $(shell unset RPMBUILDTOPDIR; if [ -f ${HOME}/.rpmmacros ]; then export RPMBUILDTOPDIR=`grep _topdir ${HOME}/.rpmmacros|awk '{print $$2}'`; else export RPMBUILDTOPDIR=/usr/src/redhat; fi; echo $${RPMBUILDTOPDIR};)
# `rpm --showrc | $(PERL) -n -e 'print if(s/.*_topdir\s+(.*)/$$1/)'` ;

EXTRA_DIST			= autogen.sh \
					  uc.spec \
					  acinclude.m4 \
					  uc.m4 \
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
CLEANFILES			= *~ *.log uc-*.tar.gz uc-config
MAINTAINERCLEANFILES = Makefile.in

clean-local:
	-test -z "$(CLEANDIRS)" || rm -rf $(CLEANDIRS)

