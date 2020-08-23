/*
  LatencyMeasure

  (c) 2020 Christian.Lorenz@gromeck.de

  module to handle the configuration


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
#include "config.h"

CONFIG _config;

#if FEATURE_CONFIG_MENU

typedef struct {
  const char *_name;
  const int value;
} CONFIG_OPTIONS;

typedef struct {
  const char *_name;
  int *confref;
  CONFIG_OPTIONS options[5];
} CONFIG_MENU;

static CONFIG_MENU _config_menu[] = {
  {
    "Series of Measure",
    &_config.measure_series,
    {
      { "1 (single)", 1 },
      { "10", 10 },
      { "25", 25 },
      { "50", 50 },
      { NULL, 0 }
    }
  },
  {
    "Measure Pause",
    &_config.measure_pause,
    {
      { "500ms", 500 },
      { "1s", 1 * 1000 },
      { "5s", 5 * 1000 },
      { "10s", 10 * 1000 },
      { NULL, 0 }
    }
  },
  {
    "HID Device Type",
    &_config.hid_device,
    {
      { "Mouse", 0 },
      { "Keyboard", 1 },
      { NULL, 0 }
    }
  },
  {
    "HID Mouse Button",
    &_config.hid_mouse_button,
    {
      { "left", MOUSE_LEFT },
      { "middle", MOUSE_MIDDLE },
      { "right", MOUSE_RIGHT },
      { NULL, 0 }
    }
  },
  {
    "HID Keyboard Key",
    &_config.hid_keyboard_key,
    {
      { "<SPACE>", ' ' },
      { "<RETURN>", KEY_RETURN },
      { "<F10>", KEY_F10 },
      { NULL, 0 }
    }
  },
  {
    "Timer start at ...",
    &_config.timer_starts_at,
    {
      { "pressed Key/Btn", KEY_PRESSED },
      { "released Key/Btn", KEY_RELEASED },
      { NULL, 0 }
    }
  },
  {
    "Exit Config\n", NULL
  },
  {
    NULL, NULL
  }
};

#endif

/*
   read the configuration from the EEPROM
*/
static bool config_read(void)
{
  byte *config = (byte *) &_config;

  for (int offset = 0; offset < sizeof(_config); offset++)
    config[offset] = EEPROM.read(EEPROM_START_ADDR + offset);
}

/*
   write the configuration to the EEPROM
*/
static bool config_write(void)
{
  byte *config = (byte *) &_config;

  for (int offset = 0; offset < sizeof(_config); offset++)
    EEPROM.write(EEPROM_START_ADDR + offset, config[offset]);
}

/*
   init the configuration by reading it from the EEPROM
*/
void config_init(void)
{
  config_read();
}

#if FEATURE_CONFIG_MENU
/*
    configuration menu
*/
void config_menu(void)
{
  int item = 0;

  while (item >= 0) {
    /*
       wrap the config menu
    */
    if (!_config_menu[item]._name)
      item = 0;
    CONFIG_MENU *cm = &_config_menu[item];
    int option_idx;

    /*
       display the current menu entry and its value
    */
    if (cm->confref) {
      const char *option_name = NULL;
      int value = *cm->confref;

      for (option_idx = 0; cm->options[option_idx]._name; option_idx++) {
        if (value == cm->options[option_idx].value) {
          option_name = cm->options[option_idx]._name;
          break;
        }
      }
      if (!option_name) {
        option_idx = -1;
        option_name = "<UNKNOWN>";
      }
      display_set_content("%s\n  %c %s", cm->_name, DISPLAY_ARROW_RIGHT, option_name);
    }
    else {
      option_idx = -1;
      display_set_content("%s", cm->_name);
    }
    display_set_page(item + 1, sizeof(_config_menu) / sizeof(CONFIG_MENU) - 1);
    display_menu("NEXT", (cm->confref) ? "CHANGE" : "EXIT");

    /*
       react on buttons
    */
    switch (button_wait()) {
      case 0:
        /*
        ** MENU pressed: goto next item
        */
        item++;
        break;
      case 1:
        /*
        ** OK pressed: select the configuration options
        */
        if (!cm->confref) {
          /*
             escape the config
          */
          item = -1;
        }
        else {
          /*
          ** get the next config option for the current item
          */
          if (!cm->options[++option_idx]._name)
            option_idx = 0;

          /*
          ** now switch the config value to the new selected one
          */
          *cm->confref = cm->options[option_idx].value;
        }
        break;
    }
  }

  /*
     we might have changed the configuration, so
     write the configuration back to the EEPROM
  */
  config_write();
}

#endif

/**/
