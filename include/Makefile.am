AUTOMAKE_OPTIONS = foreign

EXTRA_DIST = example.h

includetodir = $(shell echo '$(datadir)/@PACKAGE@/include')

include_srcdir = $(shell ls $(top_srcdir)/include/*.h|grep -v Makefile|grep -v \.bak$$)

install: install-include-local

install-include-local:
	@echo install include files to $(includetodir) ...
#	@echo install include files to $(includedir) ...
	@test -d $(includetodir) || $(INSTALL) -d $(includetodir)
	$(INSTALL_DATA) $(include_srcdir) $(includetodir)

uninstall: uninstall-include-local

uninstall-include-local:
	@echo uninstall include files from $(includetodir)
	@echo rm -rf $(includetodir)
	@test ! -d $(includetodir) \
		|| rm -rf $(includetodir)
