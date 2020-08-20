/*
  LatencyMeasure
  
  (c) 2020 Christian.Lorenz@gromeck.de
  
  module to handle the measurement
  
  
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
#include "measurement.h"

/*
   do the measurement itself and return the result
*/
void measurement_measure(void)
{
  do {
    int latency_min = MAX_LATENCY;
    int latency_max = 0;
    long latency_total = 0;
    int latency_count = 0;

    display_set_content("Start test client and\nsetup sensor");
    display_menu("MENU", "OK");
    if (button_wait() == 0)
      return;

    /*
       init the HID device
    */
    if (_config.hid_device == MOUSE)
      Mouse.begin();
    else
      Keyboard.begin();

    /*
       clear the footer when we are doing a series
    */
    display_set_footer(NULL);

    /*
       loop over the measure series
    */
    for (int pass = 0; pass < _config.measure_series && button_state(NULL) < 0; pass++) {
      char msg[20];
      unsigned long latency;

      sprintf(msg, "HID event %d/%d", pass + 1, _config.measure_series);
      display_set_content("%s\nwaiting ...", msg);
      display_flush();

      /*
         start the timer at pressing the button/key
      */
      if (_config.timer_starts_at == KEY_PRESSED)
        trigger_reset();

      /*
         send the event via USB
      */
      if (_config.hid_device == MOUSE)
        Mouse.press(_config.hid_mouse_button);
      else
        Keyboard.press(_config.hid_keyboard_key);

      /*
         reset the trigger timer
      */
      delay(HID_STROKE_TIME);

      /*
         start the timer at releasing the button/key
      */
      if (_config.timer_starts_at != KEY_PRESSED)
        trigger_reset();

      /*
         send the event via USB
      */
      if (_config.hid_device == MOUSE)
        Mouse.release(_config.hid_mouse_button);
      else
        Keyboard.release(_config.hid_keyboard_key);

      /*
         get the time until the sensor detected the reaction on the event
      */
      latency = trigger_wait(MAX_LATENCY);

      /*
         check the result
      */
      if (latency) {
        latency_total += latency;
        latency_count++;
        if (latency > latency_max)
          latency_max = latency;
        if (latency < latency_min)
          latency_min = latency;
        display_set_content("%s\nLatency: %dms", msg, latency);
      }
      else
        display_set_content("%s\nTIMEOUT", msg);
      display_flush();

      /*
         wait the configured time
      */
      if (_config.measure_series > 1)
        delay(_config.measure_pause);
    }

    /*
       init the HID device
    */
    if (_config.hid_device == MOUSE)
      Mouse.end();
    else
      Keyboard.end();

    /*
       display the result
    */
    if (_config.measure_series > 1) {
      display_set_content("ok/total min/avg/max\n%d/%d %d/%ld/%dms",
                          latency_count, _config.measure_series,
                          latency_min, (latency_count) ? latency_total / latency_count : -1, latency_max);
    }

    display_menu("MENU", "REPEAT");
  } while (button_wait() == 1);
}/**/
