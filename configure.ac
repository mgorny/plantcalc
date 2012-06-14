AC_PREREQ([2.60])
AC_INIT([plantcalc], [0])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([1.6 foreign dist-bzip2 subdir-objects])

m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES])

PKG_CHECK_MODULES([LIBH2OXX], [libh2oxx >= 0.2])

AC_PROG_CXX

LT_INIT([disable-static win32-dll])

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
