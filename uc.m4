# Configure paths for UC
# Owen Taylor     97-11-3

dnl AM_PATH_UC([MINIMUM-VERSION, [ACTION-IF-FOUND [, ACTION-IF-NOT-FOUND]]])
dnl Test for UC, and define UC_CFLAGS and UC_LIBS
dnl
AC_DEFUN([AM_PATH_UC],
[dnl 
dnl Get the cflags and libraries from the uc-config script
dnl
AC_ARG_WITH(uc-prefix,[  --with-uc-prefix=PFX   Prefix where UC is installed (optional)],
            uc_config_prefix="$withval", uc_config_prefix="")
AC_ARG_WITH(uc-exec-prefix,[  --with-uc-exec-prefix=PFX Exec prefix where UC is installed (optional)],
            uc_config_exec_prefix="$withval", uc_config_exec_prefix="")
AC_ARG_ENABLE(uctest, [  --disable-uctest       Do not try to compile and run a test UC program],
		    , enable_uctest=yes)

  if test x$uc_config_exec_prefix != x ; then
     uc_config_args="$uc_config_args --exec-prefix=$uc_config_exec_prefix"
     if test x${UC_CONFIG+set} != xset ; then
        UC_CONFIG=$uc_config_exec_prefix/bin/uc-config
     fi
  fi
  if test x$uc_config_prefix != x ; then
     uc_config_args="$uc_config_args --prefix=$uc_config_prefix"
     if test x${UC_CONFIG+set} != xset ; then
        UC_CONFIG=$uc_config_prefix/bin/uc-config
     fi
  fi

  AC_PATH_PROG(UC_CONFIG, uc-config, no)
  min_uc_version=ifelse([$1], ,0.99.7,$1)
  AC_MSG_CHECKING(for UC - version >= $min_uc_version)
  no_uc=""
  if test "$UC_CONFIG" = "no" ; then
    no_uc=yes
  else
    UC_CFLAGS=`$UC_CONFIG $uc_config_args --cflags`
    UC_LIBS=`$UC_CONFIG $uc_config_args --libs`
    uc_config_major_version=`$UC_CONFIG $uc_config_args --version | \
           sed 's/\([[0-9]]*\).\([[0-9]]*\).\([[0-9]]*\)/\1/'`
    uc_config_minor_version=`$UC_CONFIG $uc_config_args --version | \
           sed 's/\([[0-9]]*\).\([[0-9]]*\).\([[0-9]]*\)/\2/'`
    uc_config_micro_version=`$UC_CONFIG $uc_config_args --version | \
           sed 's/\([[0-9]]*\).\([[0-9]]*\).\([[0-9]]*\)/\3/'`
    if test "x$enable_uctest" = "xyes" ; then
      ac_save_CFLAGS="$CFLAGS"
      ac_save_CXXFLAGS="$CXXFLAGS"
      ac_save_LIBS="$LIBS"
      CFLAGS="$CFLAGS $UC_CFLAGS"
      CXXFLAGS="$CXXFLAGS $UC_CFLAGS"
      LIBS="$UC_LIBS $LIBS"
dnl
dnl Now check if the installed UC is sufficiently new. (Also sanity
dnl checks the results of uc-config to some extent
dnl
      rm -f conf.uctest
      AC_TRY_RUN([
#include <uc/Category.hh>
#include <stdio.h>
#include <stdlib.h>

int 
main ()
{
  int uc_major, uc_minor, uc_micro;
  int major, minor, micro;
  char *tmp_version;
  char *tmp_uc_version;

  system ("touch conf.uctest");

  /* HP/UX 9 (%@#!) writes to sscanf strings */
  tmp_version = strdup("$min_uc_version");
  if (sscanf(tmp_version, "%d.%d.%d", &major, &minor, &micro) != 3) {
     printf("%s, bad version string\n", "$min_uc_version");
     exit(1);
   }

   /* HP/UX 9 (%@#!) writes to sscanf strings */
   tmp_uc_version = strdup(UC_VERSION);
   if (sscanf(tmp_uc_version, "%d.%d.%d", &uc_major, &uc_minor, &uc_micro) != 3) {
     printf("%s, bad uc version string\n", UC_VERSION);
     exit(1);
   }

   if ((uc_major > major) ||
      ((uc_major == major) && (uc_minor > minor)) ||
      ((uc_major == major) && (uc_minor == minor) && (uc_micro >= micro)))
   {
        return 0;
   }
   else
   {
        printf("\n*** An old version of UC (%d.%d.%d) was found.\n",
               uc_major, uc_minor, uc_micro);
        printf("*** You need a version of UC newer than %d.%d.%d. The latest version of\n",
	       major, minor, micro);
        printf("***\n");
        printf("*** If you have already installed a sufficiently new version, this error\n");
        printf("*** probably means that the wrong copy of the uc-config shell script is\n");
        printf("*** being found. The easiest way to fix this is to remove the old version\n");
        printf("*** of UC, but you can also set the UC_CONFIG environment to point to the\n");
        printf("*** correct copy of uc-config. (In this case, you will have to\n");
        printf("*** modify your LD_LIBRARY_PATH enviroment variable, or edit /etc/ld.so.conf\n");
        printf("*** so that the correct libraries are found at run-time))\n");
   }

   uc::Category& log = uc::UCCpp::getRoot();
   return 1;
}
],, no_uc=yes,[echo $ac_n "cross compiling; assumed OK... $ac_c"])
       CFLAGS="$ac_save_CFLAGS"
       CXXFLAGS="$ac_save_CXXFLAGS"
       LIBS="$ac_save_LIBS"
     fi
  fi
  if test "x$no_uc" = x ; then
     AC_MSG_RESULT(yes)
     ifelse([$2], , :, [$2])     
  else
     AC_MSG_RESULT(no)
if test "$UC_CONFIG" = "no" ; then
echo "*** The uc-config script installed by UC could not be found"
       echo "*** If UC was installed in PREFIX, make sure PREFIX/bin is in"
       echo "*** your path, or set the UC_CONFIG environment variable to the"
       echo "*** full path to uc-config."
     else
       if test -f conf.uctest ; then
        :
       else
          echo "*** Could not run UC test program, checking why..."
          CFLAGS="$CFLAGS $UC_CFLAGS"
          CXXFLAGS="$CXXFLAGS $UC_CFLAGS"
          LIBS="$LIBS $UC_LIBS"
          AC_TRY_LINK([
#include <uc/uc.h>
],      [ uc::UCCpp::getRoot(); return 0; ],
        [ echo "*** The test program compiled, but did not run. This usually means"
          echo "*** that the run-time linker is not finding UC or finding the wrong"
          echo "*** version of UC. If it is not finding UC, you'll need to set your"
          echo "*** LD_LIBRARY_PATH environment variable, or edit /etc/ld.so.conf to point"
          echo "*** to the installed location  Also, make sure you have run ldconfig if that"
          echo "*** is required on your system"
	  echo "***"
          echo "*** If you have an old version installed, it is best to remove it, although"
          echo "*** you may also be able to get things to work by modifying LD_LIBRARY_PATH"
          echo "***" ],
        [ echo "*** The test program failed to compile or link. See the file config.log for the"
          echo "*** exact error that occured. This usually means UC was incorrectly installed"
          echo "*** or that you have moved UC since it was installed. In the latter case, you"
          echo "*** may want to edit the uc-config script: $UC_CONFIG" ])
          CFLAGS="$ac_save_CFLAGS"
          CXXFLAGS="$ac_save_CXXFLAGS"
          LIBS="$ac_save_LIBS"
       fi
     fi
     UC_CFLAGS=""
     UC_LIBS=""
     ifelse([$3], , :, [$3])
  fi
  AC_SUBST(UC_CFLAGS)
  AC_SUBST(UC_LIBS)
  rm -f conf.uctest
])
