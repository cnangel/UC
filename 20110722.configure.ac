#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
dnl $Id: configure.ac,v 1.0.1 2009/07/29 17:58:36 Cnangel Exp $

AC_PREREQ([2.59])
# define([UC_MAJOR_VERSION],[0])
# define([UC_MINOR_VERSION],[0])
# define([UC_MICRO_VERSION],[1])
# m4_define([version_major], [0])
# m4_define([version_minor], [3])
# m4_define([version_revision], [1])
# m4_define([version_suffix], [])
# m4_define([version_full], m4_format([%d.%d.%d%s], version_major, version_minor, version_revision, version_suffix))
AC_REVISION($Revision: esyscmd([grep -i Revision ChangeLog | awk 'NR==1 {print $5}' | tr -d "\n"]) $)dnl
dnl # AC_INIT (package, version, [bug-report], [tarname], [url])
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
#                    |          |          |
#                  +-+	    +---+   +------+
#                  |		|       |
#                 current:revision:age
#                  |        |     |
#                  |        |     +- increment if interfaces have been added
#                  |        |        set to zero if interfaces have been removed or changed
#                  |        +- increment if source code has changed
#                  |           set to zero if current is incremented
#                  +- increment if interfaces have been added, removed or changed
DOXYGEN_OUTPUT_DIR=`grep DOXYGEN_OUTPUT_DIR ChangeLog | awk 'NR==1 {print $4}' | cut -d';' -f1 | tr -d "\n"`
PACKAGE_URL=`grep visit ChangeLog | grep http | grep update | awk 'NR==1 {print $5}' | tr -d "\n"`
#CHANGELOG=`./tools/changelog.pl README ChangeLog`
GCC_VERSION=`gcc -dumpversion | sed 's/\([[0-9]]\{1,\}\.[[0-9]]\{1,\}\)\.*\([[0-9]]\{1,\}\)\{0,1\}/\1\2/'`
MK=''

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
AC_SUBST(PACKAGE_URL)
#AC_SUBST(CHANGELOG)
AC_SUBST(MK)

missing_dir=`mkdir -p m4`
AC_CONFIG_MACRO_DIR([m4])
#AM_CONFIG_HEADER([config.h])
AC_CONFIG_SRCDIR([src/config.h.in])
AC_CONFIG_HEADER([config.h])
AM_INIT_AUTOMAKE([tar-ustar])
AM_INIT_AUTOMAKE($PACKAGE, $VERSION)

