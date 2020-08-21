/*
  LatencyMeasure
  
  (c) 2020 Christian.Lorenz@gromeck.de
  
  display definitions and prototypes
  
  
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
#ifndef __DISPLAY_H__
#define __DISPLAY_H__ 1

#include "common.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

/*
** screen dimensions
*/
#define SCREEN_WIDTH    128
#define SCREEN_HEIGHT   32
#define CHAR_HEIGHT     8
#define CHAR_WIDTH      6
#define CHARS_PER_LINE  (SCREEN_WIDTH / CHAR_WIDTH)

/*
   some definition for graphical symbols
*/
#if 0
/*
   thick arrow set
*/
#define DISPLAY_ARROW_RIGHT   0x10
#define DISPLAY_ARROW_LEFT    0x11
#define DISPLAY_ARROW_UP      0x1e
#define DISPLAY_ARROW_DOWN    0x1f
#else
/*
   thin arrow set
*/
#define DISPLAY_ARROW_RIGHT   0x1a
#define DISPLAY_ARROW_LEFT    0x1b
#define DISPLAY_ARROW_UP      0x18
#define DISPLAY_ARROW_DOWN    0x19
#endif

#define DISPLAY_MIDDOT        0x07


void display_init(void);

void display_clear(void);
void display_set_header(const char *fmt, ...);
void display_set_content(const char *fmt, ...);
void display_set_footer(const char *fmt, ...);

void display_message(int wait, const char *fmt, ...);

void display_flush(void);

void display_menu(const char *opt1, const char *opt2);

#if FEATURE_SCREENSHOT
void display_dump_bitmap(void);
#endif

#endif

/**/
