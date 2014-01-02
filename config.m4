dnl $Id$
dnl config.m4 for extension smaz

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(smaz, for smaz support,
dnl Make sure that the comment is aligned:
dnl [  --with-smaz             Include smaz support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(smaz, whether to enable smaz support,
Make sure that the comment is aligned:
[  --enable-smaz           Enable smaz support])

if test "$PHP_SMAZ" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-smaz -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/smaz.h"  # you most likely want to change this
  dnl if test -r $PHP_SMAZ/$SEARCH_FOR; then # path given as parameter
  dnl   SMAZ_DIR=$PHP_SMAZ
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for smaz files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       SMAZ_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$SMAZ_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the smaz distribution])
  dnl fi

  dnl # --with-smaz -> add include path
  dnl PHP_ADD_INCLUDE($SMAZ_DIR/include)

  dnl # --with-smaz -> check for lib and symbol presence
  dnl LIBNAME=smaz # you may want to change this
  dnl LIBSYMBOL=smaz # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $SMAZ_DIR/lib, SMAZ_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_SMAZLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong smaz lib version or lib not found])
  dnl ],[
  dnl   -L$SMAZ_DIR/lib -lm
  dnl ])
  dnl
  dnl PHP_SUBST(SMAZ_SHARED_LIBADD)

  PHP_NEW_EXTENSION(smaz, smaz.c, $ext_shared)
fi
