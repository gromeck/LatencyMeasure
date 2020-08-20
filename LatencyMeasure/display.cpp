/*
    LatencyMeasure

    (c) 2020 Christian.Lorenz@gromeck.de

    module to handle the display
*/
#include "display.h"

static Adafruit_SSD1306 _display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

static char _header[CHARS_PER_LINE + 1];
static char _content[CHARS_PER_LINE * 2 + 1];
static char _footer[CHARS_PER_LINE + 1];

void display_init(void)
{
  // Address 0x3C for 128x32
  if (!_display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    LogMsg("OLED SSD1306 allocation failed -- aborting");
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

void display_menu(const char *opt1, const char *opt2)
{
  display_set_footer("%c %s   %c %s",
                     (opt1) ? DISPLAY_ARROW_DOWN : ' ',
                     (opt1) ? opt1 : "",
                     (opt2) ? DISPLAY_ARROW_RIGHT : ' ',
                     (opt2) ? opt2 : "");
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
