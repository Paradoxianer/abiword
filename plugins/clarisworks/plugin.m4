
clarisworks_pkgs="$gsf_req"

CLARISWORKS_CFLAGS=
CLARISWORKS_LIBS=

if test "$enable_clarisworks" == "yes"; then

PKG_CHECK_MODULES(CLARISWORKS,[ $clarisworks_pkgs ])

CLARISWORKS_CFLAGS="$CLARISWORKS_CFLAGS "'${PLUGIN_CFLAGS}'
CLARISWORKS_LIBS="$CLARISWORKS_LIBS "'${PLUGIN_LIBS}'

fi

AC_SUBST([CLARISWORKS_CFLAGS])
AC_SUBST([CLARISWORKS_LIBS])
