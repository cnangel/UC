#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.59])
AC_INIT([uc],[0.0.6],[cnangel@gmail.com])
AC_CONFIG_SRCDIR([test/dotest.cpp])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([tar-ustar])
AM_INIT_AUTOMAKE([uc], [0.0.6])


# Variable setting of package
PACKAGE_RELEASE=1
PACKAGE_URL=https://github.com/cnangel/UC
AC_SUBST(PACKAGE_RELEASE)
AC_SUBST(PACKAGE_URL)

# Age information of package
LT_VERSION_INFO=1:0:0
#               | | |
#               | | +---------------+
#               | +-----------+     |
#               +-current:revision:age
#                  |        |     |
#                  |        |     +- increment if interfaces have been added
#                  |        |        set to zero if interfaces have been removed or changed
#                  |        +- increment if source code has changed
#                  |           set to zero if current is incremented
#                  +- increment if interfaces have been added, removed or changed
AC_SUBST(LT_VERSION_INFO)

# About doc output, It's a switch of comment
MK=''
AC_SUBST(MK)

# Doc path setting
DOXYGEN_OUTPUT_DIR=doc/doxygen
AC_SUBST(DOXYGEN_OUTPUT_DIR)

# Check for doxygen
BB_ENABLE_DOXYGEN

# Check for pthread, fix by cnangel: ac_fn_c_try_link: command not found
BB_CHECK_PTHREADS

# Checks for programs.
AC_PROG_CXX
AC_PROG_AWK
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_LIBTOOL
#LT_INIT

# Checks for libraries.
# FIXME: Replace `main' with a function in `-lcppunit':
AC_CHECK_LIB([cppunit], [main])
# FIXME: Replace `main' with a function in `-ldl':
AC_CHECK_LIB([dl], [main])
# FIXME: Replace `main' with a function in `-lpthread':
AC_CHECK_LIB([pthread], [main])

# Checks for header files.
AC_CHECK_HEADERS([stdint.h stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_TYPE_SIZE_T

# Checks for int64_t
AC_C_INT64_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_CHECK_FUNCS([memset])

# Checks for modules (Only for test pkgconfig)
PKG_CHECK_MODULES([GLIB2], [glib-2.0 >= 2.0.0 ], , AC_MSG_ERROR([
                       *** glib-2.0 >= 2.0.0  is required to build.]))

# Submit a bool variable for Makefile*
AM_CONDITIONAL([STATIC_UC], [false])

# Checks for extra options
AC_CHECK_EXTRA_OPTIONS

# Other args setting
MY_ARG_WITH([a_b], [no])
MY_ARG_WITH([abcd], [yes])

# Define some macros for LIBCONFIG and PKGCONFIG
UC_CFLAGS=""
UC_LIBS="-l$PACKAGE"
UC_LIBDEPS=""
UC_VERSION="$VERSION"

# Create some useful files
AC_CONFIG_LIBCONFIG_IN([uc], [scripts])
AC_CONFIG_PKGCONFIG_IN([uc], [user case for pkg-config], [pkgconfig])

AC_CONFIG_FILES([Doxyfile
                 Makefile
                 conf/Makefile
                 data/Makefile
                 doc/Makefile
                 include/Makefile
                 lib/Makefile
				 myconfig.h:src/config.h.in
                 pkgconfig/uc.pc
                 scripts/Makefile
                 scripts/uc-config
                 src/Makefile
                 src/util/Makefile
                 test/Makefile
                 tools/Makefile
				 uc.spec])
AC_OUTPUT
