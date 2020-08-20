/*
  LatencyMeasure
  
  (c) 2020 Christian.Lorenz@gromeck.de
  
  button defintions and prototypes
  
  
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
**	return the state of the button
*/
void button_init(int buttons);
int button_add(int btn_pin);
int button_state(bool *pressed_long);
int button_wait(void);

#endif

/**/
