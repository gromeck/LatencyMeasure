/*
  LatencyMeasure

  (c) 2020 Christian.Lorenz@gromeck.de

  module to handle buttons


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
#include "button.h"

typedef struct _button {
  short pin_btn;
  short state;
  unsigned long timestamp;
} BUTTON;

#define __STATIC  3

#if __STATIC
static BUTTON _button[__STATIC];
#else
static BUTTON *_button = NULL;
#endif
static int _buttons = 0;

/*
   init the buttons
*/
void button_init(int buttons)
{
  DbgMsg("%s: __STATIC=%d  buttons=%d  sizeof(BUTTON)=%d", __func__, __STATIC, buttons, sizeof(BUTTON));
#if __STATIC == 0
  _button = (BUTTON *) calloc(sizeof(BUTTON), buttons);
#endif
  _buttons = 0;
  DbgMsg("%s: button=%p", __func__, _button);
}

/*

*/
int button_add(int pin_btn)
{
  if (pin_btn >= 0)
    pinMode(pin_btn, INPUT_PULLUP);

  _button[_buttons].pin_btn = pin_btn;
  _button[_buttons].state = (digitalRead(pin_btn)) ? BUTTON_UP : BUTTON_DOWN;
  _button[_buttons].timestamp = 0;

  return _buttons++;
}

/*
**	return the state of the button
*/
int button_state(bool *pressed_long)
{
  int nr = 0;

  for (BUTTON *button = _button; nr < _buttons; button++, nr++) {
    int pin = digitalRead(button->pin_btn);
    unsigned long delta = millis() - button->timestamp;

    //DbgMsg("checking button #%d, pin=%d",nr,pin);

    if (button->state == BUTTON_UP && pin == LOW) {
      /*
         button pressed
      */
      DbgMsg("button #%d pressed", nr);
      button->state = BUTTON_DOWN;
      button->timestamp = millis();
    }
#if BUTTON_PRESSED_LONG_DIRECT
    else if (button->state == BUTTON_DOWN && pin == LOW && delta > BUTTON_TIME_LONG) {
      /*
         long button event
      */
      DbgMsg("button #%d event: pressed long", nr);
      button->state = BUTTON_WAIT4UP;
      if (pressed_long)
        *pressed_long = true;
      return nr;
    }
    else if (button->state == BUTTON_WAIT4UP && pin == HIGH) {
      /*
         button was released
      */
      DbgMsg("button #%d released (we're waiting for)", nr);
      button->state = BUTTON_UP;
    }
#endif
    else if (button->state == BUTTON_DOWN && pin == HIGH) {
      /*
         button released
      */
      DbgMsg("button #%d released", nr);
      button->state = BUTTON_UP;

      if (delta < BUTTON_TIME_SHORT) {
        /*
           button pressed too short -- ignore
        */
        DbgMsg("button #%d event: too short (%lums) -- ignoring", nr, delta);
      }
      else {
        /*
           button event (long or short)
        */
        DbgMsg("button #%d event: pressed %lums", nr, delta);
        if (pressed_long) {
          *pressed_long = (delta > BUTTON_TIME_LONG) ? true : false;
        }

#if DEBUG
        {
          /*
             dump the button struct
          */
          int nr = 0;

          DbgMsg("dumping buttons");
          for (BUTTON *button = _button; nr < _buttons; button++, nr++) {
            DbgMsg("button[%d] pin_btn=%d  state=%d  timestamp=%lums", nr, button->pin_btn, button->state, button->timestamp);
          }
        }
#endif

#if FEATURE_SCREENSHOT
        if (button->pin_btn == PIN_IN_SCREENSHOT) {
          /*
             dump the display & forget about this key event
          */
          display_dump_bitmap();
        }
        else
#endif
          return nr;
      }
    }
  }
  return -1;
}

/*
   wait for any button and return it
*/
int button_wait(void)
{
  int btn;

  while ((btn = button_state(NULL)) < 0)
    ;

  return btn;
}/**/
