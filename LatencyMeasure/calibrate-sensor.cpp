/*
    LatencyMeasure

    (c) 2020 Christian.Lorenz@gromeck.de

    module to handle the sensor calibration
*/
#include "calibrate-sensor.h"

void calibrate_sensor(void)
{
  display_set_content("Place sensor over\ndark and bright areas");
  display_menu("MENU", "OK");
  display_flush();
  if (button_wait() == 0)
    return;

  display_menu("EXIT", NULL);
  display_flush();

  do {
    /*
       read the state and the voltage from the IO pins
    */
    short state = (digitalRead(PIN_IN_TRIGGER) == LOW);
    int uin = analogRead(PIN_IN_ANALOG_UIN);
    int uref = analogRead(PIN_IN_ANALOG_UREF);

    LogMsg("pin=%d  state=%d  uin=%d  uref=%d", digitalRead(PIN_IN_TRIGGER), state, uin, uref);

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
}/**/
