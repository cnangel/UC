AUTOMAKE_OPTIONS = foreign

EXTRA_DIST = index.dat

#data_DATA = index.dat

datatodir = $(shell echo '$(datadir)/@PACKAGE@/data')
data_srcfiles = $(shell ls $(top_srcdir)/data/*.*|grep -v Makefile|grep -v \.bak$$)

install: install-localdata-local

install-localdata-local:
	@echo install data files to $(datatodir)
	@test -d $(datatodir) || mkdir -p $(datatodir)
	$(INSTALL_DATA) $(data_srcfiles) $(datatodir)

uninstall: uninstall-localdata-local

uninstall-localdata-local:
	@echo uninstall data files from $(datatodir)
	@test ! -d $(datatodir) \
		|| rm -rf $(datatodir)
	

