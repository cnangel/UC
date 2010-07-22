# $Id: Makefile.am,v 1.0.0-0 2010/05/15 20:22:42 Cnangel Exp $

AUTOMAKE_OPTIONS = foreign

EXTRA_DIST = config.cfg

conftodir = $(shell echo $(sysconfdir)|sed -e 's|^/usr/etc|/etc|')

sysconftodir = $(conftodir)/@PACKAGE@

install: install-conf-local

install-conf-local:
	@echo install config files to $(sysconftodir)
	@test -d $(sysconftodir) || mkdir -p $(sysconftodir)
	@test -f $(sysconftodir)/config.cfg \
		|| cp -p $(top_srcdir)/conf/config.cfg $(sysconftodir)/config.cfg

uninstall: uninstall-conf-local

uninstall-conf-local:
	@echo uninstall confile files from $(sysconftodir)
	@test ! -d $(sysconftodir) \
		|| rm -rf $(sysconftodir)
	

