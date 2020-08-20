/*
    LatencyMeasure

    (c) 2020 Christian.Lorenz@gromeck.de

    module to test the timing ot the sensor by use of a reference LED


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
#include "test-timing.h"

void test_timing(void)
{
  do {
    display_set_content("Place sensor over\ntest LED");
    display_menu("MENU", "OK");
    display_flush();
  
    if (button_wait() == 0)
      return;
  
    display_set_footer(NULL);
    display_flush();
  
    int total_failed = 0;
  
    for (int pass = 0; pass < 10; pass++) {
      int wait = 1 << pass;
      int latency = wait;
      bool failed = false;
  
      DbgMsg("wait=%d", wait);
      DbgMsg("latency=%d", latency);
  
      display_set_content("Pass #%d\nLatency: %dms", pass + 1, wait);
      display_set_footer(NULL);
      display_flush();
  
      /*
         do the calibration itself by setting the pin of the test LED to high
      */
      trigger_reset();
      delay(wait);
      digitalWrite(PIN_OUT_LED, HIGH);
      latency = trigger_wait(TEST_TIME);
      digitalWrite(PIN_OUT_LED, LOW);
  
      /*
         show the result
      */
      if (latency) {
        failed = (abs(latency - wait) > MAX_DEVIATION);
        display_set_footer("Measure: %dms %s", latency, (failed) ? " FAILED" : "");
      }
      else {
        failed++;
        display_set_footer("Measure: TIMEOUT");
      }
      total_failed += failed;
      display_flush();
  
      delay(1000);
    }
  
    /*
       present the overall result
    */
    display_set_content("TIMING TEST %s", (total_failed) ? "FAILED" : "SUCCEED");
    display_menu("MENU", "REPEAT");
    display_flush();
  } while (button_wait() == 1);
}/**/
