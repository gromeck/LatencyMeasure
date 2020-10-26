/*
  LatencyMeasure

  (c) 2020 Christian.Lorenz@gromeck.de

  module to handle the sensor calibration


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
#include "calibrate-sensor.h"

#if FEATURE_CALIBRATE_SENSOR

void calibrate_sensor(void)
{
  int uref;
  int uin;
  int uin_min = ANALOG2VOLTS(ANALOG_RESOLUTION);
  int uin_max = 0;
  int uref_opt;

  display_set_content("Place sensor over\nsensor area");
  display_menu("MENU", "OK");

  if (button_wait() == 0)
    return;

  display_menu("EXIT", NULL);

  do {
    /*
       read the state and the voltage from the IO pins
    */
    short state = (digitalRead(PIN_IN_TRIGGER) == LOW);
    uref = analogRead(PIN_IN_ANALOG_UREF);
    uin = analogRead(PIN_IN_ANALOG_UIN);

    /*
       compute the optimal Uref
    */
    if (uin < uin_min)
      uin_min = uin;
    if (uin > uin_max)
      uin_max = uin;
    uref_opt = (uin_min + uin_max) / 2;

    DbgMsg("pin=%d  state=%d  Uin(min/max)=%d(%d/%d)  Uref(opt)=%d(%d)", digitalRead(PIN_IN_TRIGGER), state, uin, uin_min, uin_max, uref, uref_opt);

    /*
       show the current values to let the user calibrate the device Uref
    */
    display_set_content("Uref=%4dmV \033 %4dmV\nUin =%4dmV  %s",
                        ANALOG2VOLTS(uref),
                        ANALOG2VOLTS(uref_opt),
                        ANALOG2VOLTS(uin),
                        (state) ? "BRIGHT" : "DARK");

    display_flush();
  } while (button_state(NULL) < 0);
}

#endif

/**/
