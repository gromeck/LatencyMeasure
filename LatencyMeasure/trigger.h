/*
    LatencyMeasure

    (c) 2020 Christian.Lorenz@gromeck.de

    trigger definitions and prototypes
*/

#ifndef __TRIGGER_H__
#define __TRIGGER_H__ 1

#include "common.h"

void trigger_init(int pin);

void trigger_reset(void);
unsigned long trigger_wait(int timetowait);
unsigned long trigger_time(void);

#endif

/**/
