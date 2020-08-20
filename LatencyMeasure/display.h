/*
    LatencyMeasure

    (c) 2020 Christian.Lorenz@gromeck.de

    display definitions and prototypes
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

void display_menu(const char *opt1, const char *opt2);

void display_flush(void);

#endif

/**/
