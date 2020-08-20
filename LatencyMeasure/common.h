/*
    LatencyMeasure

    (c) 2020 Christian.Lorenz@gromeck.de

    common definitions
*/
#ifndef __COMMON_H__
#define __COMMON_H__ 1

/*
**  in debug mode we produce more code and
**  timing accuracy is bad
*/
#define DBG             0

/*
**  the title of this sketch
*/
#if DBG
#define TITLE "DBG LatencyMeasure"
#else
#define TITLE "LatencyMeasure"
#endif

/*
**  pins for the buttons
*/
#define PIN_IN_BTNMODE  0
#define PIN_IN_BTNOK    1

/*
**  pin used as the trigger input -- IRQ capable!
*/
#define PIN_IN_TRIGGER      7
#define PIN_IN_ANALOG_UIN   A0
#define PIN_IN_ANALOG_UREF  A1

/*
**  pin for the calibration LED
*/
#define PIN_OUT_LED     4


/*
   max latency
*/
#define MAX_LATENCY  5000

/*
   convert the measured value on an analog pin to volts
*/
#define ANALOG2VOLTS(u)   ((float) (u) * 3.3 / 1024.0)

/*
   system includes
*/
#include <Arduino.h>
#include <stdarg.h>
#include <time.h>
#include "button.h"
#include "calibrate-sensor.h"
#include "config.h"
#include "display.h"
#include "device-info.h"
#include "measurement.h"
#include "test-timing.h"
#include "trigger.h"
#include "util.h"

#endif

/**/
