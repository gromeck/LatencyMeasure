/*
    LatencyMeasure

    (c) 2020 Christian.Lorenz@gromeck.de

    configuration definitions and protoypes


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
#ifndef __CONFIG_H__
#define __CONFIG_H__ 1

#include "common.h"
#include <EEPROM.h>

/*
  some enumarions
*/
enum HID_DEVICE {
  MOUSE = 0,
  KEYBOARD = 1
};

enum TIMER_STARTS_AT {
  KEY_PRESSED = 0,
  KEY_RELEASED = 1
};

/*
   the configuration itself
*/
typedef struct {
  int measure_series;
  int measure_pause;
  int hid_device;
  int hid_mouse_button;
  int hid_keyboard_key;
  int timer_starts_at;
} CONFIG;

extern  CONFIG _config;

/*
   this is the offset in the EEPROM where the configuration is stored
*/
#define EEPROM_START_ADDR   0

/*
**	prototypes
*/
void config_init(void);
void config_menu(void);

#endif

/**/
