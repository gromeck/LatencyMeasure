/*
  LatencyMeasure

  (c) 2020 Christian.Lorenz@gromeck.de

  module to show some system info


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
#include "device-info.h"

#if FEATURE_DEVICE_INFO

#ifdef USB_PRODUCT
#define DEVICE_TYPE  USB_PRODUCT
#else
#define DEVICE_TYPE  "<unknown>"
#endif

void device_info(void)
{
  int item = 0;

  display_menu("NEXT", "EXIT");

  while (item >= 0) {
    /*
       wrap the config menu
    */
    switch (item) {
      case 0:
        display_set_content("SW-Version:\n" __DATE__ " " __TIME__);
        break;
      case 1:
        display_set_content("Device:\n" DEVICE_TYPE);
        break;
      case 2:
        display_set_content("Visit " GITHUB_URL);
        break;
      default:
        item = -1;
    }
    if (item >= 0) {
      display_flush();
      if (button_wait() == 1)
        break;
    }
    ++item;
  }
}

#endif

/**/
