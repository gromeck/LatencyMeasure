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

#if FEATURE_TEST_TIMING

void test_timing(void)
{
  do {
    display_set_content("Place sensor over\ntest LED");
    display_menu("MENU", "OK");

    if (button_wait() == 0)
      return;

    display_set_footer(NULL);
    display_flush();

    int total_failed = 0;

    for (int pass = 0; pass < TEST_PASSES; pass++) {
      int simulated_latency = 1 << pass;
      int measured_latency;
      bool failed = true;
      char msg[CHARS_PER_LINE + 1];

      sprintf(msg, "Simulated: %dms\n", simulated_latency);
      display_set_page(pass + 1, TEST_PASSES);
      display_set_content(msg);
      display_flush();

      /*
         do the calibration itself by setting the pin of the test LED to high
      */
      if (trigger_ready()) {
        /*
         * the device is ready (currently dark)
         */
        trigger_reset();
        delay(simulated_latency);
        digitalWrite(PIN_OUT_LED, HIGH);
        measured_latency = trigger_wait(TEST_TIME);
        digitalWrite(PIN_OUT_LED, LOW);
  
        /*
           show the result
        */
        if (measured_latency) {
          failed = (abs(measured_latency - simulated_latency) > MAX_DEVIATION);
          display_set_content("%sMeasured : %dms%s", msg, measured_latency, (failed) ? " FAIL" : "");
        }
        else {
          display_set_content("%sMeasured : TIMEOUT", msg);
        }
      }
      else {
        /*
         * the device is not ready (currently bright)
         */
         failed = true;
         display_set_content("%sDEVICE NOT READY", msg);
      }
      if (failed)
        total_failed++;
      display_flush();

      delay(1000);
    }

    /*
       present the overall result
    */
    display_set_content("TIMING TEST %s", (total_failed) ? "FAILED" : "SUCCEED");
    display_menu("MENU", "REPEAT");
  } while (button_wait() == 1);
}

#endif

/**/
