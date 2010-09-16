# $Id: Makefile.am,v 1.0.0-0 2010/05/15 20:22:07 Cnangel Exp $

AUTOMAKE_OPTIONS = foreign

doxygen_dir = $(shell if [ -d $(top_srcdir)/@DOXYGEN_OUTPUT_DIR@ ]; then echo $(top_srcdir)/@DOXYGEN_OUTPUT_DIR@; fi)

EXTRA_DIST = uc.txt $(doxygen_dir)

# doctodir = $(shell echo '$(datadir)/@PACKAGE@/doc')
doctodir = $(shell if [ -z "$(docdir)" ]; then echo "$(prefix)/share/doc/@PACKAGE@"; else echo $(docdir); fi)
doc_srcdir = $(shell echo '$(top_srcdir)/doc')
doc_srcfiles = $(shell ls $(top_srcdir)/doc/*.*|grep -v Makefile|grep -v \.bak$$)

install: install-doc-local

install-doc-local:
	@echo install doc files to $(doctodir)
	@test -d $(doctodir) || mkdir -p $(doctodir)
	$(INSTALL_DATA) $(doc_srcfiles) $(doctodir)
#	@if [ ! -z $(doxygen_dir) -a -d $(doxygen_dir) ] ; then cp -r $(doxygen_dir) $(doctodir); fi;
	@test -z $(doxygen_dir) || test ! -d $(doxygen_dir) \
		|| cp -r $(doxygen_dir) $(doctodir)

uninstall: uninstall-doc-local

uninstall-doc-local:
	@echo uninstall doc files from $(doctodir)
	@test ! -d $(doctodir) \
		|| rm -rf $(doctodir)
	
