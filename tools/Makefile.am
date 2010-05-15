# $Id: Makefile.am,v 1.0.0-0 2010/05/14 11:09:49 Cnangel Exp $

AUTOMAKE_OPTIONS = foreign

EXTRA_DIST = example.pl \
			 changelog.pl \
			 $(NULL)

toolstodir = $(shell echo '$(datadir)/@PACKAGE@/tools')
tools_srcdir = $(shell ls $(top_srcdir)/tools/*|grep -v Makefile|grep -v \.bak$$)

install: install-tools-local

install-tools-local:
	@echo install tools files to $(toolstodir)
	@test -d $(toolstodir) || mkdir -p $(toolstodir)
	$(INSTALL_DATA) $(tools_srcdir) $(toolstodir)

uninstall: uninstall-tools-local

uninstall-tools-local:
	@echo uninstall tools files from $(toolstodir)
	@test ! -d $(toolstodir) \
		|| rm -rf $(toolstodir)
	

