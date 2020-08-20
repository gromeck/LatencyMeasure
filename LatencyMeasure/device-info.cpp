/*
    LatencyMeasure

    (c) 2020 Christian.Lorenz@gromeck.de

    module to show some system info
*/
#include "device-info.h"

#ifdef USB_PRODUCT
#define DEVICE_TYPE  USB_PRODUCT
#else
#define DEVICE_TYPE  "<unknown>"
#endif

void device_info(void)
{
  int item = 0;

  display_menu("NEXT", "EXIT");
  display_flush();

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
}/**/
