#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.59])
AC_INIT([uc],[0.0.8],[cnangel@gmail.com])
AC_CONFIG_SRCDIR([test/dotest.cpp])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_AUX_DIR([build-aux])
# AM_SILENT_RULES([yes])
AC_CONFIG_MACRO_DIR([m4])
LT_PREREQ([2.2])
LT_INIT
# Since automake 1.9, th tar format can be chosen with the options tar-v7, tar-ustar, and tar-pax.
# AM_INIT_AUTOMAKE([tar-ustar])
AM_INIT_AUTOMAKE([1.9 tar-pax])


# build some environment variables
# dnl AC_ARG_VAR(BUILD_MODE, [if 'release', using rc_xx format for release in package name,
# dnl 			  else using nightly_XX])
# dnl AS_IF([test "x$BUILD_MODE" == "xrelease"], 
# dnl 	    [PACKAGE_RELEASE=rc_1],
# dnl 	    [PACKAGE_RELEASE=nightly_`date +%Y%m%d%H%M`]
# dnl              )
# dnl AH_TEMPLATE([HAVE_UCDEPS], [defined uc dependent library was found])

# Variable setting of package
PACKAGE_RELEASE=1
PACKAGE_URL=https://github.com/cnangel/UC
BITS=`if [[ 64 -eq $(getconf LONG_BIT) ]]; then echo -n $(getconf LONG_BIT); fi`
AC_SUBST(PACKAGE_RELEASE)
AC_SUBST(PACKAGE_URL)
AC_SUBST(BITS)

# Age information of package
ifdef([m4_pattern_allow], [m4_pattern_allow([LT_VERSION_INFO])])
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

# Checks for programs.
AC_PROG_CXX
AC_PROG_AWK
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_LIBTOOL
AC_LANG(C++)

# Check for doxygen
BB_ENABLE_DOXYGEN

# Check for pthread, fix by cnangel: ac_fn_c_try_link: command not found
BB_CHECK_PTHREADS

# Checks for libraries.
# FIXME: Replace `main' with a function in `-lcppunit':
AC_CHECK_LIB([cppunit], [main])
# FIXME: Replace `main' with a function in `-ldl':
AC_CHECK_LIB([dl], [main])
# FIXME: Replace `main' with a function in `-lpthread':
AC_CHECK_LIB([pthread], [main])
# Check for gtest
ifdef([m4_pattern_allow], [m4_pattern_allow([GTEST_LIB_CHECK])])
GTEST_LIB_CHECK([1.5], AC_MSG_RESULT([checking for Google Test... yes]), AC_MSG_ERROR([checking for Google Test... not found]))



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
# you can use GLIB2_CFLAGS and GLIB2_LIBS for Makefile.am
# dnl PKG_CHECK_MODULES([GLIB2], [glib-2.0 >= 2.0.0 ], , AC_MSG_ERROR([
# dnl                        *** glib-2.0 >= 2.0.0  is required to build.]))

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
                 lib64/Makefile
				 myconfig.h:src/config.h.in
                 pkgconfig/uc.pc
                 scripts/Makefile
                 scripts/uc-config
                 src/Makefile
				 src/common/Makefile
				 src/interface/Makefile
				 src/protobuf/Makefile
                 src/util/Makefile
                 test/Makefile
                 test/template/Makefile
                 tools/Makefile
				 uc.spec])
AC_OUTPUT
