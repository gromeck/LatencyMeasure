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

// the git version is coming from make-git-version
#include "git-version.h"

static const char *_device_info[] = {
    //"Device: " DEVICE_TYPE,
    "SW-Version: " GIT_VERSION,
    "Visit " GITHUB_URL
};
#define DEVICE_INFO_ITEMS   (sizeof(_device_info) / sizeof(char *))

void device_info(void)
{
  bool done = false;

  display_menu("NEXT", "EXIT");

  do {
    for (int item = 0;item < DEVICE_INFO_ITEMS && !done;item++) {
      display_set_page(item + 1,DEVICE_INFO_ITEMS);
      display_set_content(_device_info[item]);
      display_flush();
      done = (button_wait() == 1);
    }
  } while (!done);
}

#endif

/**/
