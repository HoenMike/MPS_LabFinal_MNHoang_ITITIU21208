/*
 * fms_man.c
 *
 *  Created on: May 28, 2024
 *      Author: hoang
 */

#include "fsm_man.h"
#include "global.h"

void fsm_man_run()
{
  if (is_button_pressed(0)) // RESET BUTTON
  {
    LED_status = INIT;
  }
  if (is_button_pressed(1)) // INCREASE BUTTON
  {
    LED_status++;
  }
  if (is_button_pressed(2)) // DECREASE BUTTON
  {
    LED_status--;
  }
}
