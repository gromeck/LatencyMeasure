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
  unsigned int millis;
} BUTTON;

#define __STATIC  0

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

  return _buttons++;
}

/*
**	return the state of the button
*/
int button_state(bool *pressed_long)
{
  int nr = 0;

  for (BUTTON *button = _button; nr < _buttons; button++, nr++) {
    //DbgMsg("checking button #%d",nr);
    int pin = digitalRead(button->pin_btn);
    
    if (button->state == BUTTON_UP && pin == LOW) {
      /*
         button pressed
      */
      DbgMsg("button #%d pressed", nr);
      button->state = BUTTON_DOWN;
      button->millis = millis();
    }
#if BUTTON_PRESSED_LONG_DIRECT
    else if (button->state == BUTTON_WAIT4UP && pin == HIGH) {
      /*
         button was released
      */
      DbgMsg("button #%d released (we're waiting for)", nr);
      button->state = BUTTON_UP;
    }
    else if (button->state == BUTTON_DOWN && pin == LOW && millis() - button->millis > BUTTON_TIME_LONG) {
      /*
         long button event
      */
      DbgMsg("button #%d event: pressed long", nr);
      button->state = BUTTON_WAIT4UP;
      if (pressed_long)
        *pressed_long = true;
      return nr;
    }
#endif
    else if (button->state == BUTTON_DOWN && pin == HIGH) {
      /*
         button released
      */
      DbgMsg("button #%d released", nr);
      button->state = BUTTON_UP;

      if (millis() - button->millis < BUTTON_TIME_SHORT) {  
        /*
           button pressed too short -- ignore
        */
        DbgMsg("button #%d event: too short (%ldms) -- ignoring", nr, millis() - button->millis);
      }
      else {
        /*
           button event (long or short)
         */
        if (pressed_long)
          *pressed_long = (millis() - button->millis > BUTTON_TIME_LONG) ? true : false;
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

  do {
    bool pressed_long = false;

    btn = button_state(&pressed_long);

#if SCREENSHOT
    if (btn >= 0 && pressed_long) {
      /*
       * any long pressed button will dump a screenshot
       */
      display_dump_bitmap();
      btn = -1;
    }
#endif

  } while (btn < 0);
  
  return btn;
}/**/
