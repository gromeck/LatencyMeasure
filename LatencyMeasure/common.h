/*
  LatencyMeasure
  
  (c) 2020 Christian.Lorenz@gromeck.de
  
  common definitions
  
  
  This file is part of LatencyMeasure.
  
  LatencyMeasure is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  LatencyMeasure is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with LatencyMeasure.  If not, see <https://www.gnu.org/licenses/>.

*/
#ifndef __COMMON_H__
#define __COMMON_H__ 1

#define SERIAL_BAUDRATE           115200

/*
**  in debug mode we produce more code and
**  timing accuracy is bad
*/
#define DEBUG                     0

#if DEBUG
#define FEATURE_CONFIG_MENU       0
#define FEATURE_TEST_TIMING       1
#define FEATURE_CALIBRATE_SENSOR  1
#define FEATURE_DEVICE_INFO       1
#define FEATURE_SCREENSHOT        1
#else
#define FEATURE_CONFIG_MENU       1
#define FEATURE_TEST_TIMING       1
#define FEATURE_CALIBRATE_SENSOR  1
#define FEATURE_DEVICE_INFO       1
#define FEATURE_SCREENSHOT        1
#endif

/*
**  the title of this sketch
*/
#define TITLE "LatencyMeasure"

//#define GITHUB_URL  "https://github.com/gromeck/LatencyMeasure"
#define GITHUB_URL  "github.com/gromeck/" TITLE

/*
**  pins for the buttons
*/
#define PIN_IN_BTNMODE    0
#define PIN_IN_BTNOK      1
#if FEATURE_SCREENSHOT
#define PIN_IN_SCREENSHOT 4
#endif

/*
**  pin used as the trigger input -- IRQ capable!
*/
#define PIN_IN_TRIGGER      7
#define PIN_IN_ANALOG_UIN   A0
#define PIN_IN_ANALOG_UREF  A1

/*
**  pin for the calibration LED
*/
#define PIN_OUT_LED       5


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
