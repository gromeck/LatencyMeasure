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
  display_set_content("Place sensor over\ndark and bright areas");
  display_menu("MENU", "OK");

  if (button_wait() == 0)
    return;

  display_menu("EXIT", NULL);

  do {
    /*
       read the state and the voltage from the IO pins
    */
    short state = (digitalRead(PIN_IN_TRIGGER) == LOW);
    int uin = analogRead(PIN_IN_ANALOG_UIN);
    int uref = analogRead(PIN_IN_ANALOG_UREF);

    DbgMsg("pin=%d  state=%d  uin=%d  uref=%d", digitalRead(PIN_IN_TRIGGER), state, uin, uref);

    /*
       show the current values to let the user calibrate the device Uref
    */
    int uin_x00 = ANALOG2VOLTS(uin);
    int uin_0xx = (ANALOG2VOLTS(uin) - uin_x00) * 100;
    int uref_x00 = ANALOG2VOLTS(uref);
    int uref_0xx = (ANALOG2VOLTS(uref) - uref_x00) * 100;

    display_set_content("Uin =%1d.%02dV\nUref=%1d.%02dV   %s",
                        uin_x00, uin_0xx,
                        uref_x00, uref_0xx,
                        (state) ? "BRIGHT" : "DARK");
    display_flush();
  } while (button_state(NULL) < 0);
}

#endif

/**/
