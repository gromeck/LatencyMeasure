/*
  LatencyMeasure

  (c) 2020 Christian.Lorenz@gromeck.de

  sensortest definitions and prototypes


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
#ifndef __SENSORTEST_H__
#define __SENSORTEST_H__ 1

#include "common.h"

#if FEATURE_CALIBRATE_SENSOR

/*
   convert the measured value on an analog pin to milli volts
*/
#define MAX_VOLTAGE            3300
#define ANALOG_RESOLUTION      1024
#define ANALOG2VOLTS(u)        ((long) (u) * MAX_VOLTAGE / (ANALOG_RESOLUTION - 1))

/*
 * compute the optimal Uref out of Uin,min and Uin,max
 * 
 * empiric test showed that not the arithmetic middle gives the best results, but the following term
 */
#define CALIBRATION_UREF_OPT(umin,umax) ((umin) + ((umax) - (umin)) * 8 / 10)

/*
 * the "calibration ok" is in the window of +/-3% of the max voltage arround the optimal Uref
 */
#define CALIBRATION_MAX_DELTA           (MAX_VOLTAGE / 100 * 3)

void calibrate_sensor(void);

#endif

#endif

/**/
