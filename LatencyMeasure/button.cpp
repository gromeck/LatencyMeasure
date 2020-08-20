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
  short pin_led;
  short state;
  unsigned long millis;
  unsigned long led_next;
  unsigned int led_blinkrate;
} BUTTON;

#define __STATIC  0

#if __STATIC
static BUTTON *_button[__STATIC];
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
int button_add(int pin_btn, int pin_led)
{
  if (pin_btn >= 0)
    pinMode(pin_btn, INPUT_PULLUP);
  if (pin_led >= 0)
    pinMode(pin_led, OUTPUT);

  _button[_buttons].pin_btn = pin_btn;
  _button[_buttons].pin_led = pin_led;
  _button[_buttons].state = (digitalRead(pin_btn)) ? BUTTON_UP : BUTTON_DOWN;

  return _buttons++;
}

/*
    switch the led of a button
*/
void button_led(int btnr, unsigned int length, unsigned int blink)
{
  BUTTON *button = &_button[btnr];

  if (button->pin_led >= 0) {
    if (length) {
      digitalWrite(button->pin_led, HIGH);
      button->led_next = millis() + length;
      button->led_blinkrate = (blink) ? length : 0;
    }
    else {
      digitalWrite(button->pin_led, LOW);
      button->led_next = 0;
      button->led_blinkrate = 0;
    }
  }
}

/*
**	return the state of the button
*/
int button_state(bool *pressed_long)
{
  int nr = 0;

  for (BUTTON *button = _button; nr < _buttons; button++, nr++) {
    //DbgMsg("checking button #%d",nr);
    if (button->led_next && millis() >= button->led_next) {
      /*
         switch off the LED or let it blink
      */
      if (button->led_blinkrate && button->pin_led >= 0) {
        digitalWrite(button->pin_led, (digitalRead(button->pin_led) == HIGH) ? LOW : HIGH);
        button->led_next = millis() + button->led_blinkrate;
      }
      else
        button_led(nr, BUTTON_LED_OFF);
    }
    if (button->state == BUTTON_UP && digitalRead(button->pin_btn) == LOW) {
      /*
         button pressed
      */
      DbgMsg("button #%d pressed", nr);
      if (button->pin_led >= 0)
        digitalWrite(button->pin_led, HIGH);
      button->state = BUTTON_DOWN;
      button->millis = millis();
    }
    else if (button->state == BUTTON_WAIT4UP && digitalRead(button->pin_btn) == HIGH) {
      /*
         button was released
      */
      DbgMsg("button #%d released (we're waiting for)", nr);
      if (button->pin_led >= 0)
        digitalWrite(button->pin_led, LOW);
      button->state = BUTTON_UP;
    }
    else if (button->state == BUTTON_DOWN && digitalRead(button->pin_btn) == LOW && digitalRead(button->pin_led) == HIGH && millis() - button->millis > BUTTON_TIME_LONG) {
      /*
         switch of the LED to give the user a feedback
      */
      DbgMsg("button #%d still pressed -- LED off", nr);
      if (button->pin_led >= 0)
        digitalWrite(button->pin_led, LOW);
#if BUTTON_PRESSED_LONG_DIRECT
      /*
         long button event
      */
      DbgMsg("button #%d event: pressed long", nr);
      button->state = BUTTON_WAIT4UP;
      //sound_single(SOUND_SINGLE_BUTTON);
      if (pressed_long)
        *pressed_long = true;
      return nr;
#endif
    }
    else if (button->state == BUTTON_DOWN && digitalRead(button->pin_btn) == HIGH) {
      /*
         button released
      */
      DbgMsg("button #%d released", nr);
      if (button->pin_led >= 0)
        digitalWrite(button->pin_led, LOW);
      button->state = BUTTON_UP;
      if (millis() - button->millis > BUTTON_TIME_LONG) {
        /*
           long button event
        */
#if !BUTTON_PRESSED_LONG_DIRECT
        DbgMsg("button #%d event: pressed long", nr);
        //sound_single(SOUND_SINGLE_BUTTON);
        return BUTTON_PRESSED_LONG | nr;
#endif
      }
      else if (millis() - button->millis > BUTTON_TIME_SHORT) {
        /*
           short button event
        */
        DbgMsg("button #%d event: short", nr);
        //sound_single(SOUND_SINGLE_BUTTON);
        if (pressed_long)
          *pressed_long = false;
        return nr;
      }
      else {
        /*
           button pressed too short -- ignore
        */
        DbgMsg("button #%d event: too short (%ldms) -- ignoring", nr, millis() - button->millis);
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
