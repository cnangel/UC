# $Id: Makefile.am,v 1.0.0-0 2011/08/06 16:46:57 Cnangel Exp $

AUTOMAKE_OPTIONS	= foreign

conf_files			= config.cfg \
					  $(NULL)
conftodir			= $(shell echo $(sysconfdir)|sed -e 's|^/usr/etc|/etc|')

EXTRA_DIST			= $(conf_files)

# install data 
confdatadir			= $(conftodir)/@PACKAGE@
confdata_DATA		= $(conf_files)
