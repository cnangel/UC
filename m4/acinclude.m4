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

