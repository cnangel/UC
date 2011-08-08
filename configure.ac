#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT([uc], [0.0.5], [cnangel@gmail.com])
AC_CONFIG_SRCDIR([config.h.in])
AC_CONFIG_HEADER([config.h])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([tar-ustar])
AM_INIT_AUTOMAKE([uc], [0.0.5])

MK=''
PACKAGE_RELEASE=1
PACKAGE_URL=https://github.com/cnangel/UC
LT_VERSION_INFO=1:0:0
#               | | |
#               | | +---------------+
#               | +-----------+	    |
#               +-current:revision:age
#                  |        |     |
#                  |        |     +- increment if interfaces have been added
#                  |        |        set to zero if interfaces have been removed or changed
#                  |        +- increment if source code has changed
#                  |           set to zero if current is incremented
#                  +- increment if interfaces have been added, removed or changed
DOXYGEN_OUTPUT_DIR=doc/doxygen
AC_SUBST(MK)
AC_SUBST(PACKAGE_RELEASE)
AC_SUBST(PACKAGE_URL)
AC_SUBST(LT_VERSION_INFO)
AC_SUBST(DOXYGEN_OUTPUT_DIR)

# Check for doxygen
BB_ENABLE_DOXYGEN

# Check for pthread
BB_CHECK_PTHREADS

# Checks for programs.
AC_PROG_CXX
AC_PROG_AWK
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
#AC_PROG_RANLIB
AC_PROG_LIBTOOL

AC_C_INT64_T

# Check for pkg-config
PKG_PROG_PKG_CONFIG

# Checks for libraries.
# FIXME: Replace `main' with a function in `-lcppunit':
AC_CHECK_LIB([cppunit], [main])
# FIXME: Replace `main' with a function in `-ldl':
AC_CHECK_LIB([dl], [main])
# FIXME: Replace `main' with a function in `-lpthread':
AC_CHECK_LIB([pthread], [main])

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stdint.h stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_CONST
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_TYPE_SIGNAL
AC_CHECK_FUNCS([memset])

PKG_CHECK_MODULES([GLIB2], [glib-2.0 >= 2.0.0 ], , AC_MSG_ERROR([
			*** glib-2.0 >= 2.0.0  is required to build.]))

AM_CONDITIONAL([STATIC_UC], [false])

AC_CHECK_EXTRA_OPTIONS
MY_ARG_WITH([a_b], [no])
MY_ARG_WITH([abcd], [yes])

UC_CFLAGS="$CXXFLAGS"
UC_LIBS="-l$PACKAGE"
UC_LIBDEPS="$LIBS"
UC_VERSION="$VERSION"

# Create files
AC_CONFIG_LIBCONFIG_IN([uc])
AC_CONFIG_PKGCONFIG_IN([uc], [user case])

AC_CONFIG_FILES([Doxyfile
		         Makefile
				 uc.spec
				 uc.pc
				 uc-config
                 conf/Makefile
				 myconfig.h:src/config.h.in
                 data/Makefile
                 doc/Makefile
                 include/Makefile
                 lib/Makefile
                 scripts/Makefile
                 src/Makefile
                 src/util/Makefile
                 test/Makefile
                 tools/Makefile])
AC_OUTPUT
