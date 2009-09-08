AUTOMAKE_OPTIONS = foreign

EXTRA_DIST = example.sh

scirptstodir = $(shell echo '$(datadir)/@PACKAGE@/scripts')
scirpts_srcdir = $(shell ls $(top_srcdir)/scripts/*|grep -v Makefile|grep -v \.bak$$)

install: install-scripts-local

install-scripts-local:
	@echo install scripts files to $(scirptstodir)
	@test -d $(scirptstodir) || mkdir -p $(scirptstodir)
	$(INSTALL_DATA) $(scripts_srcdir) $(scirptstodir)

uninstall: uninstall-scripts-local

uninstall-scripts-local:
	@echo uninstall scripts files from $(scirptstodir)
	@test ! -d $(scirptstodir) \
		|| rm -rf $(scirptstodir)
	