# Checks for programs.
AC_PROG_CXX
AC_PROG_AWK
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
ifdef([m4_pattern_allow], [m4_pattern_allow([AC_PROG_MKDIR_P])])
dnl # AC_PROG_LEX
dnl # AC_PROG_SED
dnl # AC_PROG_YACC
dnl # AC_PROG_RANLIB
dnl # AC_LANG_CPLUSPLUS
dnl # CFLAGS="-g -Wall"
dnl # CXXFLAGS="-g -Wall"
dnl # LIBTOOL="$LIBTOOL --silent"
dnl # soname_spec="\${libname}\${shared_ext}"

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
# Checking hashmap
dnl AC_CHECK_HEADERS([ext/hash_map], [], AC_MSG_FAILURE([hash_map not found]))
dnl AC_RUN_IFELSE([AC_LANG_PROGRAM([[#include <ext/hash_map>]],
							   dnl [[#ifdef _BACKWARD_BACKWARD_WARNING_H
								 dnl return 1;
								 dnl #endif]])
			  dnl ], 
			  dnl [],
			  dnl [CXXFLAGS="-Wno-deprecated $CXXFLAGS"])

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


# Checks for ydm libraries.
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

# Checks for alog libraries.
dnl AC_ARG_WITH([alog],
  dnl [AS_HELP_STRING([--with-alog],
    dnl [do logging with alog @<:@default=yes@:>@])],
  dnl [],
  dnl [with_alog=yes])

dnl AC_SUBST([ALOG_FLAG])

dnl AC_MSG_CHECKING([whether do logging with alog])
dnl AS_IF([test "x$with_alog" != "xno"],
      dnl [ AC_MSG_RESULT([yes])
        dnl AC_MSG_NOTICE(checking alog library...)
        dnl AS_IF([test "x$with_alog" != "xyes"],
              dnl [AC_MSG_NOTICE([checking alog in $with_alog...])
               dnl CPPFLAGS="$CPPFLAGS -I$with_alog/include"
               dnl LDFLAGS="$LDFLAGS -L$with_alog/lib${BITS}"
              dnl ], 
              dnl [AC_MSG_NOTICE([checking alog in system default location])]
             dnl )

        dnl [LIBS="$LIBS -lalog"]
        dnl AC_CHECK_HEADERS([alog/Logger.h alog/Configurator.h],,
                         dnl [AC_MSG_FAILURE([checking alog headers Failed])]
                        dnl )
        dnl AC_LINK_IFELSE([AC_LANG_PROGRAM([[#include <alog/Logger.h>]],
                             dnl [[return alog::Logger::getRootLogger() ? 0 : 1;]])
                       dnl ],
                       dnl [AC_MSG_RESULT([checking for alog... OK])],
                       dnl [AC_MSG_FAILURE([getRootLogger() checking failure])]
                      dnl )
        dnl [ALOG_FLAG="define HAVE_ALOG"]
      dnl ],
      dnl [ AC_MSG_RESULT([no])
        dnl [ALOG_FLAG="undef HAVE_ALOG"]
      dnl ]
     dnl )  

dnl AC_ARG_ENABLE([iconv],
		dnl [AS_HELP_STRING([--enable-iconv], [enable iconv support.])],
		dnl [],
		dnl [enable_iconv=no]
		dnl )
dnl AC_MSG_CHECKING([whether do enable iconv support])
dnl AS_IF([test "x$enable_iconv" = "xyes"],
		dnl [
			dnl AC_MSG_RESULT([yes])
			dnl AC_CHECK_LIB([iconv], [main])
		dnl ],
		dnl [
			dnl AC_MSG_RESULT([no])
		dnl ]
	 dnl )

AC_ARG_WITH([libiconv],
		[AS_HELP_STRING([--with-libiconv], [with libiconv support.])],
		[],
		[with_libiconv=no]
		)
AC_MSG_CHECKING([whether do with libiconv support])
AS_IF([test "x$with_libiconv" = "xyes"],
		[
			AC_MSG_RESULT([yes])
			AC_CHECK_LIB([iconv], [main])
		],
		[
			AC_MSG_RESULT([no])
		]
	 )

AC_CHECK_EXTRA_OPTIONS
MY_ARG_WITH([a_b], [no])
MY_ARG_WITH([abcd], [yes])

dnl # all_includes="$all_includes -I/usr/include/foo"
dnl # all_libraries="$all_libraries -L/usr/lib/foo"

# Check for rst2html
dnl AC_ARG_VAR(RST2HTML, [rst2html path])
dnl AC_PATH_PROGS(RST2HTML, [rst2html rst2html.py], [])
dnl 
dnl if test -z "$RST2HTML"
dnl then
dnl   AC_MSG_WARN([rst2html not found, documentation rebuild will not be possible])
dnl fi

AC_ARG_ENABLE(gcov,
    AS_HELP_STRING([--enable-gcov],
        [enable test coverage with gcov @<:@default=no@:>@]),
        [case "${enableval}" in
           yes) gcov=true ;;
           no)  gcov=false ;;
           *)   AC_MSG_ERROR([bad value ${enableval} for --enable-gcov]) ;;
         esac],
   [gcov=false])

AM_CONDITIONAL(GCOV, test x"$gcov" = "xtrue")

AC_SUBST(GCC_GCOV_CFLAGS,
["\
-fprofile-arcs \
-ftest-coverage \
-lgcov \
"])

AM_CONDITIONAL(PLATFORM64, test x$BITS != x)
AM_CONDITIONAL(GCC4, expr $GCC_VERSION '>=' 4 >/dev/null)

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

dnl # AC_OUTPUT_COMMANDS([echo this is extra $fubar, and so on.], fubar=$fubar) 
