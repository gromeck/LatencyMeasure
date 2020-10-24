#
#	configure.ac
#
#	Copyright (c) 2020 by Christian Lorenz
#
#	Process this file with autoconf to produce a configure script.
#

AC_INIT([LatencyTest], [m4_esyscmd_s([cat VERSION])])
AC_CONFIG_SRCDIR([.])
AM_INIT_AUTOMAKE
AM_CONFIG_HEADER(config.h)
AC_PROG_CC

# static
AC_ARG_ENABLE(static,
		[  --enable-static         enable static build],
			       STATIC_ENABLED="$enableval",STATIC_ENABLED=no)
AM_CONDITIONAL(STATIC_ENABLED, test "$STATIC_ENABLED" = yes)

#######################################
#
#	CFLAGS & LIBS
#
PKGCONFIG_FLAGS=""
if test "$STATIC_ENABLED" = yes; then
	PKGCONFIG_FLAGS="--static"
	CFLAGS="$CFLAGS --static"
fi
CFLAGS="$CFLAGS -g -fno-strict-aliasing -fPIC -Wall"
CFLAGS="$CFLAGS -D_GNU_SOURCE"
CFLAGS="$CFLAGS $( pkg-config gtk+-3.0 $PKGCONFIG_FLAGS --cflags )"
LIBS="$LIBS $( pkg-config gtk+-3.0 $PKGCONFIG_FLAGS --libs )"

#
#	find all Makefiles
#
AC_CONFIG_FILES([ Makefile ])
AC_OUTPUT
