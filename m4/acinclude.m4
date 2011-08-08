dnl $Id: acinclude.m4,v 1.0.0-0 2010/06/15 12:11:09 Cnangel Exp $

dnl -------------------------------------------------------------------------
dnl AC_CHECK_EXTRA_OPTIONS
dnl -------------------------------------------------------------------------
AC_DEFUN([AC_CHECK_EXTRA_OPTIONS],[

dnl -------------------------------------------------------------------------
dnl Enable debug with -g -Wall -D_DEBUG
dnl -------------------------------------------------------------------------
AC_MSG_CHECKING(for debugging)
AC_ARG_ENABLE(debug, [  --enable-debug          compile for debugging @<:@default=yes@:>@])
if test -z "$enable_debug" ; then
	CFLAGS="${CFLAGS} -g -Wall -D_DEBUG"
	CXXFLAGS="${CXXFLAGS} -g -Wall -D_DEBUG"
elif test $enable_debug != "yes" ; then
	enable_debug="no"
	CFLAGS="${CFLAGS} -g -O2"
	CXXFLAGS="${CXXFLAGS} -g -O2"
else
	enable_debug="yes"
	CFLAGS="${CFLAGS} -g -Wall -D_DEBUG"
	CXXFLAGS="${CXXFLAGS} -g -Wall -D_DEBUG"
fi
AC_MSG_RESULT([$enable_debug])


dnl -------------------------------------------------------------------------
dnl Enable profile with -pg
dnl -------------------------------------------------------------------------
AC_MSG_CHECKING(for profiling)
AC_ARG_ENABLE(profile, [  --enable-profile          compile for profiling @<:@default=no@:>@])
if test "x$enable_profile" == "xyes" ; then
	enable_profile="yes"
	CFLAGS="${CFLAGS} -pg";
	CXXFLAGS="${CXXFLAGS} -pg";
else
	enable_profile="no"
fi
AC_MSG_RESULT([$enable_profile])


dnl -------------------------------------------------------------------------
dnl Enable test options with -fstack-protector -fstack-protector-all -fprofile-arcs -ftest-coverage 
dnl -------------------------------------------------------------------------
AC_ARG_ENABLE([test],
		[AS_HELP_STRING([--enable-test],
			[enable test options with -fprofile-arcs -ftest-coverage @<:@default=no@:>@])],
		[],
		[enable_test=no]
		)
AC_MSG_CHECKING([whether do enable test options support])
AS_IF([test "x$enable_test" = "xyes"],
		[
			GCC_VERSION=`gcc -dumpversion | sed 's/\([[0-9]]\{1,\}\.[[0-9]]\{1,\}\)\.*\([[0-9]]\{1,\}\)\{0,1\}/\1\2/'`
			AS_IF([expr $GCC_VERSION '>=' 4 >/dev/null],
				[
					CFLAGS="${CFLAGS} -fstack-protector -fstack-protector-all -fprofile-arcs -ftest-coverage"
					CXXFLAGS="${CXXFLAGS} -fstack-protector -fstack-protector-all -fprofile-arcs -ftest-coverage"
				],
				[
					CFLAGS="${CFLAGS} -fprofile-arcs -ftest-coverage"
					CXXFLAGS="${CXXFLAGS} -fprofile-arcs -ftest-coverage"
				])
			AC_MSG_RESULT([yes])
		],
		[
			AC_MSG_RESULT([no])
		]
	 )
AM_CONDITIONAL(ENABLE_TEST_OPTIONS, test x$enable_test != xno)



])

dnl -------------------------------------------------------------------------
dnl MY_ARG_WITH
dnl -------------------------------------------------------------------------
AC_DEFUN([MY_ARG_WITH],

[AC_ARG_WITH(m4_translit([[$1]], [_], [-]), 
	[AS_HELP_STRING([--with-m4_translit([$1], [_], [-])], [use $1 @<:@default is $2@:>@])],
	[use_[]$1=$withval],
	[use_[]$1=$2]
)

])

AC_DEFUN([uc_WITH_BUILD_PATH],
[
    AC_ARG_WITH([build-path],
    [  --with-build-path=DIR   build using DIR/include and DIR/lib],
    [
        for d in `echo $withval | tr : ' '`; do
            test -d $d/include &amp;&amp; CPPFLAGS="$CPPFLAGS -I$d/include"
            test -d $d/lib &amp;&amp; LDFLAGS="$LDFLAGS -L$d/lib"
        done
    ])
])

