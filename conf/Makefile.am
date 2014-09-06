# $Id: Makefile.am,v 1.0.0-0 2011/08/06 16:46:57 Cnangel Exp $

AUTOMAKE_OPTIONS			= foreign

conf_files					= config.cfg \
							  log4cpp.conf \
							  $(NULL)
tpl_conf_files				= config.cfg.tpl \
							  log4cpp.conf.tpl \
							  example.conf.tpl \
							  $(NULL)
dist_conf_files				= example.conf \
							  $(NULL)

conftodir					= $(shell echo $(sysconfdir)|sed -e 's|^/usr/etc|/etc|')

EXTRA_DIST					= $(tpl_conf_files)

# install data 
pkgsysconfdir				= $(conftodir)/@PACKAGE@
pkgsysconf_DATA				= $(conf_files)
dist_pkgsysconf_DATA		= $(dist_conf_files)

# install log 
pkglogdir					= $(localstatedir)/log/@PACKAGE@
pkglog_DATA					= $(NULL)

% : $(srcdir)/%.tpl
	sed 's#your_words#replace_words#' $< > $@

CLEANFILES					= *.cfg *.conf

