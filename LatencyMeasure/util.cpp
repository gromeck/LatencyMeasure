/*
    LatencyMeasure

    (c) 2020 Christian.Lorenz@gromeck.de

    module to implement some support functions
*/
#include "util.h"

/*
**  log a smessage to serial
*/
void LogMsg(const char *fmt, ...)
{
#if DBG
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
#endif
}/**/
