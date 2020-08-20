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
  { "Configure", config_menu },
  { "Test Timing", test_timing },
  { "Calibrate Sensor", calibrate_sensor },
  { "Device Info", device_info },
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
  delay(1000);
  Serial.begin(115000);
  DbgMsg(TITLE ": starting up");

  /*
  **  get the config from the EEPROM
  */
  config_init();

  /*
  ** initialize the display
  */
  display_init();
  display_set_content("\007 Latency Measure \007");
  display_flush();

  /*
  ** configure the buttons
  */
  button_init(2);
  button_add(PIN_IN_BTNMODE, -1);
  button_add(PIN_IN_BTNOK, -1);

  /*
  ** configure the trigger
  */
  trigger_init(PIN_IN_TRIGGER);

  /*
  ** configure other IO pins
  */
  pinMode(PIN_OUT_LED, OUTPUT);
  analogReference(INTERNAL);

  delay(2000);
  display_flush();
}

/*
**  continous loop
*/
void loop()
{
  /*
     switch the modes
  */
  switch ((_mode < 0) ? 0 : button_wait()) {
    case 0:
      /*
         MENU button select the mode
      */
      DbgMsg("button MENU pressed");
      display_clear();
      if (++_mode < 0 || !_main_menu[_mode].title)
        _mode = 0;
      display_set_header("Menu");
      display_set_content(_main_menu[_mode].title);
      display_menu("NEXT", "OK");
      display_flush();
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
