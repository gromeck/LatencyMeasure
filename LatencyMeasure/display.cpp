/*
  LatencyMeasure
  
  (c) 2020 Christian.Lorenz@gromeck.de
  
  module to handle the display
  
  
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
#include "display.h"

static Adafruit_SSD1306 _display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

static char _header[CHARS_PER_LINE + 1];
static char _content[CHARS_PER_LINE * 2 + 1];
static char _footer[CHARS_PER_LINE + 1];

/*
 * init the OLED display
 */
void display_init(void)
{
  // Address 0x3C for 128x32
  if (!_display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    DbgMsg("OLED SSD1306 allocation failed -- halting");
    for (;;);
  }

#if 0
  /*
     show a character map
  */
  for (;;) {
    _display.setTextSize(1);
    _display.setTextColor(SSD1306_WHITE);

    _display.clearDisplay();
    _display.setCursor(0, 0);
    for (int16_t c = 0; c < 64; c++) {
      _display.write((c == '\n') ? ' ' : c);
      _display.write(' ');
    }
    _display.display();
    delay(2 * 1000);

    _display.clearDisplay();
    _display.setCursor(0, 0);

    _display.write(DISPLAY_ARROW_LEFT);
    _display.write(DISPLAY_ARROW_RIGHT);
    _display.write(DISPLAY_ARROW_UP);
    _display.write(DISPLAY_ARROW_DOWN);

    _display.display();
    delay(2 * 1000);
  }
#endif

  display_clear();
  display_flush();
}

void display_clear(void)
{
  _header[0] = '\0';
  _content[0] = '\0';
  _footer[0] = '\0';
}

static char *setup_text(char *buffer, int maxlen, const char *fmt, va_list args)
{
  vsnprintf(buffer, maxlen - 1, fmt, args);
  buffer[maxlen - 1] = '\0';
  va_end(args);
}

void display_set_header(const char *fmt, ...)
{
  va_list args;

  if (fmt) {
    va_start(args, fmt);
    setup_text(_header, sizeof(_header), fmt, args);
  }
  else
    _header[0] = '\0';
}

void display_set_content(const char *fmt, ...)
{
  va_list args;

  if (fmt) {
    va_start(args, fmt);
    setup_text(_content, sizeof(_content), fmt, args);
  }
  else
    _content[0] = '\0';
}

void display_set_footer(const char *fmt, ...)
{
  va_list args;

  if (fmt) {
    va_start(args, fmt);
    setup_text(_footer, sizeof(_footer), fmt, args);
  }
  else
    _footer[0] = '\0';
}

void display_flush(void)
{
  _display.clearDisplay();

  /*
     header
  */
  if (_header[0]) {
    _display.fillRect(0, 0, SCREEN_WIDTH, CHAR_HEIGHT, SSD1306_WHITE);
    _display.setTextSize(1);
    _display.setTextColor(SSD1306_BLACK);
    _display.setCursor(1,0);
    _display.print("\007 ");
    _display.print(_header);
  }

  /*
     content

     NOTE: text without linebreaks is centered
  */
  if (_content[0]) {
    _display.setTextSize(1);
    if (strchr(_content,'\n') || strlen(_content) >= CHARS_PER_LINE)
      _display.setCursor(0, 1 * CHAR_HEIGHT);
    else
      _display.setCursor((SCREEN_WIDTH - strlen(_content) * CHAR_WIDTH) / 2,1 * CHAR_HEIGHT + CHAR_HEIGHT / 2);
    _display.setTextColor(SSD1306_WHITE);
    _display.print(_content);
  }

  /*
     footer
  */
  if (_footer[0]) {
    _display.setTextSize(1);
    _display.setTextColor(SSD1306_WHITE);
    _display.setCursor(0, 3 * CHAR_HEIGHT);
    _display.println(_footer);
  }

  _display.display();
}

/*
 * print the menu & flush
 */
void display_menu(const char *opt1, const char *opt2)
{
  display_set_footer("%c %s   %c %s",
                     (opt1) ? DISPLAY_ARROW_DOWN : ' ',
                     (opt1) ? opt1 : "",
                     (opt2) ? DISPLAY_ARROW_RIGHT : ' ',
                     (opt2) ? opt2 : "");
  display_flush();
}

#if FEATURE_SCREENSHOT
/*
 * dump the display a a PNM bitmap (P1)
 */
void display_dump_bitmap(void)
{
#if !DEBUG
  // in debug mode we will use the serial interface anyway
  Serial.begin(SERIAL_BAUDRATE);
#endif

  /*
   * write the header
   */
  Serial.println("P1");
  Serial.print(SCREEN_WIDTH);
  Serial.print(" ");
  Serial.println(SCREEN_HEIGHT);
  for (int y = 0;y < SCREEN_HEIGHT;y++) {
    for (int x = 0;x < SCREEN_WIDTH;x++) {
      Serial.print(_display.getPixel(x,y) ? 0 : 1);
      Serial.print(" ");
    }
    Serial.println();
  }
  Serial.println("#");

#if !DEBUG
  // in debug mode we will use the serial interface anyway
  Serial.end();
#endif
}

#endif

/**/
