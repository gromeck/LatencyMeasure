/*
  LatencyMeasure

  (c) 2020 Christian.Lorenz@gromeck.de

  This sketch uses an Arduino device to send HID events via USB keyboard
  resp. mouse to a PC/workstation. This device also uses a sensor to detect
  a reaction on the PC/workstation screen.
  The time between the HID event and the reaction on the screen is the
  HMI latency on that PC/workstation.

  sime simple programs has to used on the PC/workstation to react on the
  HID device and switch a detectable field from white to black.
  Mulitple implementation (eg. HTML, Qt) are available in this software
  distribution.


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
#include "common.h"

/*
   the main menu with all function to call
*/
typedef struct {
  const char *title;
  void (*func)(void);
} MAIN_MENU;

static MAIN_MENU _main_menu[] = {
  { "Measurement", measurement_measure },
#if FEATURE_CONFIG_MENU
  { "Configure", config_menu },
#endif
#if FEATURE_TEST_TIMING
  { "Test Timing", test_timing },
#endif
#if FEATURE_CALIBRATE_SENSOR
  { "Calibrate Sensor", calibrate_sensor },
#endif
#if FEATURE_DEVICE_INFO
  { "Device Info", device_info },
#endif
  { NULL }
};

/*
**  operating mode
*/
static int _mode = -1;

/*
**  setup called once on powerup
*/
void setup()
{
  /*
     init the serial interface
  */
#if DEBUG
  Serial.begin(SERIAL_BAUDRATE);
  delay(1000);
  DbgMsg(TITLE ": starting up");
#endif

  /*
  ** configure other IO pins
  */
  pinMode(PIN_OUT_LED, OUTPUT);
  analogReference(INTERNAL);
  digitalWrite(PIN_OUT_LED, HIGH);

  /*
  **  get the config from the EEPROM
  */
  config_init();

  /*
  ** configure the buttons
  */
  button_init(3);
  button_add(PIN_IN_BTNMODE);
  button_add(PIN_IN_BTNOK);
#if FEATURE_SCREENSHOT
  button_add(PIN_IN_SCREENSHOT);
#endif

  /*
  ** initialize the display
  */
  display_init();
  display_set_content(TITLE);
  display_flush();

  /*
  ** configure the trigger
  */
  trigger_init(PIN_IN_TRIGGER);

  /*
     almost done with init ...
  */
  delay(2000);
  display_flush();
  digitalWrite(PIN_OUT_LED, LOW);
}

/*
**  wait for user input
*/
void loop()
{
  switch ((_mode < 0) ? 0 : button_wait()) {
    case 0:
      /*
         MENU button select the mode
      */
      DbgMsg("button MENU pressed");
      display_clear();
      if (++_mode < 0 || !_main_menu[_mode].title)
        _mode = 0;
      display_set_header("MENU");
      display_set_page(_mode + 1, sizeof(_main_menu) / sizeof(MAIN_MENU) - 1);
      display_set_content(_main_menu[_mode].title);
      display_menu("NEXT", "OK");
      break;
    case 1:
      /*
         OK button starts the function
      */
      DbgMsg("button OK pressed");
      if (_main_menu[_mode].func) {
        display_set_header(_main_menu[_mode].title);
        (*_main_menu[_mode].func)();
      }

      /*
         jump back to the beginning of the menu
      */
      _mode = -1;
  }
}/**/
