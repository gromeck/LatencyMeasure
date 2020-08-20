/*
    LatencyMeasure

    (c) 2020 Christian.Lorenz@gromeck.de

    util definitions and prototypes
*/
#ifndef __UTIL_H__
#define __UTIL_H__ 1

#include "common.h"

#if DBG
/*
**  debug message
*/
#define DbgMsg  LogMsg
#else
#define DbgMsg(...)
#endif


/*
**  log a smessage to serial
*/
void LogMsg(const char *fmt, ...);

#endif

/**/
