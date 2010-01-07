#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
dnl $Id: configure.ac,v 1.0.1 2009/07/29 17:58:36 Cnangel Exp $

AC_PREREQ(2.59)
# define([UC_MAJOR_VERSION],[0])
# define([UC_MINOR_VERSION],[0])
# define([UC_MICRO_VERSION],[1])
AC_REVISION($Revision: esyscmd([grep -i Revision ChangeLog | awk 'NR==1 {print $5}' | tr -d "\n"]) $)dnl
AC_INIT(esyscmd([grep -i Revision ChangeLog | awk 'NR==1 {print $4}' | tr -d "\n"]), esyscmd([grep ^[[:digit:]\.] ChangeLog | awk 'NR==1 { max=$1 } NF>=1 { if ($1>max) max=$1; } END{print max}' | tr -d "\n"]), esyscmd([grep -i Copyright README | awk -F[\(\)\ ] 'BEGIN{i=0}{NR=i;i++};END{print $8}' | tr -d "\n"]))

PACKAGE_NAME=`grep -i Revision ChangeLog | awk 'NR==1 {print tolower($4)}' | tr -d "\n"`
PACKAGE=$PACKAGE_NAME
PACKAGE_VERSION=`grep ^[[[:digit:]\.]] ChangeLog | awk 'NR==1 { max=$1 } NF>=1 { if ($1>max) max=$1; } END{print max}' | tr -d "\n"`
VERSION=$PACKAGE_VERSION
PACKAGE_RELEASE=`grep RELEASE ChangeLog|awk '{print $2}' | tr -d "\n"`
RELEASE=$PACKAGE_RELEASE
BITS=`if [[ 64 -eq $(getconf LONG_BIT) ]]; then echo -n $(getconf LONG_BIT); fi`
PACKAGE_MAJOR_VERSION=${PACKAGE_VERSION%%\.*}
PACKAGE_MINOR_VERSION=`echo $PACKAGE_VERSION | cut -d. -f2 | tr -d "\n"`
PACKAGE_MICRO_VERSION=${PACKAGE_VERSION##*\.}

ifdef([m4_pattern_allow], [m4_pattern_allow([LT_MAJOR])])
ifdef([m4_pattern_allow], [m4_pattern_allow([LT_REVISION])])
ifdef([m4_pattern_allow], [m4_pattern_allow([LT_AGE])])
ifdef([m4_pattern_allow], [m4_pattern_allow([LT_VERSION_INFO])])
LT_MAJOR=`grep 'lib\*\.so\.' ChangeLog | cut -d. -f3 | tr -d "\n"`
LT_REVISION=`grep 'lib\*\.so\.' ChangeLog | cut -d. -f4 | tr -d "\n"`
LT_AGE=`grep 'lib\*\.so\.' ChangeLog | cut -d. -f5 | cut -d';' -f1 | tr -d "\n"`
LT_VERSION_INFO=$LT_MAJOR:$LT_REVISION:$LT_AGE
DOXYGEN_OUTPUT_DIR=`grep DOXYGEN_OUTPUT_DIR ChangeLog | awk 'NR==1 {print $4}' | cut -d';' -f1 | tr -d "\n"`
URL=`grep visit ChangeLog | grep http | grep update | awk 'NR==1 {print $5}' | tr -d "\n"`
#CHANGELOG=`./tools/changelog.pl README ChangeLog`

AC_SUBST(PACKAGE_NAME)
AC_SUBST(PACKAGE_VERSION)
AC_SUBST(PACKAGE_RELEASE)
AC_SUBST(PACKAGE_MAJOR_VERSION)
AC_SUBST(PACKAGE_MINOR_VERSION)
AC_SUBST(PACKAGE_MICRO_VERSION)
AC_SUBST(LT_MAJOR)
AC_SUBST(LT_REVISION)
AC_SUBST(LT_AGE)
AC_SUBST(LT_VERSION_INFO)
AC_SUBST(BITS)
AC_SUBST(DOXYGEN_OUTPUT_DIR)
AC_SUBST(URL)
#AC_SUBST(CHANGELOG)

AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR([src/uc.h])
AM_CONFIG_HEADER([config.h])
AM_INIT_AUTOMAKE([tar-ustar])
AM_INIT_AUTOMAKE($PACKAGE, $VERSION)

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AM_PROG_CC_C_O
AC_PROG_LIBTOOL
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
dnl # AC_PROG_AWK
dnl # AC_PROG_GREP
dnl # AC_PROG_EGREP
dnl # AC_PROG_FGREP
AC_PROG_MKDIR_P
dnl # AC_PROG_LEX
dnl # AC_PROG_SED
dnl # AC_PROG_YACC
dnl # AC_PROG_RANLIB
dnl # CFLAGS="-g -Wall"
dnl # CXXFLAGS="-g -Wall"
dnl # LIBTOOL="$LIBTOOL --silent"

dnl # missing_dir=`cd $ac_aux_dir && pwd`
dnl # AM_MISSING_PROG(ACLOCAL, aclocal, $missing_dir)
dnl # AM_MISSING_PROG(AUTOCONF, autoconf, $missing_dir)
dnl # AM_MISSING_PROG(AUTOMAKE, automake, $missing_dir)
dnl # AM_MISSING_PROG(AUTOHEADER, autoheader, $missing_dir)
dnl # AM_MISSING_PROG(MAKEINFO, makeinfo, $missing_dir)


# Checks for libraries.
# FIXME: Replace `main' with a function in `-lJudy':
dnl AC_CHECK_LIB([Judy], [main], [], AC_MSG_FAILURE([pthread not found!]))
dnl AC_CHECK_LIB([config], [main], [], AC_MSG_FAILURE([pthread not found!]))
dnl AC_CHECK_LIB([anet], [main])
dnl AC_CHECK_LIB([log4cpp], [config_init])
# FIXME: Replace `main' with a function in `-lapstubs':
dnl AC_CHECK_LIB([apstubs], [main])
# FIXME: Replace `main' with a function in `-lboost_filesystem':
dnl AC_CHECK_LIB([boost_filesystem], [main])
# FIXME: Replace `main' with a function in `-lcppunit':
dnl AC_CHECK_LIB([cppunit], [main])
# FIXME: Replace `main' with a function in `-ldcp':
dnl AC_CHECK_LIB([dcp], [main])
# FIXME: Replace `main' with a function in `-ldcpwrap':
dnl AC_CHECK_LIB([dcpwrap], [main])
# FIXME: Replace `main' with a function in `-ldl':
dnl AC_CHECK_LIB([dl], [main])
# FIXME: Replace `main' with a function in `-lnsl':
dnl AC_CHECK_LIB([nsl], [main])
# FIXME: Replace `main' with a function in `-lprismaGet':
dnl AC_CHECK_LIB([prismaGet], [main])
# FIXME: Replace `main' with a function in `-lproxyio':
dnl AC_CHECK_LIB([proxyio], [main])
# FIXME: Replace `main' with a function in `-lpthread':
dnl AC_CHECK_LIB([pthread], [main])
# FIXME: Replace `main' with a function in `-lrt':
dnl AC_CHECK_LIB([rt], [main])
# FIXME: Replace `main' with a function in `-lxml2':
dnl AC_CHECK_LIB([xml2], [main])
# FIXME: Replace `main' with a function in `-lyavalon':
dnl AC_CHECK_LIB([yavalon], [main])
# FIXME: Replace `main' with a function in `-lydm':
dnl AC_CHECK_LIB([ydm], [main])
# FIXME: Replace `main' with a function in `-lyws':
dnl AC_CHECK_LIB([yws], [main])

# Checks for header files.
AC_HEADER_DIRENT
AC_HEADER_STDC
AC_CHECK_HEADERS([stdlib.h string.h])
dnl AC_HEADER_SYS_WAIT
dnl AC_CHECK_HEADERS([arpa/inet.h fcntl.h inttypes.h limits.h malloc.h memory.h netdb.h netinet/in.h stddef.h stdint.h stdlib.h string.h strings.h sys/ioctl.h sys/param.h sys/socket.h sys/statvfs.h sys/time.h unistd.h utime.h])
dnl AC_CHECK_HEADERS([arpa/inet.h fcntl.h netdb.h netinet/in.h string.h strings.h sys/socket.h sys/time.h unistd.h], [], [AC_MSG_FAILURE([headers checking failed!])])

# Checks for typedefs, structures, and compiler characteristics.
dnl AC_HEADER_STDBOOL
dnl AC_C_CONST
dnl AC_C_INLINE
dnl ifdef([m4_pattern_allow], [m4_pattern_allow([AC_TYPE_UINT32_T])])
dnl AC_TYPE_UINT32_T
dnl AC_TYPE_MODE_T
dnl AC_TYPE_OFF_T
dnl AC_TYPE_PID_T
dnl AC_TYPE_SIZE_T
dnl AC_CHECK_MEMBERS([struct stat.st_blksize])
dnl AC_HEADER_TIME
dnl AC_STRUCT_TM
dnl AC_C_VOLATILE
dnl AC_CHECK_TYPES([ptrdiff_t])

dnl AC_CHECK_HEADERS([ext/hash_map], [], AC_MSG_FAILURE([hash_map not found]))
dnl AC_RUN_IFELSE([AC_LANG_PROGRAM([[#include <ext/hash_map>]],
dnl                                [[#ifdef _BACKWARD_BACKWARD_WARNING_H
dnl                                  return 1;
dnl                                  #endif]])
dnl               ], 
dnl               [],
dnl               [CXXFLAGS="-Wno-deprecated $CXXFLAGS"])


# Checks for library functions.
dnl AC_FUNC_CLOSEDIR_VOID
dnl AC_FUNC_ERROR_AT_LINE
dnl AC_FUNC_FSEEKO
dnl AC_FUNC_LSTAT
dnl AC_FUNC_LSTAT_FOLLOWS_SLASHED_SYMLINK
dnl AC_FUNC_MALLOC
dnl AC_FUNC_MEMCMP
dnl AC_FUNC_MMAP
dnl AC_FUNC_REALLOC
dnl AC_FUNC_SETVBUF_REVERSED
dnl AC_TYPE_SIGNAL
dnl AC_FUNC_STAT
dnl AC_FUNC_STRFTIME
dnl AC_FUNC_STRTOD
dnl AC_FUNC_VPRINTF
dnl AC_CHECK_FUNCS([clock_gettime dup2 floor getcwd gethostbyname gethostname gethrtime getpagesize gettimeofday localtime_r memmove memset munmap regcomp socket sqrt strcasecmp strchr strdup strerror strncasecmp strpbrk strrchr strstr strtol strtoul])
AC_CHECK_FUNCS([memset])
dnl AC_CHECK_FUNCS([dup2 gethostbyname gethostname gettimeofday memmove memset\
dnl                 munmap socket strcasecmp strdup strerror],
dnl                [],
dnl                [AC_MSG_FAILURE([funcs check failed!])])


dnl AC_ARG_WITH(
		dnl [ydm],
		dnl [AS_HELP_STRING([--with-ydm], [where do ydm install @<:@default=/usr/local@:>@])],
		dnl [],
		dnl [with_ydm=/usr/local]
		dnl )

dnl AC_SUBST(with_ydm)

dnl AS_IF(
		dnl [test "x$with_ydm" != "xno"],
		dnl [ AC_MSG_RESULT([yes])
		dnl AC_MSG_NOTICE(checking ydm package path ...)
		dnl AS_IF(
			dnl [test "x$with_ydm" != "xyes"],
			dnl [ AC_MSG_NOTICE([checking ydm package path in $with_ydm ...]) 
            dnl    CPPFLAGS="$CPPFLAGS -I$with_ydm/include"
            dnl    LDFLAGS="$LDFLAGS -L$with_ydm/lib"
			dnl ],
			dnl [ AC_MSG_NOTICE([checking ydm package path in system default location]) ]
		dnl )
		dnl [LIBS="$LIBS -lydm"]
		dnl AC_CHECK_HEADERS([ydm/logger.h ydm/config.h],,
						dnl	[AC_MSG_FAILURE([checking ydm headers Failed])]
        dnl )
		dnl AC_CHECK_FILE([$with_ydm/lib/libydm.a],,
			dnl [ AC_MSG_FAILURE([checking ydm package path Failed]) ]
		dnl )
		dnl AC_LINK_IFELSE([AC_LANG_PROGRAM([[#include <ydm/logger.h>]],
                        dnl [[return ydm::logger::getRootLogger() ? 0 : 1;]])
            dnl         ],
            dnl         [AC_MSG_RESULT([OK])],
            dnl         [AC_MSG_FAILURE([getRootLogger() checking failure])]
		dnl	)
		dnl [YDM_FLAG="define HAVE_YDM"]
		dnl ],
        dnl [ AC_MSG_RESULT([no])
        dnl   [YDM_FLAG="undef HAVE_YDM"]
        dnl ]
	 dnl )

dnl AM_CONDITIONAL(WITH_YDM, test x$with_ydm != xno)

AC_CHECK_EXTRA_OPTIONS

AC_CONFIG_FILES([Makefile
				 uc.spec
				 uc.pc
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
				 tools/Makefile
				 Doxyfile])
AC_OUTPUT

dnl # AC_OUTPUT_COMMANDS([echo this is extra $fubar, and so on.], fubar=$fubar) 
