AUTOMAKE_OPTIONS = foreign

EXTRA_DIST = example.sh

scriptstodir = $(shell echo '$(datadir)/@PACKAGE@/scripts')
scripts_srcfiles = $(shell ls $(top_srcdir)/scripts/*|grep -v Makefile|grep -v \.bak$$)

install: install-scripts-local

install-scripts-local:
	@echo install scripts files to $(scriptstodir)
	@test -d $(scriptstodir) || mkdir -p $(scriptstodir)
	$(INSTALL_DATA) $(scripts_srcfiles) $(scriptstodir)

uninstall: uninstall-scripts-local

uninstall-scripts-local:
	@echo uninstall scripts files from $(scriptstodir)
	@test ! -d $(scriptstodir) \
		|| rm -rf $(scriptstodir)
	

