AUTOMAKE_OPTIONS = foreign

EXTRA_DIST = example.so

libtodir = $(shell echo '$(datadir)/@PACKAGE@/lib')

lib_srcdir = $(shell ls $(top_srcdir)/lib/*.*|grep -v Makefile|grep -v \.bak$$)

install: install-lib-local

install-lib-local:
#	@echo install lib files to $(libdir)
	@echo install lib files to ${libtodir}
	@test -d $(libtodir) || mkdir -p $(libtodir)
	$(INSTALL_DATA) $(lib_srcdir) $(libtodir)

uninstall: uninstall-lib-local

uninstall-lib-local:
	@echo uninstall lib files from $(libtodir)
	@echo rm -rf $(libtodir)
	@test ! -d $(libtodir) \
		|| rm -rf $(libtodir)

