/*
  LatencyMeasure
  
  (c) 2020 Christian.Lorenz@gromeck.de
  
  module to implement some support functions
  
  
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
#include "util.h"

#if DBG

/*
**  log a smessage to serial
*/
void DbgMsg(const char *fmt, ...)
{
  va_list args;
  char msg[128];
  unsigned long now = millis();

  if (Serial) {
    va_start(args, fmt);
    vsnprintf(msg, 128, fmt, args);
    va_end(args);

    Serial.print(now);
    Serial.print(": ");
    Serial.println(msg);
    Serial.flush();
  }
}

#endif

/**/
