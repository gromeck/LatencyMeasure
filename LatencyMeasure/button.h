/*
    LatencyMeasure

    (c) 2020 Christian.Lorenz@gromeck.de

    button defintions and prototypes
*/
#ifndef __BUTTON_H__
#define __BUTTON_H__ 1

#include "common.h"

/*
**	return codes for the button
*/
#define BUTTON_WAIT4UP           -1
#define BUTTON_DOWN               1
#define BUTTON_UP                 0

/*
   if this is set, we will directly act on a long pressed
   button when the time for that is reached;
   otherwise the long pressed event will be raised on
   releasing of the button
*/
#define BUTTON_PRESSED_LONG_DIRECT  1

/*
    time to detect a long pressed button in milliseconds
*/
#define BUTTON_TIME_SHORT         5
#define BUTTON_TIME_LONG          3000

/*
   defines to switch the button LED
   these are passed as the two last parameters to button_led()
*/
#define BUTTON_LED_OFF            0,0
#define BUTTON_LED_ON_SHORT       (MSEC_PER_SEC / 4),0
#define BUTTON_LED_ON_LONG        MSEC_PER_SEC,0
#define BUTTON_LED_BLINK_FAST     (MSEC_PER_SEC / 4),1
#define BUTTON_LED_BLINK_SLOW     MSEC_PER_SEC,1

/*
**	return the state of the button
*/
void button_init(int buttons);
int button_add(int btn_pin, int led_pin);
void button_led(int btnr, unsigned int length, unsigned int blinkrate);
int button_state(bool *pressed_long);
int button_wait(void);

#endif

/**/
