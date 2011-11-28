# $Id: Makefile.am,v 1.0.0-0 2011/08/08 17:51:57 Cnangel Exp $

AUTOMAKE_OPTIONS			= foreign

doxygen_dir					= $(shell if [ -d $(top_srcdir)/@DOXYGEN_OUTPUT_DIR@ ]; then echo $(top_srcdir)/@DOXYGEN_OUTPUT_DIR@; fi)

EXTRA_DIST					= rpm-spec-mode.el \
							  $(doxygen_dir) \
							  $(NULL)

doctodir					= $(shell if [ -z "$(docdir)" ]; then echo "$(prefix)/share/doc/@PACKAGE@"; else echo $(docdir); fi)
doc_srcdir					= $(shell echo '$(top_srcdir)/doc')
doc_srcfiles				= $(shell ls $(top_srcdir)/doc/*.*|grep -v Makefile|grep -v \.bak$$)

install: install-doc-local

install-doc-local:
	@echo install doc files to $(doctodir)
	@test -d $(doctodir) || mkdir -p $(doctodir)
	$(INSTALL_DATA) $(doc_srcfiles) $(doctodir)
#	@if [ ! -z $(doxygen_dir) -a -d $(doxygen_dir) ] ; then cp -r $(doxygen_dir) $(doctodir); fi;
	@test -z $(doxygen_dir) || test ! -d $(doxygen_dir) \
		|| cp -r $(doxygen_dir) $(doctodir)
	@rm -rf `find $(doctodir) \( -name "Makefile*" -o -name ".svn" -o -name "*.bak" \)`

uninstall: uninstall-doc-local

uninstall-doc-local:
	@echo uninstall doc files from $(doctodir)
	@test ! -d $(doctodir) \
		|| rm -rf $(doctodir)
	
