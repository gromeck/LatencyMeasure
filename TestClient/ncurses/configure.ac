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


######################################
#
#	Change some defaults.
#
test "$prefix" = NONE && prefix=/usr
test "$exec_prefix" = NONE && exec_prefix=$prefix
test "$sysconfdir" = '${prefix}/etc' && sysconfdir=/etc
test "$localstatedir" = '${prefix}/var' && localstatedir=/var/run
test "$mandir" = '${prefix}/man' && mandir=/usr/share/man
#echo "prefix=$prefix"
#echo "exec_prefix=$exec_prefix"
#echo "sysconfdir=$sysconfdir"
#echo "localstatedir=$localstatedir"
#echo "mandir=$mandir"


# debug
AC_ARG_ENABLE(debug,
		[  --enable-debug          enable debugging support],
			       DEBUGGING_ENABLED="$enableval",DEBUGGING_ENABLED=no)
AM_CONDITIONAL(DEBUGGING_ENABLED, test "$DEBUGGING_ENABLED" = yes)

# static
AC_ARG_ENABLE(static,
		[  --enable-static         enable static build],
			       STATIC_ENABLED="$enableval",STATIC_ENABLED=no)
AM_CONDITIONAL(STATIC_ENABLED, test "$STATIC_ENABLED" = yes)


#######################################
#
#	Checks for programs.
#
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_MAKE_SET
AC_PROG_RANLIB


#######################################
#
#	Checks for libraries.
#
AC_CHECK_LIB(m,main)
AC_CHECK_LIB(ncurses,main,,exit 1)

#######################################
#
#	Checks for header files.
#
AC_HEADER_DIRENT
AC_HEADER_STDC
AC_HEADER_SYS_WAIT

#######################################
#
#	Checks for typedefs, structures, and compiler characteristics.
#
AC_C_CONST
AC_C_INLINE
AC_TYPE_MODE_T
AC_TYPE_OFF_T
AC_TYPE_PID_T
AC_TYPE_SIZE_T
AC_HEADER_TIME
AC_STRUCT_TM
AC_TYPE_UID_T
AC_C_VOLATILE
AC_CHECK_TYPES([ptrdiff_t])


#######################################
#
#	Checks for library functions.
#
AC_FUNC_ALLOCA
AC_FUNC_CHOWN
AC_FUNC_CLOSEDIR_VOID
AC_FUNC_ERROR_AT_LINE
AC_FUNC_GETPGRP
AC_PROG_GCC_TRADITIONAL
AC_FUNC_MALLOC
AC_FUNC_MEMCMP
AC_FUNC_MKTIME
AC_FUNC_SELECT_ARGTYPES


#######################################
#
#	config.h defines
#
AC_DEFINE_UNQUOTED(LOCALSTATEDIR,"$( eval echo $localstatedir )","local state directory")
AC_DEFINE_UNQUOTED(SYSCONFDIR,"$( eval echo $sysconfdir )","system configuration directory")
AC_DEFINE(__VERSION_NR__,VERSION,"Version Number")


#######################################
#
#	CFLAGS
#
if test "$DEBUGGING_ENABLED" = yes; then
	CFLAGS_DEFS="$CFLAGS_DEFS -DDEBUGGING=1"
fi
if test "$STATIC_ENABLED" = yes; then
	CFLAGS_DEFS="$CFLAGS_DEFS -static"
fi
CFLAGS="$CFLAGS -g -fno-strict-aliasing -fPIC -Wall"
CFLAGS="$CFLAGS -D_GNU_SOURCE"
CFLAGS="$CFLAGS $CFLAGS_DEFS"


#
#	find all Makefiles
#
#AC_CONFIG_FILES($( find . -name Makefile.am -printf "%h/Makefile " ))
AC_CONFIG_FILES([ \
			Makefile \
				  ])

AC_OUTPUT

