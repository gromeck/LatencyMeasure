/*
  LatencyMeasure
  
  (c) 2020 Christian.Lorenz@gromeck.de
  
  module to handle the sensor detection in an interrupt service routine
  
  
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
#include "trigger.h"

static volatile unsigned long _trigger_start = 0;
static volatile unsigned long _trigger_time = 0;

/*
   interrupt service routine for our trigger

   we only register the first call
*/
static void _trigger_isr(void)
{
  if (!_trigger_time)
    _trigger_time = millis() - _trigger_start;
}

/*
   initialize the trigger by attaching the ISR
*/
void trigger_init(int pin)
{
  pinMode(pin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pin), _trigger_isr, FALLING);
}

/*
   reset the trigger time
*/
void trigger_reset(void)
{
  _trigger_time = 0;
  _trigger_start = millis();
}

/*
   wait for a given time for the trigger event
*/
unsigned long trigger_wait(int timetowait)
{
  unsigned long waittostop = millis() + timetowait;

  while (millis() < waittostop && !_trigger_time)
    delay(10);
  return _trigger_time;
}

/*
   return the time between the reset and the trigger event
*/
unsigned long trigger_time(void)
{
  return _trigger_time;
}/**/
